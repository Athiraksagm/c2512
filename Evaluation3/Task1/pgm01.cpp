// Coding Question: 1.1
/*
    Employee {id, age, name} //id, age, name are value objects 
    Employee e1(101,22,"Athira"),e2(102,23,"Bhagya");
    cout << e1 << endl; //101 22 Athira
    cout << e2 << endl; //102 23 Bhagya
    e1.swap(e2);
    cout << e1 << endl; //102 23 Bhagya
    cout << e2 << endl; //101 22 Athira
    */

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;        // Employee ID
    int age;       // Employee age
    string name;   // Employee name

public:
    // Parameterized Constructor
    Employee(int empId, int empAge, const string& empName) 
        : id(empId), age(empAge), name(empName) {}

    // Move Constructor
    Employee(Employee&& other) noexcept
        : id(other.id), age(other.age), name(std::move(other.name)) {
        other.id = 0;
        other.age = 0;
    }

    // Move Assignment Operator
    Employee& operator=(Employee&& other) noexcept {
        if (this != &other) {
            // Move the resources from the other object
            id = other.id;
            age = other.age;
            name = std::move(other.name);
            
            // Reset the state of the moved-from object
            other.id = 0;
            other.age = 0;
        }
        return *this;
    }

    // Overload << operator for displaying Employee details
    friend ostream& operator<<(ostream& os, const Employee& emp) {
        os << emp.id << " " << emp.age << " " << emp.name;
        return os;
    }

    // Swap function to swap two Employee objects using move constructor and move assignment
    void swap(Employee& other) {
        // Move current object to temporary
        Employee temp = std::move(*this);  // Move the current object to temp
        
        // Move the other object to the current object
        *this = std::move(other);          // Move the other object to *this
        
        // Move the temporary object to the other object
        other = std::move(temp);           // Move temp to the other object
    }
};

int main() {
    // Creating Employee objects
    Employee e1(101, 22, "Athira");
    Employee e2(102, 23, "Bhagya");

    // Display initial Employee details
    cout << "Before swapping:" << endl;
    cout << e1 << endl; // 101 22 Athira
    cout << e2 << endl; // 102 23 Bhagya

    // Swapping Employee objects
    e1.swap(e2);

    // Display Employee details after swapping
    cout << "After swapping:" << endl;
    cout << e1 << endl; // 102 23 Bhagya
    cout << e2 << endl; // 101 22 Athira

    return 0;
}
