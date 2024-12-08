#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

struct Student {
	int id;
	char name[255];
};

void student_read(Student& student);
void student_print(Student& student);

int main() {
	Student student1 {};
	Student student2 {};

	cout << "Enter first student details." << endl; student_read(student1);
	cout << "Enter second student details." << endl; student_read(student2);

	student_print(student1);
	student_print(student2);

	return EXIT_SUCCESS;
}

void student_read(Student& student) {
	cout << "Enter id:";
	cin >> student.id;
	cout << "Enter name:";
	cin >> student.name;
}

void student_print(Student& student) {
	cout << "Hello " << student.name << " of id " << student.id << "!!!" << endl;
}
