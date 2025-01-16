
#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <cstring>
#include <string>

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

void client(int client_socket) 
{
    vector<LabTest> tests;
    tests.emplace_back("T001", 10.15);
    tests.emplace_back("T002", 20.25);
    tests.emplace_back("T003", 30.35);
    tests.emplace_back("T004", 40.45);
    tests.emplace_back("T005", 50.55);

    int size = tests.size();
    double resultsArray[100];

    // Filling the array with Result value data
    for (int i = 0; i < size; ++i) 
    {
        resultsArray[i] = tests[i].getResultValues();
    }

    cout << "Client sending Result Values: ";
    for (int i = 0; i < size; ++i) 
    {
        cout << resultsArray[i] << " ";
    }
    cout << endl;

    // Send data to server
    send(client_socket, &size, sizeof(size), 0);
    send(client_socket, resultsArray, sizeof(double) * size, 0);

    // Receive result from server
    double sum;
    recv(client_socket, &sum, sizeof(sum), 0);
    cout << "Client received sum from server: " << sum << endl;

    close(client_socket);
}

void server(int server_socket) 
{
    double buffer[100];
    int size;
    double sum = 0;

    // Read size and data from client
    recv(server_socket, &size, sizeof(size), 0);
    recv(server_socket, buffer, sizeof(double) * size, 0);

    cout << "Server received Result Values: ";
    for (int i = 0; i < size; ++i) 
    {
        cout << buffer[i] << " ";
        sum += buffer[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    // Send sum back to client
    send(server_socket, &sum, sizeof(sum), 0);

    close(server_socket);
}

int main() 
{
    int sockets[2];
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) == -1) 
    {
        perror("Socket creation failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) 
    {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) 
    { // Child process (Client)
        close(sockets[0]);
        client(sockets[1]);
        exit(0);
    } 
    else 
    { // Parent process (Server)
        close(sockets[1]);
        server(sockets[0]);
        wait(nullptr); // Wait for child process to complete
    }

    return 0;
}
