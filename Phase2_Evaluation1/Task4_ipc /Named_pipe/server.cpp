#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>

using namespace std;

int findSum(double array[], int size){
	double sum = 0;
	for(int i = 0; i < size; i++){
		sum += array[i];
	}
	return sum;
}

int main(){
	const char* pipe1 = "pipe1";
	const char* pipe2 = "pipe2";
	int pipe_one_read_fd, pipe_two_write_fd;
	pipe_one_read_fd = open(pipe1, O_RDONLY);
	pipe_two_write_fd = open(pipe2, O_WRONLY);
	if(pipe_one_read_fd == -1){
		perror("pipe1 open failure");
		return 1;
	}	
	
	if(pipe_two_write_fd == -1){
		perror("pipe2 open failure");
		return 1;
	}

	int numOfElements;
	read(pipe_one_read_fd, &numOfElements, sizeof(int));
	cout << "Server received number of elements: "<< numOfElements << endl ;
	
	double results[numOfElements] = {0};
	read(pipe_one_read_fd, results, sizeof(int) * numOfElements);
	cout << "Server received Results: ";
	for(int result : results){
		cout << result << "\t";
	}
	cout << endl;
	close(pipe_one_read_fd);
	
	int sum = findSum(results, numOfElements);
	write(pipe_two_write_fd, &sum, sizeof(int));
	cout << "Sum sent from server: " << sum << endl;

	close(pipe_two_write_fd);
	return 0;
}
