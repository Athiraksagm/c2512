#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

void student_read(int& id, char name[]);
void student_print(int& id, char name[]);

int main() {
	int id1;
	char name1[255];

	int id2;
	char name2[255];

	cout << "Enter first student details." << endl;  student_read(id1, name1);
	cout << "Enter second student details." << endl;  student_read(id2, name2);

	student_print(id1, name1); 
	student_print(id2, name2);

	return EXIT_SUCCESS;
}

void student_read(int& id, char name[]) {
	cout << "Enter id:";
	cin >> id;
	cout << "Enter name:";
	cin >> name;
}

void student_print(int& id, char name[]) {
	cout << "Hello " << name << " of id " << id << "!!!" << endl;
}
