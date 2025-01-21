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

