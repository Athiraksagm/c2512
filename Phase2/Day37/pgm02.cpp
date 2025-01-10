#include <iostream>

#include <unistd.h>
#include <cstring>

#include <string>
#include <sstream>

#include <cstdlib>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_CONNS 5

void server(int port);
void serveClient(int&);
void client(std::string server_ip, int port);
void requestServer(int&);

void server(int port) {
    int server_socket_fd;
    // Create socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    sockaddr_in address; //struct sockaddr_in
    
    // Bind socket to port
    address.sin_family = AF_INET;           // ipv4 | AF_INET6
    address.sin_addr.s_addr = INADDR_ANY;   // ip addr is not mandatory | auto ip addr detected
    address.sin_port = htons(port);         // convert port of host byte order to network byte order

    if (bind(server_socket_fd, (sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket_fd, MAX_CONNS) < 0) { 
        perror("Listen failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    // Accept a connection
    int client_socket_fd;
    int addrlen = sizeof(address);
    if ((client_socket_fd = accept(server_socket_fd, (sockaddr*)&address, (socklen_t*)&addrlen)) < 0) { //blocked
        perror("Accept failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    //serve the client
    serveClient(client_socket_fd);

    // Close server socket
    close(server_socket_fd);
}

void serveClient(int& client_socket_fd) {
    char buffer[BUFFER_SIZE];

    long first;
    long second;
    // receive first number
    read(client_socket_fd, buffer, BUFFER_SIZE);
    memcpy((void*)buffer, (void*)&first, sizeof(long));
    // receive second number 
    read(client_socket_fd, buffer, BUFFER_SIZE);
    memcpy((void*)buffer, (void*)&second, sizeof(long));
    // process numbers
    long sum = first + second;

    std::cout << "process:" << first << " + " 
                            << second << " = " 
                            << sum << " done." << std::endl;

    // send response
    memcpy((void*)buffer, (void*)&sum, sizeof(long));
    write(client_socket_fd, buffer, BUFFER_SIZE);
    std::cout << "\tresponse sent to client" << std::endl;

    // release client // Close client socket
    close(client_socket_fd);
}

void client(std::string server_ip, int port) {
    int client_socket_fd = 0;  
    // create socket
    if ((client_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    // specify server address
    sockaddr_in server_address; //struct sockaddr_in
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0) { 
        // convert ip addr of host byte order to network byte order, 
        // and assigning into sin_addr
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(client_socket_fd, (sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // request the server 
    requestServer(client_socket_fd);

    // close client socket
    close(client_socket_fd);
}

void requestServer(int& client_socket_fd) {
    char buffer[BUFFER_SIZE];
    
    long first;
    long second;
    std::cout << "First Number:"; std::cin >> first;
    std::cout << "Second Number:"; std::cin >> second;
    // send numbers
    memcpy((void*)buffer, (void*)&first, sizeof(long));
    write(client_socket_fd, buffer, BUFFER_SIZE);

    memcpy((void*)buffer, (void*)&second, sizeof(long));
    write(client_socket_fd, buffer, BUFFER_SIZE);
    // receive response
   
    read(client_socket_fd, buffer, BUFFER_SIZE);
    //
    long sum{};
    memcpy((void*)&sum, (void*)buffer, sizeof(long));
    std::cout << "So," << first << " + " 
                            << second << " = " 
                            << sum << std::endl;
    std::cout << "I am thankful to my sum calculator server!!!" << std::endl;
}

int main(int argc, char* argv[]) {
    if(argc <= 1) {
        std::cout << "usage:\n\t./sumCalculatorApp.out server 8080" << std::endl;
        std::cout << "\t./sumCalculatorApp.out client 127.0.0.1 8080" << std::endl;
        return EXIT_FAILURE;
    }

    if(!(
       (strcmp(argv[1], "client") == 0 && argc == 4) || 
       (strcmp(argv[1], "server") == 0 && argc == 3)
       )) {
        std::cout << "usage:\n\t./sumCalculatorApp.out server 8080" << std::endl;
        std::cout << "\t./sumCalculatorApp.out client 127.0.0.1 8080" << std::endl;
        return EXIT_FAILURE;
    }

    if(strcmp(argv[1], "client") == 0) {
        std::cout << "Client [to server `" << argv[2] << ":" << argv[3] << "`]" << std::endl;      
        client(argv[2], atoi(argv[3]));  
    }
    if(strcmp(argv[1], "server") == 0) {
        std::cout << "Server [port:`" << argv[2] << "`]" <<std::endl;
        server(atoi(argv[2]));
    }
    
    return EXIT_SUCCESS;
}
