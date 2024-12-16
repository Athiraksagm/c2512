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
    ~Employee() {
        cout << "Employee destructor called for ID: " << *id << endl;
    }

    // Copy Constructor (deleted due to unique_ptr)
    Employee(const Employee& other) = delete;

    // Move Constructor
    Employee(Employee&& other) noexcept
        : id(move(other.id)), age(move(other.age)), name(move(other.name)) {}

    // Copy Assignment Operator (deleted due to unique_ptr)
    Employee& operator=(const Employee& other) = delete;

    // Move Assignment Operator
    Employee& operator=(Employee&& other) noexcept {
        id = move(other.id);
        age = move(other.age);
        name = move(other.name);
        return *this;
    }

    // Swap method
    virtual void swap(Employee& other) {
        std::swap(id, other.id);
        std::swap(age, other.age);
        std::swap(name, other.name);
    }

    // Friend function to overload << operator
    friend ostream& operator<<(ostream& os, const Employee& emp) {
        os << *emp.id << " " << *emp.age << " " << *emp.name;
        return os;
    }
};

class Programmer : public Employee {
private:
    unique_ptr<string[]> tasks; // Smart pointer for dynamic array
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

    // Swap method
    void swap(Programmer& other) override {
        Employee::swap(other); // Call base class swap
        std::swap(tasks, other.tasks);
        std::swap(taskCount, other.taskCount);
    }

    // Friend function to overload << operator
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
    // Task lists
    string tasks1[] = {"Develop Module A", "Code Review"};
    string tasks2[] = {"Debugging", "Documentation"};

    // Create dynamic Programmer objects assigned to Employee smart pointers
    unique_ptr<Employee> emp1 = make_unique<Programmer>(101, 25, "Athira", tasks1, 2);
    unique_ptr<Employee> emp2 = make_unique<Programmer>(102, 26, "Bhagya", tasks2, 2);

    // Display details
    cout << *emp1 << endl;
    cout << *emp2 << endl;

    // Swap objects
    emp1->swap(*emp2);

    // Display after swapping
    cout << "After swapping:" << endl;
    cout << *emp1 << endl;
    cout << *emp2 << endl;

    // Destructors are automatically called when unique_ptr goes out of scope
    return 0;
}

