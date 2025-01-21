#include <iostream>
#include <vector>
#include <string>
#include <ctime>
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

// Function to get current date and time
string getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    sprintf(buffer, "%04d-%02d-%02d %02d:%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min);
    return string(buffer);
}

vector<Patient> patients;

Patient* findPatient(int patient_number) {
    for (auto& patient : patients) {
        if (patient.patient_number == patient_number) {
            return &patient;
        }
    }
    return nullptr;
}

void addMedicalHistory(int patient_number) {
    Patient* patient = findPatient(patient_number);
    if (!patient) {
        cout << "Patient Number not found. Please verify Patient Number ..Thank You\n";
        return;
    }

    MedicalHistory history;
    cout << "Enter Initial Ailment: ";
    cin.ignore();
    getline(cin, history.initial_ailment);
    cout << "Enter Diagnosis: ";
    getline(cin, history.diagnosis);
    cout << "Enter Treatment: ";
    getline(cin, history.treatment);
    cout << "Enter Prescription: ";
    getline(cin, history.prescription);
    history.date_and_time = getCurrentDateTime();

    patient->history.push_back(history);
    cout << "Medical history of patient(" << patient_number << ") added successfully!\n";
}

void viewMedicalHistory(int patient_number, int& index) {
    Patient* patient = findPatient(patient_number);
    if (!patient) {
        cout << "Patient Number not found. Please verify Patient Number ..Thank You\n";
        return;
    }

    if (patient->history.empty()) {
        cout << "No medical history available for Patient Number: " << patient_number << "\n";
        return;
    }

    const auto& history = patient->history[index];
    cout << "Medical History for Patient Number " << patient_number << ":\n";
    cout << "Initial Ailment: " << history.initial_ailment << "\n";
    cout << "Diagnosis: " << history.diagnosis << "\n";
    cout << "Treatment: " << history.treatment << "\n";
    cout << "Prescription: " << history.prescription << "\n";
    cout << "Date and Time: " << history.date_and_time << "\n";

    cout << "\n[1] Prev  [2] Next  [3] Enter Medical History  [99] Back\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;

    if (choice == 1 && index > 0) {
        index--;
        viewMedicalHistory(patient_number, index);
    } else if (choice == 2 && index < patient->history.size() - 1) {
        index++;
        viewMedicalHistory(patient_number, index);
    } else if (choice == 3) {
        addMedicalHistory(patient_number);
    } else if (choice == 99) {
        return;
    } else {
        cout << "Invalid choice!\n";
    }
}

void doctorApp() {
    while (true) {
        cout << "\nDoctor App >> Consultation Management\n";
        cout << "[1] Add Medical History Details\n";
        cout << "[2] View Medical History Details\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice, patient_number;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Patient Number: ";
            cin >> patient_number;
            addMedicalHistory(patient_number);
        } else if (choice == 2) {
            cout << "Enter Patient Number: ";
            cin >> patient_number;
            int index = 0;
            viewMedicalHistory(patient_number, index);
        } else if (choice == 99) {
            cout << "LogOut.......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

void patientApp() {
    while (true) {
        cout << "\nPatient App >> Consultation Management\n";
        cout << "[1] View Medical History Details\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice, patient_number;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Patient Number: ";
            cin >> patient_number;
            int index = 0;
            viewMedicalHistory(patient_number, index);
        } else if (choice == 99) {
            cout << "LogOut.......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

void adminApp() {
    while (true) {
        cout << "\nAdmin App >> Consultation Management\n";
        cout << "[1] View Medical History Details\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice, patient_number;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Patient Number: ";
            cin >> patient_number;
            int index = 0;
            viewMedicalHistory(patient_number, index);
        } else if (choice == 99) {
            cout << "LogOut.......\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

int main() {
    patients.push_back({1001, {}});
    patients.push_back({1002, {}});

    while (true) {
        cout << "\nSelect Role:\n";
        cout << "[1] Doctor\n";
        cout << "[2] Patient\n";
        cout << "[3] Admin\n";
        cout << "[99] Exit\n";
        cout << "Choice: ";
        int choice;
        cin >> choice;

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
