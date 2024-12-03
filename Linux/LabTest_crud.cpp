#include <iostream>
#include <iomanip>


using namespace std;

const int MAX_LAB_TESTS = 100;

class LabTest {
    friend class LabTestManager;
    private:
        string TestID;
        double ResultValue;
    public:
	bool GreaterThan(const LabTest& other);
	bool LessThan(const LabTest& other);
       
        
        string GetTestID();
        double GetResultValue();
};

class LabTestManager {
    friend class LabTestAggregator;
    friend int main();
    private:
        
        LabTest tests[MAX_LAB_TESTS];    
        int numLabTests;
    public:
        
        int findIndexById(string TestID);
        void create();
        void displayAll();
        void editById();
        void deleteById();
        
        LabTestManager();
};

class LabTestAggregator {
    public:
        int findMin(LabTestManager& manager);
        int findMax(LabTestManager& manager);
        int findSecondMin(LabTestManager& manager);
        int findSecondMax(LabTestManager& manager);
};

void printMenu();



int main() {
    LabTestManager manager;
    LabTestAggregator aggregator;
   
    int choice; 

    do {
        printMenu(); 
        cout << "Enter your choice: ";
        cin >> choice;

        
        switch (choice) {
            case 1: manager.create();    break;
            case 2: manager.displayAll();  break;
            case 3: manager.editById();      break;
            case 4: manager.deleteById();    break;
            case 5: 
                std::cout << "LabTest with Min Test: " 
                    << manager.tests[aggregator.findMin(manager)].GetTestID() 
                    << " with ResultValue " 
                    << manager.tests[aggregator.findMin(manager)].GetResultValue() 
                    << std::endl;
                break;
            case 6: 
                std::cout << "LabTest with Max Test: " 
                    << manager.tests[aggregator.findMax(manager)].GetTestID() 
                    << " with ResultValue " 
                    << manager.tests[aggregator.findMax(manager)].GetResultValue() 
                    << std::endl;
                break;
            case 7: 
                std::cout << "LabTest with 2nd Min Test: " 
                    << manager.tests[aggregator.findSecondMin(manager)].GetTestID() 
                    << " with ResultValue " 
                    << manager.tests[aggregator.findSecondMin(manager)].GetResultValue() 
                    << std::endl;
                break;
            case 8: 
                std::cout << "LabTest with 2nd Max Test: " 
                    << manager.tests[aggregator.findSecondMax(manager)].GetTestID() 
                    << " with ResultValue " 
                    << manager.tests[aggregator.findSecondMax(manager)].GetResultValue() 
                    << std::endl;
                break;
            case 9:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }
    } while (choice != 9);

    return 0;
}

void LabTestManager::create() {
    if (numLabTests >= MAX_LAB_TESTS) {
        cout << "Error: Maximum Lab test limit reached.\n";
        return;
    }

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

    
    tests[numLabTests].TestID = TestID;
    tests[numLabTests].ResultValue = ResultValue;
    numLabTests++;

    cout << "Lab Test created successfully.\n";
}

void LabTestManager::displayAll() {
    if (numLabTests == 0) {
        cout << "No tests available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "|   TESTID | Result Values                     |\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < numLabTests; i++) {
        cout << "| " << setw(10) << tests[i].TestID << " | "
             << setw(13) << tests[i].ResultValue  << " |\n";
    }
    cout << "------------------------------------------------\n";
}


int LabTestManager::findIndexById(string TestID) {
    for (int i = 0; i < numLabTests; i++) {
        if (tests[i].TestID == TestID) {
            return i;
        }
    }
    return -1;
}


void LabTestManager::editById() {
    string TestID;
    cout << "Enter LabTest TestID to edit: ";
    cin >> TestID;

    int index = findIndexById(TestID);
    if (index == -1) {
        cout << "Error: LabTest TESTID not found.\n";
        return;
    }

    cout << "Current Details - Result Value: " << tests[index].ResultValue << "\n";

    cout << "Enter New Result Value: ";
    cin >> tests[index].ResultValue;

    cout << "ResultValue updated successfully.\n";
}


void LabTestManager::deleteById() {
    string TestID;
    cout << "Enter LabTest TestID to delete: ";
    cin >> TestID;

    int index = findIndexById(TestID);
    if (index == -1) {
        cout << "Error: LabTest TestID not found.\n";
        return;
    }

    
    for (int i = index; i < numLabTests - 1; i++) {
        tests[i] = tests[i + 1];
    }
    numLabTests--;

    cout << "LabTest deleted successfully.\n";
}

LabTestManager::LabTestManager() {
    numLabTests = 0;
}

void printMenu() {
    cout << "\n=== Lab Test Management Module ===\n";
    cout << "1. Create Lab Test\n";
    cout << "2. Display All Lab Tests\n";
    cout << "3. Edit Lab Test\n";
    cout << "4. Delete Lab Test\n";
    cout << "5. Find Min Test\n";
    cout << "6. Find Max Test\n";
    cout << "7. Find Second Min Test\n";
    cout << "8. Find Second Max Test\n";
    cout << "9. Exit\n";
}


bool LabTest::GreaterThan(const LabTest& other)
{
    return (ResultValue > other.ResultValue);
}
bool LabTest::LessThan(const LabTest& other)
{
    return (ResultValue > other.ResultValue);
}


string LabTest::GetTestID()
{
    return TestID;
}
double LabTest::GetResultValue()
{
    return ResultValue;
}

int LabTestAggregator::findMin(LabTestManager& manager) {
    LabTest* arr = manager.tests;
    int& n = manager.numLabTests;
   
    int minIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].LessThan(arr[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}


int LabTestAggregator::findMax(LabTestManager& manager) {
    LabTest* arr = manager.tests;
    int& n = manager.numLabTests;
   
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].GreaterThan(arr[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}


int LabTestAggregator::findSecondMin(LabTestManager& manager) {
    LabTest* arr = manager.tests;
    int& n = manager.numLabTests;
   
    int minIndex = findMin(manager);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;
    
    for (int i = 0; i < n; ++i) {
        if (i != minIndex) {
            if (arr[i].LessThan(arr[secondMinIndex])) {
                secondMinIndex = i;
            }
        }
    }
    return secondMinIndex;
}


int LabTestAggregator::findSecondMax(LabTestManager& manager) {
    LabTest* arr = manager.tests;
    int& n = manager.numLabTests;
   
    int maxIndex = findMax(manager);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;
    
    for (int i = 0; i < n; ++i) {
        if (i != maxIndex) {
            if (arr[i].GreaterThan(arr[secondMaxIndex])) {
                secondMaxIndex = i;
            }
        }
    }
    return secondMaxIndex;
}
