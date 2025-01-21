#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>

using namespace std;

struct MedicalHistory {
    string initial_ailment;
    string diagnosis;
    string treatment;
    string prescription;
    string date_and_time;
};

struct Patient {
    int patient_number;
    vector<MedicalHistory> history;
};

// Function to get the current date and time
string getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    sprintf(buffer, "%04d-%02d-%02d %02d:%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min);
    return string(buffer);
}

vector<Patient> patients;

// Function to find a patient by their patient number
Patient* findPatient(int patient_number) {
    for (auto& patient : patients) {
        if (patient.patient_number == patient_number) {
            return &patient;
        }
    }
    return nullptr;
}

// Input validation function
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

// Add medical history
void addMedicalHistory(int patient_number) {
    Patient* patient = findPatient(patient_number);
    if (!patient) {
        cout << "Patient Number not found. Please verify Patient Number ..Thank You\n";
        return;
    }

    MedicalHistory history;
    cin.ignore();
    cout << "Enter Initial Ailment: ";
    getline(cin, history.initial_ailment);
    cout << "Enter Diagnosis: ";
    getline(cin, history.diagnosis);
    cout << "Enter Treatment: ";
    getline(cin, history.treatment);
    cout << "Enter Prescription: ";
    getline(cin, history.prescription);
    history.date_and_time = getCurrentDateTime();

    patient->history.push_back(history);
    cout << "Medical history of patient (" << patient_number << ") added successfully!\n";
}

