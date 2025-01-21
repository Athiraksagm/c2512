#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Department {
    string name;
    string headDoctorCode;
};

map<string, Department> departments; // Key: Department Number, Value: Department Info

string generateDepartmentNumber(int id) {
    return "DPT" + to_string(5000 + id);
}

void addDepartment() {
    static int departmentID = 1;
    Department newDepartment;

    cout << "Enter Department Name: ";
    cin.ignore();
    getline(cin, newDepartment.name);

    string departmentNumber = generateDepartmentNumber(departmentID++);
    departments[departmentNumber] = newDepartment;

    cout << newDepartment.name << " Department Created successfully.. and Department Number is " << departmentNumber << "\n";
}

void addDoctorToDepartment() {
    string departmentNumber, doctorCode;
    cout << "Search Department Number: ";
    cin >> departmentNumber;

    if (departments.find(departmentNumber) == departments.end()) {
        cout << "Department Number Not Found. Please Verify the Department Number.. Thank You\n";
        return;
    }

    cout << "Enter Doctor Code: ";
    cin >> doctorCode;

    // Simulating doctor code check (normally you'd validate against a list of doctors)
    if (doctorCode.empty() || doctorCode.length() < 3) {
        cout << "Doctor code not found. Please Verify the Doctor code.. Thank You\n";
        return;
    }

    departments[departmentNumber].headDoctorCode = doctorCode;
    cout << "Doctor Added successfully\n";
}

void assignHeadForDepartment() {
    string departmentNumber, doctorCode;
    cout << "Search Department Number: ";
    cin >> departmentNumber;

    if (departments.find(departmentNumber) == departments.end()) {
        cout << "Department Number Not Found. Please Verify the Department Number.. Thank You\n";
        return;
    }

    cout << "Enter Doctor code for Department Head: ";
    cin >> doctorCode;

    if (doctorCode.empty() || doctorCode.length() < 3) {
        cout << "Doctor code not found. Please Verify the Doctor code.. Thank You\n";
        return;
    }

    departments[departmentNumber].headDoctorCode = doctorCode;
    cout << "Department Head Created successfully!\n";
}

void viewDepartment() {
    string departmentNumber;
    cout << "Search Department Number: ";
    cin >> departmentNumber;

    if (departments.find(departmentNumber) == departments.end()) {
        cout << "Department Number Not Found.\n";
        return;
    }

    Department &dept = departments[departmentNumber];
    cout << "\nDepartment_Number  Department_Name  Department_Head_Code\n";
    cout << departmentNumber << "\t\t" << dept.name << "\t\t" << dept.headDoctorCode << "\n";
}

void editDepartment() {
    string departmentNumber;
    cout << "Search Department Number: ";
    cin >> departmentNumber;

    if (departments.find(departmentNumber) == departments.end()) {
        cout << "Department Number Not Found.\n";
        return;
    }

    int editChoice;
    cout << "\n[1] Edit Department Name\n";
    cout << "[2] Edit Department Head\n";
    cout << "[3] Edit Department Name and Head\n";
    cout << "Enter Choice: ";
    cin >> editChoice;

    Department &dept = departments[departmentNumber];

    switch (editChoice) {
        case 1: {
            cout << "Enter new Department Name: ";
            cin.ignore();
            getline(cin, dept.name);
            cout << "Department Name Updated successfully...\n";
            break;
        }
        case 2: {
            cout << "Enter new Doctor code for Head: ";
            cin >> dept.headDoctorCode;
            cout << "Department Head Updated successfully...\n";
            break;
        }
        case 3: {
            cout << "Enter new Department Name: ";
            cin.ignore();
            getline(cin, dept.name);
            cout << "Enter new Doctor code for Head: ";
            cin >> dept.headDoctorCode;
            cout << "Department Name and Head Updated successfully...\n";
            break;
        }
        default:
            cout << "Invalid choice.\n";
    }
}

void deleteDepartment() {
    string departmentNumber;
    cout << "Search the Department Number to be Deleted: ";
    cin >> departmentNumber;

    if (departments.find(departmentNumber) == departments.end()) {
        cout << "Department Number Not Found.\n";
        return;
    }

    string departmentName = departments[departmentNumber].name;
    departments.erase(departmentNumber);

    cout << "Department " << departmentName << "(" << departmentNumber << ") Deleted successfully..\n";
}

