#include <iostream>
#include <string>
#include <memory> // For smart pointers
#include <utility> // For std::swap
using namespace std;

class Employee {
protected:
    unique_ptr<int> id;
    unique_ptr<int> age;
    unique_ptr<string> name;

public:
    // Constructor
    Employee(int id, int age, const string& name)
        : id(make_unique<int>(id)), age(make_unique<int>(age)), name(make_unique<string>(name)) {}

    // Destructor (non-virtual)
    virtual ~Employee() {
        cout << "Employee destructor called for ID: " << *id << endl;
    }

    // Move Constructor
    Employee(Employee&& other) noexcept
        : id(move(other.id)), age(move(other.age)), name(move(other.name)) {}

    // Move Assignment Operator
    Employee& operator=(Employee&& other) noexcept {
        id = move(other.id);
        age = move(other.age);
        name = move(other.name);
        return *this;
    }

    // Friend function to overload >> operator for input
    friend istream& operator>>(istream& is, Employee& emp) {
        // Input for the Employee details
        cout << "Enter ID: ";
        is >> *emp.id;
        cout << "Enter Age: ";
        is >> *emp.age;
        cout << "Enter Name: ";
        is >> *emp.name;
        return is;
    }

    // Friend function to overload << operator for output
    friend ostream& operator<<(ostream& os, const Employee& emp) {
        os << *emp.id << " " << *emp.age << " " << *emp.name;
        return os;
    }
};

class Programmer : public Employee {
private:
    unique_ptr<string[]> tasks; // Smart pointer for dynamic array of tasks
    int taskCount;

public:
    // Constructor
    Programmer(int id, int age, const string& name, string* taskList, int taskCount)
        : Employee(id, age, name), taskCount(taskCount) {
        tasks = make_unique<string[]>(taskCount);
        for (int i = 0; i < taskCount; ++i) {
            tasks[i] = taskList[i];
        }
    }

    // Destructor (non-virtual)
    ~Programmer() {
        cout << "Programmer destructor called for ID: " << *id << endl;
    }

    // Move Constructor
    Programmer(Programmer&& other) noexcept
        : Employee(move(other)), tasks(move(other.tasks)), taskCount(other.taskCount) {}

    // Move Assignment Operator
    Programmer& operator=(Programmer&& other) noexcept {
        Employee::operator=(move(other));
        tasks = move(other.tasks);
        taskCount = other.taskCount;
        return *this;
    }

    // Friend function to overload >> operator for input
    friend istream& operator>>(istream& is, Programmer& prog) {
        // Reuse Employee input operator to read common details
        is >> static_cast<Employee&>(prog);

        cout << "Enter number of tasks: ";
        is >> prog.taskCount;
        prog.tasks = make_unique<string[]>(prog.taskCount);
        
        for (int i = 0; i < prog.taskCount; ++i) {
            cout << "Enter Task " << i + 1 << ": ";
            is >> prog.tasks[i];
        }
        return is;
    }

    // Friend function to overload << operator for output
    friend ostream& operator<<(ostream& os, const Programmer& prog) {
        os << static_cast<const Employee&>(prog); // Call Employee's << operator
        os << " | Tasks: ";
        for (int i = 0; i < prog.taskCount; ++i) {
            os << prog.tasks[i];
            if (i < prog.taskCount - 1) os << ", ";
        }
        return os;
    }
};

int main() {
    int N;
    cout << "Enter the number of programmers: ";
    cin >> N;

    // Create an array of N programmers
    unique_ptr<Programmer[]> programmers = make_unique<Programmer[]>(N);

    // Read each programmer's details
    for (int i = 0; i < N; ++i) {
        cout << "Enter details for Programmer " << i + 1 << ":\n";
        cin >> programmers[i]; // Using overloaded >> operator
    }

    // Display the details of all programmers
    cout << "\nProgrammer details:\n";
    for (int i = 0; i < N; ++i) {
        cout << programmers[i] << endl; // Using overloaded << operator
    }

    return 0;
}

