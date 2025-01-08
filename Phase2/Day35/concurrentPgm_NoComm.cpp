#include<iostream>
#include<unistd.h>

void client() { //child 1
    sleep(1);
    std::cout << "client" << std::endl;
}

void server() { //child 2
    sleep(1);
    std::cout << "server" << std::endl;
}

int main() {
    pid_t pid = -1;

    {   //child 1
       pid_t pid = fork();
        if(0 == pid) {
            server();
            return 0;
        }
    }

    {   //child 2
       pid_t pid = fork();
        if(0 == pid) {
            client();
            return 0;
        }
    }

    // no parent process
    sleep(2);
    return 0;
}
