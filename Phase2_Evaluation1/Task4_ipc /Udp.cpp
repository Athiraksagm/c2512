#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

class LabTest 
{
private:
    string TestId;
    double ResultValues;
public:
    LabTest(string id, double value) : TestId(id), ResultValues(value) {}
    double getResultValues() const { return ResultValues; }
};

void client() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    // Server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    vector<LabTest> tests;
    tests.emplace_back("T001", 10.15);
    tests.emplace_back("T002", 20.25);
    tests.emplace_back("T003", 30.35);
    tests.emplace_back("T004", 40.45);
    tests.emplace_back("T005", 50.55);

    int size = tests.size();
    double resultsArray[100];

    // Filling the array with Result value data
    for (int i = 0; i < size; ++i) {
        resultsArray[i] = tests[i].getResultValues();
    }

    cout << "Client sending Result Values: ";
    for (int i = 0; i < size; ++i) {
        cout << resultsArray[i] << " ";
    }
    cout << endl;

    // Send size and data to server
    sendto(sockfd, &size, sizeof(size), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    sendto(sockfd, resultsArray, sizeof(double) * size, 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));

    // Receive result from server
    double sum;
    socklen_t len = sizeof(server_addr);
    recvfrom(sockfd, &sum, sizeof(sum), 0, (struct sockaddr *)&server_addr, &len);

    cout << "Client received sum from server: " << sum << endl;

    close(sockfd);
}

void server() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    // Server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    double buffer[100];
    int size;
    double sum = 0;

    socklen_t len = sizeof(client_addr);

    // Receive size and data from client
    recvfrom(sockfd, &size, sizeof(size), 0, (struct sockaddr *)&client_addr, &len);
    recvfrom(sockfd, buffer, sizeof(double) * size, 0, (struct sockaddr *)&client_addr, &len);

    cout << "Server received Result Values: ";
    for (int i = 0; i < size; ++i) {
        cout << buffer[i] << " ";
        sum += buffer[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    // Send sum back to client
    sendto(sockfd, &sum, sizeof(sum), 0, (const struct sockaddr *)&client_addr, len);

    close(sockfd);
}

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        sleep(1); 
        client();
        exit(0);
    } else { 
        server();
        wait(nullptr); 
    }

    return 0;
}

