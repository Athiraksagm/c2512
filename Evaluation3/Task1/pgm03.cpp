#include <iostream>
#include <string>
#include <utility> // For std::swap
using namespace std;

class Employee {
protected:
    int* id;
    int* age;
    string* name;

public:
    // Constructor
    Employee(int id, int age, const string& name) {
        this->id = new int(id);
        this->age = new int(age);
        this->name = new string(name);
    }

    // Destructor
    virtual ~Employee() {
        delete id;
        delete age;
        delete name;
    }

    // Copy Constructor
    Employee(const Employee& other) {
        id = new int(*other.id);
        age = new int(*other.age);
        name = new string(*other.name);
    }

    // Assignment Operator
    Employee& operator=(const Employee& other) {
        if (this != &other) {
            delete id;
            delete age;
            delete name;

            id = new int(*other.id);
            age = new int(*other.age);
            name = new string(*other.name);
        }
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
    string* tasks; // Dynamic array of tasks
    int taskCount;

public:
    // Constructor
    Programmer(int id, int age, const string& name, string* tasks, int taskCount)
        : Employee(id, age, name), taskCount(taskCount) {
        this->tasks = new string[taskCount];
        for (int i = 0; i < taskCount; ++i) {
            this->tasks[i] = tasks[i];
        }
    }

    // Destructor
    ~Programmer() override {
        delete[] tasks; // Free dynamic array
    }

    // Copy Constructor
    Programmer(const Programmer& other) : Employee(other) {
        taskCount = other.taskCount;
        tasks = new string[taskCount];
        for (int i = 0; i < taskCount; ++i) {
            tasks[i] = other.tasks[i];
        }
    }

    // Assignment Operator
    Programmer& operator=(const Programmer& other) {
        if (this != &other) {
            Employee::operator=(other); // Call base class assignment operator

            delete[] tasks; // Free existing memory
            taskCount = other.taskCount;
            tasks = new string[taskCount];
            for (int i = 0; i < taskCount; ++i) {
                tasks[i] = other.tasks[i];
            }
        }
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
    // Create dynamic array of tasks
    string tasks1[] = {"Code Review", "Develop Module A"};
    string tasks2[] = {"Debugging", "Documentation"};

    // Create dynamic Programmer objects
    Employee* emp1 = new Programmer(101, 25, "Athira", tasks1, 2);
    Employee* emp2 = new Programmer(102, 26, "Bhagya", tasks2, 2);

    // Display using overloaded << operator
    cout << *emp1 << endl;
    cout << *emp2 << endl;

    // Swap objects
    emp1->swap(*emp2);

    // Display after swapping
    cout << "After swapping:" << endl;
    cout << *emp1 << endl;
    cout << *emp2 << endl;

    // Clean up
    delete emp1;
    delete emp2;

    return 0;
}

