#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    int age;
    string name;

public:
    // Constructor
    Employee(int id, int age, const string& name) : id(id), age(age), name(name) {}

    // Friend function to overload the << operator
    friend ostream& operator<<(ostream& os, const Employee& emp) {
        output << emp.id << " " << emp.age << " " << emp.name;
        return output;
    }

    // Swap method
    void swap(Employee& other) {
        std::swap(this->id, other.id);
        std::swap(this->age, other.age);
        std::swap(this->name, other.name);
    }
};

int main() {
    Employee e1(101, 22, "Athira");
    Employee e2(102, 23, "Bhagya");

    cout << e1 << endl; // 101 22 Athira
    cout << e2 << endl; // 102 23 Bhagya

    e1.swap(e2);

    cout << e1 << endl; // 102 23 Bhagya
    cout << e2 << endl; // 101 22 Athira

    return 0;
}

