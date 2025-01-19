
#include <iostream>
#include <unordered_map>
#include <string>
#include <ctime>

using namespace std;

// Structure to hold payment details
struct PaymentDetails {
    string patientId;
    string appointmentId;
    double consultationFee;
    string paymentStatus;
    string paymentDateTime;
};

// Class to manage Payment System
class PaymentManagement {
private:
    unordered_map<string, PaymentDetails> paymentRecords;

public:
    // Function to make a payment
    void makePayment(string appointmentId, string patientId, double fee) {
        cout << "Search Appointment id : " << appointmentId << endl;

        // Simulate checking for a valid appointment
        if (appointmentId != "APT3001") {
            cout << "Appointment id not found. Please enter valid Appointment id.. Thank You" << endl;
            return;
        }

        cout << "Shows Patient and payment details..\n";
        cout << "Patient Number: " << patientId << endl;
        cout << "Your Consultation fee is " << fee << endl;

        char continuePayment;
        cout << "Continue Payment..[Y/N]..";
        cin >> continuePayment;

        if (continuePayment == 'Y' || continuePayment == 'y') {
            string paymentMode;
            cout << "Select Payment mode : ";
            cin >> paymentMode;  // Assume the payment mode is always valid for simplicity
            cout << "Payment successful and your Payment id is PAY4001" << endl;

            // Store payment record
            time_t now = time(0);
            char* dt = ctime(&now);
            PaymentDetails payment;
            payment.patientId = patientId;
            payment.appointmentId = appointmentId;
            payment.consultationFee = fee;
            payment.paymentStatus = "Paid";
            payment.paymentDateTime = string(dt);

            paymentRecords["PAY4001"] = payment;
        } else {
            cout << "Payment Pending.. Complete your Payment for consultation." << endl;
        }
    }

    // Function to view payment details by payment ID
    void viewPaymentDetails(string paymentId) {
        cout << "Search Payment id : " << paymentId << endl;

        if (paymentRecords.find(paymentId) == paymentRecords.end()) {
            cout << "Payment id not found. Please verify the Payment id.. Thank You.." << endl;
            return;
        }

        PaymentDetails payment = paymentRecords[paymentId];
        cout << "Patient_id   | Appointment_id  | Consultation_fee | Payment_status | Payment_Date_Time(YY-MM-DD HH:MM)\n";
        cout << "-------------------------------------------------------------------------------------------------------------\n";
        cout << payment.patientId << " | " << payment.appointmentId << " | " 
             << payment.consultationFee << " | " << payment.paymentStatus << " | " 
             << payment.paymentDateTime << endl;
    }
};

class PatientApp {
public:
    void patientMenu(PaymentManagement& pm) {
        int choice;
        do {
            cout << "\nPatient App >> Payment Management\n";
            cout << "[1] Payment\n";
            cout << "[2] View Payment Details\n";
            cout << "[99] Exit\n";
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string appointmentId = "APT3001";
                    string patientId = "PAT1001";
                    double fee = 250;
                    pm.makePayment(appointmentId, patientId, fee);
                    break;
                }

                case 2: {
                    string paymentId;
                    cout << "Enter Payment id: ";
                    cin >> paymentId;
                    pm.viewPaymentDetails(paymentId);
                    break;
                }

                case 99:
                    cout << "LogOut....\n";
                    break;

                default:
                    cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 99);
    }
};

class AdminApp {
public:
    void adminMenu(PaymentManagement& pm) {
        int choice;
        do {
            cout << "\nAdmin App >> Payment Management\n";
            cout << "[1] View Patient Payment Details\n";
            cout << "[99] Exit\n";
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string paymentId;
                    cout << "Enter Payment id: ";
                    cin >> paymentId;
                    pm.viewPaymentDetails(paymentId);
                    break;
                }

                case 99:
                    cout << "LogOut....\n";
                    break;

                default:
                    cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 99);
    }
};

int main() {
    PaymentManagement pm;

    int userType;
    cout << "Enter User Type (1 - Patient, 2 - Admin): ";
    cin >> userType;

    switch (userType) {
        case 1: {
            PatientApp patientApp;
            patientApp.patientMenu(pm);
            break;
        }
        case 2: {
            AdminApp adminApp;
            adminApp.adminMenu(pm);
            break;
        }
        default:
            cout << "Invalid user type.\n";
    }

    return 0;
}
