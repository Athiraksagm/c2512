#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <vector>

using namespace std;

class LabTest{
	private:
		string TestId;
		double ResultValues;
	public:
		LabTest(string TestId, int ResultValues){
			this -> TestId = TestId;
			this -> ResultValues = ResultValues;
		}

		double getResultValues(){ return this -> ResultValues; };

};

int main(){
	vector<LabTest> tests;
	tests.emplace_back("T001", 10.15);
	tests.emplace_back("T002", 20.25);
	tests.emplace_back("T003", 30.35);
	tests.emplace_back("T004", 40.45);
	tests.emplace_back("T005", 50.55);

	double results[tests.size()] = {0};
	
	for(int i = 0; i < tests.size(); i++){
		results[i] = tests[i].getResultValues();
	}

	
	int numOfElements = tests.size();

	const char* pipe1 = "pipe1";
	const char* pipe2 = "pipe2";
	int pipe_two_read_fd, pipe_one_write_fd;
	pipe_one_write_fd = open(pipe1, O_WRONLY);
	pipe_two_read_fd = open(pipe2, O_RDONLY);
        
	if(pipe_one_write_fd == -1){
		perror("pipe1 open failure at client");
		return 1;
	}
	if(pipe_two_read_fd == -1){
		perror("pipe2 open failure at client");
		return 1;
	}

	write(pipe_one_write_fd, &numOfElements, sizeof(int));
	cout << "Client sent number of elements: " << numOfElements << endl ;

	write(pipe_one_write_fd, doses, sizeof(doses));
	cout << "Client sent Results : ";
	for(double result:results){
		cout << result << "\t";
	}
	cout << endl;
	close(pipe_one_write_fd);

	sleep(1);

	int sum;
	read(pipe_two_read_fd, &sum, sizeof(int));
	cout << "sum received from server: " << sum << endl;

	close(pipe_two_read_fd);
	

	return 0;
}

