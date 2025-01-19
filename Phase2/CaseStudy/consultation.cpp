
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

struct MedicalHistory {
    string ailment;
    string diagnosis;
    string treatment;
    string prescription;
    string date_time;
};

class ConsultationManagement {
private:
    unordered_map<int, vector<MedicalHistory>> patientHistory;

public:
    // Add Medical History for a patient
    void addMedicalHistory(int doctorCode, int patientNumber, string ailment, string diagnosis, string treatment, string prescription) {
        if (doctorCode != 2001) {
            cout << "Doctor code not found. Please verify the Doctor Code... Thank You\n";
            return;
        }

        // Check if patient exists
        if (patientNumber <= 0) {
            cout << "Patient Number not found. Please verify Patient Number... Thank You\n";
            return;
        }

        MedicalHistory newHistory;
        newHistory.ailment = ailment;
        newHistory.diagnosis = diagnosis;
        newHistory.treatment = treatment;
        newHistory.prescription = prescription;

        // Get current date and time
        time_t now = time(0);
        char* dt = ctime(&now);
        newHistory.date_time = string(dt);

        // Add the history to the patient
        patientHistory[patientNumber].push_back(newHistory);

        cout << "Medical history of patient " << patientNumber << " added successfully!\n";
    }

    // View Medical History for a patient
    void viewMedicalHistory(int patientNumber) {
        if (patientHistory.find(patientNumber) == patientHistory.end()) {
            cout << "Patient Number not found. Please verify the Patient Number... Thank You\n";
            return;
        }

        cout << "Medical History for Patient Number " << patientNumber << ":\n";
        cout << "Initial_Ailment | Diagnosis | Treatment | Prescription | Date_and_Time\n";
        cout << "------------------------------------------------------------\n";
        for (const auto& history : patientHistory[patientNumber]) {
            cout << history.ailment << " | "
                 << history.diagnosis << " | "
                 << history.treatment << " | "
                 << history.prescription << " | "
                 << history.date_time;
        }
    }
};

class DoctorApp {
public:
    void doctorMenu(ConsultationManagement& cm) {
        int choice;
        do {
            cout << "\nDoctor App >> Consultation Management\n";
            cout << "[1] Add Medical History Details\n";
            cout << "[2] View Medical History Details\n";
            cout << "[99] Exit\n";
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int doctorCode, patientNumber;
                    string ailment, diagnosis, treatment, prescription;

                    cout << "Enter Doctor Code: ";
                    cin >> doctorCode;

                    cout << "Search Patient Number: ";
                    cin >> patientNumber;

                    cout << "Enter Diagnosis: ";
                    cin.ignore();  // To clear the buffer
                    getline(cin, diagnosis);

                    cout << "Enter Treatment: ";
                    getline(cin, treatment);

                    cout << "Enter Prescription: ";
                    getline(cin, prescription);

                    cm.addMedicalHistory(doctorCode, patientNumber, ailment = "Cough", diagnosis, treatment, prescription);
                    break;
                }

                case 2: {
                    int patientNumber;
                    cout << "Search Patient Number to be Viewed: ";
                    cin >> patientNumber;

                    cm.viewMedicalHistory(patientNumber);
                    break;
                }

                case 99:
                    cout << "LogOut........\n";
                    break;

                default:
                    cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 99);
    }
};

class PatientApp {
public:
    void patientMenu(ConsultationManagement& cm) {
        int choice;
        do {
            cout << "\nPatient App >> Consultation Management\n";
            cout << "[1] View Medical History Details\n";
            cout << "[99] Exit\n";
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int patientNumber;
                    cout << "Search Patient Number: ";
                    cin >> patientNumber;

                    cm.viewMedicalHistory(patientNumber);
                    break;
                }

                case 99:
                    cout << "LogOut........\n";
                    break;

                default:
                    cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 99);
    }
};

class AdminApp {
public:
    void adminMenu(ConsultationManagement& cm) {
        int choice;
        do {
            cout << "\nAdmin >> Consultation Management\n";
            cout << "[1] View Medical History Details\n";
            cout << "[99] Exit\n";
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int patientNumber;
                    cout << "Search Patient Number: ";
                    cin >> patientNumber;

                    cm.viewMedicalHistory(patientNumber);
                    break;
                }

                case 99:
                    cout << "LogOut........\n";
                    break;

                default:
                    cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 99);
    }
};

int main() {
    ConsultationManagement cm;

    int userType;
    cout << "Enter User Type (1 - Doctor, 2 - Patient, 3 - Admin): ";
    cin >> userType;

    switch (userType) {
        case 1: {
            DoctorApp doctorApp;
            doctorApp.doctorMenu(cm);
            break;
        }
        case 2: {
            PatientApp patientApp;
            patientApp.patientMenu(cm);
            break;
        }
        case 3: {
            AdminApp adminApp;
            adminApp.adminMenu(cm);
            break;
        }
        default:
            cout << "Invalid user type.\n";
    }

    return 0;
}
