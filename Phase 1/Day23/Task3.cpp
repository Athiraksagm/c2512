single inheritance with dynamic binding
============================================================
one two dynamic/static objects of the Derived class 
pointed by base class pointer
and call all behaviours using Base class pointer 

Override Base Class behaviors to derived class.
Define constructors and destructors for all the classes 
Define all the fields as dynamic fields in each class 

If you use string, use c-string (don't use string class)
        ie. dynamic c-string [dynamic char array]

Problem 15: `Employee and Developer`
- `Base Class:` `Employee`  
  - Fields: `name`, `id`  
  - Pure Virtual Behaviors: `work()`, `takeBreak()`.  
- `Derived Class:` `Developer`  
  - Fields: `programmingLanguage`, `projects` 

solution:

#include <iostream>
#include <cstring>

using namespace std;

// Base Class: Employee
class Employee
{
protected:
    char* name;
    int id;

public:
    // Constructor
    Employee(const char* empName, int empId) : id(empId)
   {
        name = new char[strlen(empName) + 1];
        strcpy(name, empName);
        cout << "Employee constructor called ! " << endl;
    }

    // Virtual Destructor
    virtual ~Employee() 
    {
        cout << "Employee destructor called ! "  << endl;
        delete[] name;
    }

    // Pure Virtual function
    virtual void work() const = 0;
    virtual void takeBreak() const = 0;
};

// Derived Class: Developer
class Developer : public Employee
 {
protected:
    char* programmingLanguage;
    int projects;

public:
    // Constructor
    Developer(const char* devName, int devId, const char* lang, int proj) 
        : Employee(devName, devId), projects(proj)
    {
        programmingLanguage = new char[strlen(lang) + 1];
        strcpy(programmingLanguage, lang);
        cout << "Developer constructor called for " << name << endl;
    }

    // Destructor
    ~Developer() override
    {
        cout << "Developer destructor called for " << name << endl;
        delete[] programmingLanguage;
    }

    // Overridden function
    void work() const override
    {
        cout << name << " (ID: " << id << ") is coding in " 
             << programmingLanguage << " on " << projects << " projects." << endl;
    }

    void takeBreak() const override
    {
        cout << name << " (ID: " << id << ") is taking a coffee break." << endl;
    }
};

int main()
 {
    cout << "=== Dynamic  object ===" << endl;

    // Base class pointer to Derived class objects
    Employee* emp1 = new Developer("Alice", 101, "C++", 3);
    Employee* emp2 = new Developer("Bob", 102, "Java", 5);

    // Call overridden behaviors using base class pointers
    emp1->work();
    emp1->takeBreak();

    emp2->work();
    emp2->takeBreak();

    // Clean up
    delete emp1;
    delete emp2;

    return 0;
}

