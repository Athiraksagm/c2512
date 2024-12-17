#include <iostream>
#include <iomanip>
#include <deque>     // Include deque library
#include <algorithm> // Include algorithm for std::find_if

using namespace std;

class LabTest {
    friend class LabTestManager;
private:
    string TestID;
    double ResultValue;
public:
    string GetTestID();
    double GetResultValue();
};

class LabTestManager {
private:
    deque<LabTest> tests; // Use deque instead of vector
public:
    int findIndexById(const string& TestID);
    void create();
    void displayAll();
    void editById();
    void deleteById();
    LabTestManager();
};

void printMenu();

int main() {
    LabTestManager manager;
    int choice;

    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.create(); break;
            case 2: manager.displayAll(); break;
            case 3: manager.editById(); break;
            case 4: manager.deleteById(); break;
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}

void LabTestManager::create() {
    string TestID;
    double ResultValue;

    cout << "Enter LabTest TestID: ";
    cin >> TestID;

    if (findIndexById(TestID) != -1) {
        cout << "Error: LabTest TestID already exists. Please use a unique TestID.\n";
        return;
    }

    cout << "Enter Result Value: ";
    cin >> ResultValue;

    LabTest newTest;
    newTest.TestID = TestID;
    newTest.ResultValue = ResultValue;
    tests.push_back(newTest); // Insert at the end of the deque

    cout << "Lab Test created successfully.\n";
}

void LabTestManager::displayAll() {
    if (tests.empty()) {
        cout << "No tests available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "|   TESTID   |   Result Values                 |\n";
    cout << "------------------------------------------------\n";

    // Modern range-based for loop
    for (const auto& test : tests) {
        cout << "| " << setw(10) << test.TestID << " | "
             << setw(13) << test.ResultValue << " |\n";
    }

    cout << "------------------------------------------------\n";
}

int LabTestManager::findIndexById(const string& TestID) {
    auto it = find_if(tests.begin(), tests.end(), [&](const LabTest& test) {
        return test.TestID == TestID;
    });

    if (it != tests.end()) {
        return distance(tests.begin(), it); // Return the index position
    }
    return -1; // Return -1 if not found
}

void LabTestManager::editById() {
    string TestID;
    cout << "Enter LabTest TestID to edit: ";
    cin >> TestID;

    int index = findIndexById(TestID);
    if (index == -1) {
        cout << "Error: LabTest TestID not found.\n";
        return;
    }

    cout << "Current Details - Result Value: " << tests[index].ResultValue << "\n";

    cout << "Enter New Result Value: ";
    cin >> tests[index].ResultValue;

    cout << "Result Value updated successfully.\n";
}

void LabTestManager::deleteById() {
    string TestID;
    cout << "Enter LabTest TestID to delete: ";
    cin >> TestID;

    // Use find_if to directly locate and delete the matching LabTest
    auto it = find_if(tests.begin(), tests.end(), [&](const LabTest& test) {
        return test.TestID == TestID;
    });

    if (it != tests.end()) {
        tests.erase(it); // Erase the found element
        cout << "LabTest deleted successfully.\n";
    } else {
        cout << "Error: LabTest TestID not found.\n";
    }
}

LabTestManager::LabTestManager() {
    // No need to initialize tests, deque is empty by default
}

void printMenu() {
    cout << "\n=== Lab Test Management Module ===\n";
    cout << "1. Create Lab Test\n";
    cout << "2. Display All Lab Tests\n";
    cout << "3. Edit Lab Test\n";
    cout << "4. Delete Lab Test\n";
    cout << "5. Exit\n";
}

string LabTest::GetTestID() {
    return TestID;
}

double LabTest::GetResultValue() {
    return ResultValue;
}
