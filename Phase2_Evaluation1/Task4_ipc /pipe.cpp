#include <iostream>
#include <vector>
#include <unistd.h>
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

void client(int write_to_server, int read_from_server) {
    vector<LabTest> tests;
        tests.emplace_back("T001",10.15);
        tests.emplace_back("T002",20.25);
        tests.emplace_back("T003",30.35);
        tests.emplace_back("T004",40.45);
        tests.emplace_back("T005",50.55);
    
    int size = tests.size(); 
    double resultsArray[100];

    // Filling the array with Result value  data
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
    write(write_to_server, &size, sizeof(size));
    write(write_to_server, resultsArray, sizeof(double) * size);

    // Read result from server
    double sum;
    read(read_from_server, &sum, sizeof(sum));
    cout << "Client received sum from server: " << sum << endl;

    close(write_to_server);
    close(read_from_server);
}

void server(int read_from_client, int write_to_client)
{
    double buffer[100];
    int size;
    double sum = 0;

    // Read size and data from client
    read(read_from_client, &size, sizeof(size));
    read(read_from_client, buffer, sizeof(double) * size);

    cout << "Server received Result Values: ";
    for (int i = 0; i < size; ++i)
    {
        cout << buffer[i] << " ";
        sum += buffer[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    // Send sum back to client
    write(write_to_client, &sum, sizeof(sum));

    close(read_from_client);
    close(write_to_client);
}

int main()
{
    int pipe_client_to_server[2];
    int pipe_server_to_client[2];

    // Create pipes
    if (pipe(pipe_client_to_server) == -1 || pipe(pipe_server_to_client) == -1) 
    {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) 
    {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) 
    {  // Child process (Client)
        close(pipe_client_to_server[0]);
        close(pipe_server_to_client[1]);
        client(pipe_client_to_server[1], pipe_server_to_client[0]);
        exit(0);
    } else {  // Parent process (Server)
        close(pipe_client_to_server[1]);
        close(pipe_server_to_client[0]);
        server(pipe_client_to_server[0], pipe_server_to_client[1]);
        wait(nullptr);  // Wait for child process
    }
    return 0;
}
