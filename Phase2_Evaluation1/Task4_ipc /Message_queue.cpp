#include <iostream>
#include <vector>
#include <sys/msg.h>
#include <sys/wait.h>
#include <cstring>
#include <cstdlib>

#define MSG_KEY 1234

using namespace std;

// Define message structure
struct msgbuf_t {
    long mtype;             // Message type
    char mtext[1024];       // Message text
};

class LabTest {
private:
    string TestId;
    double ResultValues;

public:
    LabTest(string id, double value) : TestId(id), ResultValues(value) {}
    double getResultValues() const { return ResultValues; }
};

void client(int& msgid) {
    // Prepare test data
    vector<LabTest> tests = {
        LabTest("T001", 10.15),
        LabTest("T002", 20.25),
        LabTest("T003", 30.35),
        LabTest("T004", 40.45),
        LabTest("T005", 50.55)
    };

    int size = tests.size();
    double resultsArray[100];

    // Populate the results array
    for (int i = 0; i < size; ++i) {
        resultsArray[i] = tests[i].getResultValues();
    }

    // Send data to the server
    msgbuf_t message;
    message.mtype = 1;

    // Send size
    memcpy(message.mtext, &size, sizeof(size));
    if (msgsnd(msgid, &message, sizeof(size), 0) == -1) {
        perror("Client: Failed to send size");
        exit(1);
    }

    // Send data
    memcpy(message.mtext, resultsArray, sizeof(double) * size);
    if (msgsnd(msgid, &message, sizeof(double) * size, 0) == -1) {
        perror("Client: Failed to send data");
        exit(1);
    }

    // Wait for sum from server
    if (msgrcv(msgid, &message, sizeof(message.mtext), 2, 0) == -1) {
        perror("Client: Failed to receive sum");
        exit(1);
    }

    double sum;
    memcpy(&sum, message.mtext, sizeof(sum));
    cout << "Client received sum from server: " << sum << endl;
}

void server(int& msgid) {
    msgbuf_t message;

    // Receive size
    if (msgrcv(msgid, &message, sizeof(message.mtext), 1, 0) == -1) {
        perror("Server: Failed to receive size");
        exit(1);
    }

    int size;
    memcpy(&size, message.mtext, sizeof(size));

    // Receive data
    if (msgrcv(msgid, &message, sizeof(message.mtext), 1, 0) == -1) {
        perror("Server: Failed to receive data");
        exit(1);
    }

    double resultsArray[100];
    memcpy(resultsArray, message.mtext, sizeof(double) * size);

    cout << "Server received Result Values: ";
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        cout << resultsArray[i] << " ";
        sum += resultsArray[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    // Send sum back to the client
    message.mtype = 2;
    memcpy(message.mtext, &sum, sizeof(sum));
    if (msgsnd(msgid, &message, sizeof(sum), 0) == -1) {
        perror("Server: Failed to send sum");
        exit(1);
    }
}

int main() {
    int msgid = msgget(MSG_KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Failed to create message queue");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process - Client
        client(msgid);
        exit(0);
    }

    // Parent process - Server
    server(msgid);
    wait(nullptr); // Wait for client process to finish

    // Cleanup message queue
    if (msgctl(msgid, IPC_RMID, nullptr) == -1) {
        perror("Failed to remove message queue");
    }

    return 0;
}
