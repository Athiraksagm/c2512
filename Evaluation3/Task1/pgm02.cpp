#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int* id;
    int* age;
    string* name;

public:
    // Constructor
    Employee(int id, int age, const string& name) {
        this->id = new int(id);         // Dynamically allocate memory for id
        this->age = new int(age);       // Dynamically allocate memory for age
        this->name = new string(name);  // Dynamically allocate memory for name
    }

    // Copy Constructor (for deep copy)
    Employee(const Employee& other) {
        id = new int(*other.id);
        age = new int(*other.age);
        name = new string(*other.name);
    }

    // Destructor
    ~Employee() {
        delete id;   // Free memory for id
        delete age;  // Free memory for age
        delete name; // Free memory for name
    }

    // Assignment Operator (for deep copy)
    Employee& operator=(const Employee& other) {
        if (this != &other) {
            // Free existing memory
            delete id;
            delete age;
            delete name;

            // Allocate new memory and copy values
            id = new int(*other.id);
            age = new int(*other.age);
            name = new string(*other.name);
        }
        return *this;
    }

    // Friend function to overload the << operator
    friend ostream& operator<<(ostream& os, const Employee& emp) {
        output << *emp.id << " " << *emp.age << " " << *emp.name; // Dereference pointers
        return output;
    }

    // Swap method
    void swap(Employee& other) {
        std::swap(id, other.id);   // Swap pointers
        std::swap(age, other.age);
        std::swap(name, other.name);
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

