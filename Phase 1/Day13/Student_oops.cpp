#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

struct Student {
	int id;
	char name[255];
};

int main() {
	Student student1;
	Student student2;

	cout << "Enter first student details." << endl;
	cout << "Enter id:";
	cin >> student1.id;
	cout << "Enter name:";
	cin >> student1.name;
	
	cout << "Enter second student details." << endl;
	cout << "Enter id:";
	cin >> student2.id;
	cout << "Enter name:";
	cin >> student2.name;

	cout << "Hello " << student1.name << " of id " << student1.id << "!!!" << endl;
	cout << "Hello " << student2.name << " of id " << student2.id << "!!!" << endl;	

	return EXIT_SUCCESS;
}
