#include <iostream>
#include <vector>
#include <sys/ipc.h>
#include <sys/shm.h>
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

void client(double* shared_data, int* shared_size) 
{
    vector<LabTest> tests;
    tests.emplace_back("T001", 10.15);
    tests.emplace_back("T002", 20.25);
    tests.emplace_back("T003", 30.35);
    tests.emplace_back("T004", 40.45);
    tests.emplace_back("T005", 50.55);

    int size = tests.size();

    // Store result values in shared memory
    *shared_size = size;
    for (int i = 0; i < size; ++i) 
    {
        shared_data[i] = tests[i].getResultValues();
    }

    cout << "Client sending Result Values: ";
    for (int i = 0; i < size; ++i) 
    {
        cout << shared_data[i] << " ";
    }
    cout << endl;
}

void server(double* shared_data, int* shared_size, double* shared_sum) 
{
    int size = *shared_size;
    double sum = 0;

    cout << "Server received Result Values: ";
    for (int i = 0; i < size; ++i) 
    {
        cout << shared_data[i] << " ";
        sum += shared_data[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    // Store sum in shared memory
    *shared_sum = sum;
}

int main() 
{
    // Allocate shared memory for size, data, and sum
    int shm_size = sizeof(double) * 100 + sizeof(int) + sizeof(double);
    int shm_id = shmget(IPC_PRIVATE, shm_size, IPC_CREAT | 0666);
    if (shm_id == -1) 
    {
        perror("Shared memory creation failed");
        return 1;
    }

    void* shm_ptr = shmat(shm_id, nullptr, 0);
    if (shm_ptr == (void*)-1) 
    {
        perror("Shared memory attachment failed");
        return 1;
    }

    // Pointers to shared memory sections
    int* shared_size = (int*)shm_ptr;
    double* shared_data = (double*)((char*)shm_ptr + sizeof(int));
    double* shared_sum = (double*)((char*)shm_ptr + sizeof(int) + sizeof(double) * 100);

    pid_t pid = fork();
    if (pid == -1) 
    {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) 
    { // Child process (Client)
        client(shared_data, shared_size);
        exit(0);
    } 
    else 
    { // Parent process (Server)
        wait(nullptr); // Wait for child process to complete
        server(shared_data, shared_size, shared_sum);
        cout << "Client received sum from server: " << *shared_sum << endl;
    }

    // Detach and remove shared memory
    shmdt(shm_ptr);
    shmctl(shm_id, IPC_RMID, nullptr);

    return 0;
}