// View medical history with navigation and add option for Doctor
void viewMedicalHistory(int patient_number, bool is_doctor) {
    Patient* patient = findPatient(patient_number);
    if (!patient) {
        cout << "Patient Number not found. Please verify Patient Number ..Thank You\n";
        return;
    }

    if (patient->history.empty()) {
        cout << "No medical history available for Patient Number: " << patient_number << "\n";
        return;
    }

    int index = 0;
    while (true) {
        const auto& history = patient->history[index];
        cout << "\nMedical History for Patient Number " << patient_number << ":\n";
        cout << "Initial Ailment: " << history.initial_ailment << "\n";
        cout << "Diagnosis: " << history.diagnosis << "\n";
        cout << "Treatment: " << history.treatment << "\n";
        cout << "Prescription: " << history.prescription << "\n";
        cout << "Date and Time: " << history.date_and_time << "\n";

        cout << "\n[1] Prev  [2] Next";
        if (is_doctor) {
            cout << "  [3] Enter Medical History";
        }
        cout << "  [99] Back\nChoice: ";

        int choice = getValidatedInteger("");
        if (choice == 1 && index > 0) {
            index--;
        } else if (choice == 2 && index < patient->history.size() - 1) {
            index++;
        } else if (is_doctor && choice == 3) {
            addMedicalHistory(patient_number);
        } else if (choice == 99) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

// Doctor App Menu
void doctorApp() {
    while (true) {
        cout << "\nDoctor App >> Consultation Management\n";
        cout << "[1] Add Medical History Details\n";
        cout << "[2] View Medical History Details\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice = getValidatedInteger("");

        if (choice == 1) {
            int patient_number = getValidatedInteger("Enter Patient Number: ");
            addMedicalHistory(patient_number);
        } else if (choice == 2) {
            int patient_number = getValidatedInteger("Enter Patient Number: ");
            viewMedicalHistory(patient_number, true);
        } else if (choice == 99) {
            cout << "LogOut.......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

// Patient App Menu
void patientApp() {
    while (true) {
        cout << "\nPatient App >> Consultation Management\n";
        cout << "[1] View Medical History Details\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice = getValidatedInteger("");

        if (choice == 1) {
            int patient_number = getValidatedInteger("Enter Patient Number: ");
            viewMedicalHistory(patient_number, false);
        } else if (choice == 99) {
            cout << "LogOut.......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

// Admin App Menu
void adminApp() {
    while (true) {
        cout << "\nAdmin App >> Consultation Management\n";
        cout << "[1] View Medical History Details\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice = getValidatedInteger("");

        if (choice == 1) {
            int patient_number = getValidatedInteger("Enter Patient Number: ");
            viewMedicalHistory(patient_number, false);
        } else if (choice == 99) {
            cout << "LogOut.......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

// Main Menu
int main() {
    // Adding initial dummy patients for testing
    patients.push_back({1001, {}});
    patients.push_back({1002, {}});

    while (true) {
        cout << "\nSelect Role:\n";
        cout << "[1] Doctor\n";
        cout << "[2] Patient\n";
        cout << "[3] Admin\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice = getValidatedInteger("");

        if (choice == 1) {
            doctorApp();
        } else if (choice == 2) {
            patientApp();
        } else if (choice == 3) {
            adminApp();
        } else if (choice == 99) {
            cout << "Exiting Application...\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

_--------------=--------
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>

using namespace std;

struct MedicalHistory {
    string initial_ailment;
    string diagnosis;
    string treatment;
    string prescription;
    string date_and_time;
};

struct Patient {
    int patient_number;
    vector<MedicalHistory> history;
};

// Function to get the current date and time
string getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    sprintf(buffer, "%04d-%02d-%02d %02d:%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min);
    return string(buffer);
}

vector<Patient> patients;

// Function to find a patient by their patient number
Patient* findPatient(int patient_number) {
    for (auto& patient : patients) {
        if (patient.patient_number == patient_number) {
            return &patient;
        }
    }
    return nullptr;
}

// Input validation function
int getValidatedInteger(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            return value;
        }
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid number.\n";
    }
}

// Add medical history
void addMedicalHistory(int patient_number) {
    Patient* patient = findPatient(patient_number);
    if (!patient) {
        cout << "Patient Number not found. Please verify Patient Number ..Thank You\n";
        return;
    }

    MedicalHistory history;
    cin.ignore(); // To clear out the newline character from previous input
    cout << "Enter Initial Ailment: ";
    getline(cin, history.initial_ailment);
    cout << "Enter Diagnosis: ";
    getline(cin, history.diagnosis);
    cout << "Enter Treatment: ";
    getline(cin, history.treatment);
    cout << "Enter Prescription: ";
    getline(cin, history.prescription);
    history.date_and_time = getCurrentDateTime();

    patient->history.push_back(history);
    cout << "Medical history of patient (" << patient_number << ") added successfully!\n";
}

// View medical history with navigation and add option for Doctor
void viewMedicalHistory(int patient_number, bool is_doctor) {
    Patient* patient = findPatient(patient_number);
    if (!patient) {
        cout << "Patient Number not found. Please verify Patient Number ..Thank You\n";
        return;
    }

    if (patient->history.empty()) {
        cout << "No medical history available for Patient Number: " << patient_number << "\n";
        return;
    }

    int index = 0;
    while (true) {
        // Check if there is any history to show
        if (patient->history.empty()) {
            cout << "No medical history available.\n";
            break;
        }

        const auto& history = patient->history[index];
        cout << "\nMedical History for Patient Number " << patient_number << ":\n";
        cout << "Initial Ailment: " << history.initial_ailment << "\n";
        cout << "Diagnosis: " << history.diagnosis << "\n";
        cout << "Treatment: " << history.treatment << "\n";
        cout << "Prescription: " << history.prescription << "\n";
        cout << "Date and Time: " << history.date_and_time << "\n";

        // Navigation and options
        cout << "\n[1] Prev  [2] Next";
        if (is_doctor) {
            cout << "  [3] Enter Medical History";
        }
        cout << "  [99] Back\nChoice: ";

        int choice = getValidatedInteger("");
        if (choice == 1) { // Navigate to previous history
            if (index > 0) {
                index--;
            } else {
                cout << "No previous history available.\n";
            }
        } else if (choice == 2) { // Navigate to next history
            if (index < patient->history.size() - 1) {
                index++;
            } else {
                cout << "No next history available.\n";
            }
        } else if (is_doctor && choice == 3) { // Add new medical history
            addMedicalHistory(patient_number);
        } else if (choice == 99) { // Exit
            break;
        } else {
            cout << "Invalid choice! Please select a valid option.\n";
        }

        // If there are no more records (prev or next), we show no history message
        if (index == 0 && patient->history.size() == 1) {
            cout << "No more previous history available.\n";
        } else if (index == patient->history.size() - 1) {
            cout << "No more next history available.\n";
        }
    }
}

// Doctor App Menu
void doctorApp() {
    while (true) {
        cout << "\nDoctor App >> Consultation Management\n";
        cout << "[1] Add Medical History Details\n";
        cout << "[2] View Medical History Details\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice = getValidatedInteger("");

        if (choice == 1) {
            int patient_number = getValidatedInteger("Enter Patient Number: ");
            addMedicalHistory(patient_number);
        } else if (choice == 2) {
            int patient_number = getValidatedInteger("Enter Patient Number: ");
            viewMedicalHistory(patient_number, true);
        } else if (choice == 99) {
            cout << "LogOut.......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

// Patient App Menu
void patientApp() {
    while (true) {
        cout << "\nPatient App >> Consultation Management\n";
        cout << "[1] View Medical History Details\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice = getValidatedInteger("");

        if (choice == 1) {
            int patient_number = getValidatedInteger("Enter Patient Number: ");
            viewMedicalHistory(patient_number, false);
        } else if (choice == 99) {
            cout << "LogOut.......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

// Admin App Menu
void adminApp() {
    while (true) {
        cout << "\nAdmin App >> Consultation Management\n";
        cout << "[1] View Medical History Details\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice = getValidatedInteger("");

        if (choice == 1) {
            int patient_number = getValidatedInteger("Enter Patient Number: ");
            viewMedicalHistory(patient_number, false);
        } else if (choice == 99) {
            cout << "LogOut.......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

// Main Menu
int main() {
    // Adding initial dummy patients for testing
    patients.push_back({1001, {}});
    patients.push_back({1002, {}});

    while (true) {
        cout << "\nSelect Role:\n";
        cout << "[1] Doctor\n";
        cout << "[2] Patient\n";
        cout << "[3] Admin\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice = getValidatedInteger("");

        if (choice == 1) {
            doctorApp();
        } else if (choice == 2) {
            patientApp();
        } else if (choice == 3) {
            adminApp();
        } else if (choice == 99) {
            cout << "Exiting Application...\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

