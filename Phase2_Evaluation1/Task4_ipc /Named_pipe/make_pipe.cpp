#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

int main(){
	const char* pipe1 = "pipe1";
	if(mkfifo(pipe1, 0666) == -1){
		perror("pipe1 failure");
		return 1;
	}
	cout << "pipe1 created successfully" << endl;
	
	const char* pipe2 = "pipe2";
	if(mkfifo(pipe2, 0666) == -1){
		perror("pipe2 failure");
		return 1;
	}
	cout << "pipe2 created successfully" << endl;

	return 0;
}