int main() {
    int choice;

    do {
        cout << "\n                       Admin >> Department Management\n";
        cout << "================================================================================\n";
        cout << "[1] Add Department\n";
        cout << "[2] Add Doctor to Department\n";
        cout << "[4] Assign Head For Department\n";
        cout << "[5] View Department\n";
        cout << "[6] Edit Department\n";
        cout << "[8] Delete Department\n";
        cout << "[99] Exit\n\n";
        cout << "Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                addDepartment();
                break;
            case 2:
                addDoctorToDepartment();
                break;
            case 4:
                assignHeadForDepartment();
                break;
            case 5:
                viewDepartment();
                break;
            case 6:
                editDepartment();
                break;
            case 8:
                deleteDepartment();
                break;
            case 99:
                cout << "LogOut......\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 99);

    return 0;
}

-----------

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Department {
    string department_name;
    string department_description;
    string department_head;
    string department_code;
    string doctor_code;
};

vector<Department> departments;

// Input validation functions
int getValidatedInteger(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail()) {
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
}

string getValidatedString(const string& prompt) {
    string value;
    cin.ignore();
    cout << prompt;
    getline(cin, value);
    return value;
}

// Admin's department management functions
void createDepartment() {
    Department new_dept;
    new_dept.department_name = getValidatedString("Enter Department Name: ");
    new_dept.department_description = getValidatedString("Enter Department Description: ");
    new_dept.department_head = getValidatedString("Assign Head to Department: ");
    new_dept.department_code = "DPT" + to_string(departments.size() + 5001);  // Creating department code like DPT5001
    new_dept.doctor_code = new_dept.department_head;  // Assume head is also the first doctor in the department

    // Adding department to the departments list
    departments.push_back(new_dept);
    cout << new_dept.department_name << " Department created successfully..\n";
    cout << "Head is " << new_dept.department_head << " and Department Number is " << new_dept.department_code << endl;
}

void editDepartment() {
    string dept_code = getValidatedString("Enter Department Code to Edit: ");
    bool found = false;
    for (auto& dept : departments) {
        if (dept.department_code == dept_code) {
            found = true;
            int edit_choice = getValidatedInteger("Enter Choice:\n[1] Edit Department Head\n[2] Edit Department Description\n[3] Edit Both\nChoice: ");
            if (edit_choice == 1) {
                dept.department_head = getValidatedString("Enter new Department Head: ");
                cout << "Department Head Updated successfully...\n";
            } else if (edit_choice == 2) {
                dept.department_description = getValidatedString("Enter new Department Description: ");
                cout << "Department Description updated successfully..\n";
            } else if (edit_choice == 3) {
                dept.department_head = getValidatedString("Enter new Department Head: ");
                dept.department_description = getValidatedString("Enter new Department Description: ");
                cout << "Department Head and Description Updated successfully...\n";
            } else {
                cout << "Invalid choice!\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Department Code not found.. Please verify the department number.. Thank You\n";
    }
}

void viewDepartment() {
    string dept_code = getValidatedString("Enter Department Code to View: ");
    bool found = false;
    for (const auto& dept : departments) {
        if (dept.department_code == dept_code) {
            found = true;
            cout << "\nDepartment Number: " << dept.department_code << "\n";
            cout << "Department Name: " << dept.department_name << "\n";
            cout << "Department Description: " << dept.department_description << "\n";
            cout << "Department Head: " << dept.department_head << "\n";
            cout << "Doctor Code: " << dept.doctor_code << "\n";
            break;
        }
    }
    if (!found) {
        cout << "Department Number not found. Please verify the Department Number.\n";
    }
}

void deleteDepartment() {
    string dept_code = getValidatedString("Enter Department Code to Delete: ");
    auto it = departments.begin();
    bool found = false;
    while (it != departments.end()) {
        if (it->department_code == dept_code) {
            found = true;
            cout << "Department " << it->department_name << " (" << it->department_code << ") Deleted successfully..\n";
            departments.erase(it);
            break;
        }
        ++it;
    }
    if (!found) {
        cout << "Department Number not found. Please verify the Department Number.\n";
    }
}

// Admin App Menu
void adminApp() {
    while (true) {
        cout << "\nAdmin >> Department Management\n";
        cout << "[1] Create Department\n";
        cout << "[2] Edit Department\n";
        cout << "[4] View Department\n";
        cout << "[8] Delete Department\n";
        cout << "[99] Exit\n";
        int choice = getValidatedInteger("Choice: ");
        
        if (choice == 1) {
            createDepartment();
        } else if (choice == 2) {
            editDepartment();
        } else if (choice == 4) {
            viewDepartment();
        } else if (choice == 8) {
            deleteDepartment();
        } else if (choice == 99) {
            cout << "LogOut......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

// Doctor App Menu
void doctorApp() {
    while (true) {
        cout << "\nDoctor >> Department Management\n";
        cout << "[1] View Department\n";
        cout << "[99] Exit\n";
        int choice = getValidatedInteger("Choice: ");
        
        if (choice == 1) {
            viewDepartment();
        } else if (choice == 99) {
            cout << "LogOut......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

// Main Menu
int main() {
    while (true) {
        cout << "\nSelect Role:\n";
        cout << "[1] Admin\n";
        cout << "[2] Doctor\n";
        cout << "[99] Exit\n";
        int choice = getValidatedInteger("Choice: ");

        if (choice == 1) {
            adminApp();
        } else if (choice == 2) {
            doctorApp();
        } else if (choice == 99) {
            cout << "Exiting Application...\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}


