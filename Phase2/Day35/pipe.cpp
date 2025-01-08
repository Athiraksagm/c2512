//two processing - concurrent programming
//IPC (inter process communication) via pipe
#include<iostream>
#include<unistd.h>
#include<cstring>

void client(int& read_end_fd) { //child 1
    sleep(1);
    
    char buffer[1024];
    read(read_end_fd, 
        buffer, 
        sizeof(buffer));
    close(read_end_fd);

    std::cout << "client:" << buffer << std::endl;
    //you can write now
}

void server(int& write_end_fd) { //child 2
    sleep(1);

    const char* msg = "hello";
    std::cout << "server:" << msg << std::endl;
    write(write_end_fd, 
         msg, 
         strlen(msg) + 1);
    close(write_end_fd);
    //you can read now
}

int main() {
    int pipe_fd[2];//read_end_fd, write_end_fd
    if(pipe(pipe_fd) == -1) {
        perror("pipe");
        std::cout << "pipe is not created." << std::endl;
        return 1;
    }
    int& read_end_fd = pipe_fd[0];
    int& write_end_fd = pipe_fd[1];

    pid_t pid = -1;

    {   //child 1
        pid = fork();
        if(0 == pid) {
            close(read_end_fd);
            server(write_end_fd);
            return 0;
        }
    }

    {   //child 2
        pid = fork();
        if(0 == pid) {
            close(write_end_fd);
            client(read_end_fd);
            return 0;
        }
    }

    // no parent process
    sleep(2);
    return 0;
}
