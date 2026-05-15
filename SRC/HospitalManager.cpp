#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "Admin.h"
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"

using namespace std;

// --- Helper Functions for Validation ---
bool isDigitChar(char c) {
    return (c >= '0' && c <= '9');
}

bool isAlphaChar(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isNumber(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isDigitChar(c)) return false;
    }
    return true;
}

bool isAlphaOnly(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isAlphaChar(c) && c != ' ') return false;
    }
    return true;
}

bool isValidPhone(const string& str) {
    if (str.length() != 11) return false;
    if (str[0] != '0' || str[1] != '1') return false;
    for (char c : str) {
        if (!isDigitChar(c)) return false;
    }
    return true;
}

bool isValidEmail(const string& str) {
    if (str.empty()) return false;
    if (str.find('@') != string::npos && str.find(".com") != string::npos) {
        return true;
    }
    return false;
}

bool isValidGender(const string& str) {
    return (str == "male" || str == "female" || str == "Male" || str == "Female");
}

bool isValidPassword(const string& str) {
    if(str.empty()) return false;
    bool hasLetter = false, hasDigit = false;
    for(char c : str) {
        if(isAlphaChar(c)) hasLetter = true;
        if(isDigitChar(c)) hasDigit = true;
    }
    return hasLetter && hasDigit;
}

// Global arrays to store our data
const int MAX_DOCTORS = 100;
const int MAX_PATIENTS = 100;

Doctor* doctors[MAX_DOCTORS] = {nullptr};
int doctorCount = 0;

Patient* patients[MAX_PATIENTS] = {nullptr};
int patientCount = 0;

int appointmentCounter = 1;

// --- File Handling Functions ---
void loadData() {
    // Load Doctors
    ifstream docFile("doctors.txt");
    if (docFile.is_open()) {
        int id, exp;
        string user, pass, name, phone, email, spec;
        while (docFile >> id >> user >> pass >> name >> phone >> email >> spec >> exp) {
            if(doctorCount < MAX_DOCTORS) {
                doctors[doctorCount++] = new Doctor(id, user, pass, name, phone, email, spec, exp);
            }
        }
        docFile.close();
    }

    // Load Patients
    ifstream patFile("patients.txt");
    if (patFile.is_open()) {
        int id, age;
        string user, pass, name, gender, phone, history;
        while (patFile >> id >> user >> pass >> name >> age >> gender >> phone >> history) {
            if(patientCount < MAX_PATIENTS) {
                patients[patientCount++] = new Patient(id, user, pass, name, age, gender, phone, history);
            }
        }
        patFile.close();
    }
}

void saveData() {
    // Save Doctors
    ofstream docFile("doctors.txt");
    for (int i = 0; i < doctorCount; i++) {
        docFile << doctors[i]->getId() << " "
                << doctors[i]->getUsername() << " "
                << doctors[i]->getPassword() << " "
                << doctors[i]->getName() << " "
                << doctors[i]->getPhone() << " "
                << doctors[i]->getEmail() << " "
                << doctors[i]->getSpecialization() << " "
                << doctors[i]->getExperienceYears() << "\n";
    }
    docFile.close();

    // Save Patients
    ofstream patFile("patients.txt");
    for (int i = 0; i < patientCount; i++) {
        patFile << patients[i]->getId() << " "
                << patients[i]->getUsername() << " "
                << patients[i]->getPassword() << " "
                << patients[i]->getName() << " "
                << patients[i]->getAge() << " "
                << patients[i]->getGender() << " "
                << patients[i]->getPhone() << " "
                << patients[i]->getMedicalHistory() << "\n";
    }
    patFile.close();
}

// --- Menus ---

void adminMenu(Admin& admin) {
    int choice;
    string inputStr;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Doctor\n";
        cout << "2. Remove Doctor\n";
        cout << "3. Add Patient\n";
        cout << "4. Remove Patient\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> inputStr;
        if (!isNumber(inputStr)) {
            cout << "Invalid choice!\n";
            choice = -1;
            continue;
        }
        choice = stoi(inputStr);

        if (choice == 1) {
            string idStr, user, pass, name, phone, email, spec, expStr;
            int id, exp;
            
            while(true) {
                cout << "Enter ID (numbers only): "; cin >> idStr;
                if(isNumber(idStr)) { id = stoi(idStr); break; }
                cout << "Error: ID must only contain numbers.\n";
            }
            while(true) {
                cout << "Enter Username (string only): "; cin >> user;
                if(isAlphaOnly(user)) break;
                cout << "Error: Username must only contain string letters.\n";
            }
            while(true) {
                cout << "Enter Password (string and numbers): "; cin >> pass;
                if(isValidPassword(pass)) break;
                cout << "Error: Password must contain letters and numbers.\n";
            }
            while(true) {
                cout << "Enter Name (string only): "; cin >> ws; getline(cin, name);
                if(isAlphaOnly(name)) break;
                cout << "Error: Name must only contain string letters.\n";
            }
            while(true) {
                cout << "Enter Phone (11 digits, starts with 01): "; cin >> phone;
                if(isValidPhone(phone)) break;
                cout << "Error: Invalid phone number format. Must be 11 digits and start with 01.\n";
            }
            while(true) {
                cout << "Enter Email (must contain @ and .com): "; cin >> email;
                if(isValidEmail(email)) break;
                cout << "Error: Email must contain @ and .com (@gmail.com).\n";
            }
            while(true) {
                cout << "Enter Specialization (string only): "; cin >> ws; getline(cin, spec);
                if(isAlphaOnly(spec)) break;
                cout << "Error: Specialization must only contain string letters.\n";
            }
            while(true) {
                cout << "Enter Experience Years (numbers only): "; cin >> expStr;
                if(isNumber(expStr)) { exp = stoi(expStr); break; }
                cout << "Error: Experience must only contain numbers.\n";
            }

            if (admin.addDoctor(doctors, doctorCount, id, user, pass, name, phone, email, spec, exp)) {
                cout << "Doctor added successfully!\n";
            } else {
                cout << "Cannot add more doctors. Maximum capacity reached.\n";
            }
            saveData();
        } else if (choice == 2) {
            string idStr;
            int id;
            while(true) {
                cout << "Enter Doctor ID to remove (numbers only): "; cin >> idStr;
                if(isNumber(idStr)) { id = stoi(idStr); break; }
                cout << "Error: ID must only contain numbers.\n";
            }
            if (admin.removeDoctor(doctors, doctorCount, id)) {
                cout << "Doctor removed successfully!\n";
            } else {
                cout << "Doctor with ID " << id << " not found!\n";
            }
            saveData();
        } else if (choice == 3) {
            string idStr, user, pass, name, ageStr, gender, phone, history;
            int id, age;
            
            while(true) {
                cout << "Enter ID (numbers only): "; cin >> idStr;
                if(isNumber(idStr)) { id = stoi(idStr); break; }
                cout << "Error: ID must only contain numbers.\n";
            }
            while(true) {
                cout << "Enter Username (string only): "; cin >> user;
                if(isAlphaOnly(user)) break;
                cout << "Error: Username must only contain string letters.\n";
            }
            while(true) {
                cout << "Enter Password (string and numbers): "; cin >> pass;
                if(isValidPassword(pass)) break;
                cout << "Error: Password must contain letters and numbers.\n";
            }
            while(true) {
                cout << "Enter Name (string only): "; cin >> ws; getline(cin, name);
                if(isAlphaOnly(name)) break;
                cout << "Error: Name must only contain string letters.\n";
            }
            while(true) {
                cout << "Enter Age (numbers only): "; cin >> ageStr;
                if(isNumber(ageStr)) { age = stoi(ageStr); break; }
                cout << "Error: Age must only contain numbers.\n";
            }
            while(true) {
                cout << "Enter Gender (male/female): "; cin >> gender;
                if(isValidGender(gender)) break;
                cout << "Error: Gender must be 'male' or 'female'.\n";
            }
            while(true) {
                cout << "Enter Phone (11 digits, starts with 01): "; cin >> phone;
                if(isValidPhone(phone)) break;
                cout << "Error: Invalid phone number format. Must be 11 digits and start with 01.\n";
            }
            while(true) {
                cout << "Enter Medical History (string only): "; cin >> ws; getline(cin, history);
                if(isAlphaOnly(history)) break;
                cout << "Error: History must only contain string letters.\n";
            }

            if (admin.addPatient(patients, patientCount, id, user, pass, name, age, gender, phone, history)) {
                cout << "Patient added successfully!\n";
            } else {
                cout << "Cannot add more patients. Maximum capacity reached.\n";
            }
            saveData();
        } else if (choice == 4) {
            string idStr;
            int id;
            while(true) {
                cout << "Enter Patient ID to remove (numbers only): "; cin >> idStr;
                if(isNumber(idStr)) { id = stoi(idStr); break; }
                cout << "Error: ID must only contain numbers.\n";
            }
            if (admin.removePatient(patients, patientCount, id)) {
                cout << "Patient removed successfully!\n";
            } else {
                cout << "Patient with ID " << id << " not found!\n";
            }
            saveData();
        } else if (choice != 5) {
            cout << "Invalid menu choice!\n";
        }
    } while (choice != 5);
}

void doctorMenu(Doctor& doc) {
    int choice;
    string inputStr;
    do {
        cout << "\n--- Doctor Menu ---\n";
        cout << "1. Add Slot\n";
        cout << "2. Remove Slot\n";
        cout << "3. View Slots\n";
        cout << "4. View Details\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> inputStr;
        if (!isNumber(inputStr)) {
            cout << "Invalid choice!\n";
            choice = -1;
            continue;
        }
        choice = stoi(inputStr);

        if (choice == 1) {
            string time;
            cout << "Enter slot time ( 5:00pm): ";
            cin >> ws; getline(cin, time);
            if (doc.addSlot(time)) {
                cout << "Slot added successfully!\n";
            } else {
                cout << "Cannot add more slots. Maximum capacity reached.\n";
            }
            saveData();
        } else if (choice == 2) {
            string time;
            cout << "Enter slot time to remove: ";
            cin >> ws; getline(cin, time);
            if (doc.removeSlot(time)) {
                cout << "Slot removed successfully!\n";
            } else {
                cout << "Slot not found!\n";
            }
            saveData();
        } else if (choice == 3) {
            doc.displaySlots();
        } else if (choice == 4) {
            doc.getDetails();
        } else if (choice != 5) {
            cout << "Invalid menu choice!\n";
        }
    } while (choice != 5);
}

void patientMenu(Patient& pat) {
    int choice;
    string inputStr;
    do {
        cout << "\n--- Patient Menu ---\n";
        cout << "1. Search Doctors by Specialization\n";
        cout << "2. Search Doctors by Available Slot\n";
        cout << "3. Book Appointment\n";
        cout << "4. Cancel Appointment\n";
        cout << "5. View Details\n";
        cout << "6. Logout\n";
        cout << "Enter choice: ";
        cin >> inputStr;
        if (!isNumber(inputStr)) {
            cout << "Invalid choice!\n";
            choice = -1;
            continue;
        }
        choice = stoi(inputStr);

        if (choice == 1) {
            string spec;
            cout << "Enter Specialization: ";
            cin >> ws; getline(cin, spec);
            cout << "Doctors with specialization " << spec << ":\n";
            int matchCount = 0;
            for (int i = 0; i < doctorCount; i++) {
                if (doctors[i]->getSpecialization() == spec) {
                    cout << "- Dr. " << doctors[i]->getName() << " (ID: " << doctors[i]->getId() << ")\n";
                    matchCount++;
                }
            }
            if (matchCount == 0) {
                cout << "Zero doctors found.\n";
            }
        } else if (choice == 2) {
            string time;
            cout << "Enter time slot to check: ";
            cin >> ws; getline(cin, time);
            cout << "Doctors available at " << time << ":\n";
            int matchCount = 0;
            for (int i = 0; i < doctorCount; i++) {
                if (doctors[i]->hasAvailableSlot(time)) {
                    cout << "- Dr. " << doctors[i]->getName() << " (ID: " << doctors[i]->getId() << ")\n";
                    matchCount++;
                }
            }
            if (matchCount == 0) {
                cout << "Zero doctors found.\n";
            }
        } else if (choice == 3) {
            string docIdStr;
            int docId;
            string slot;
            
            while(true) {
                cout << "Enter Doctor ID (numbers only): "; cin >> docIdStr;
                if(isNumber(docIdStr)) { docId = stoi(docIdStr); break; }
                cout << "Error: ID must only contain numbers.\n";
            }
            cout << "Enter time slot: ";
            cin >> ws; getline(cin, slot);
            
            Doctor* foundDoc = nullptr;
            for (int i = 0; i < doctorCount; i++) {
                if (doctors[i]->getId() == docId) {
                    foundDoc = doctors[i];
                    break;
                }
            }
            
            if (foundDoc != nullptr && foundDoc->hasAvailableSlot(slot)) {
                Appointment* newAppt = new Appointment(appointmentCounter++, slot, foundDoc, &pat);
                if (pat.makeAppointment(newAppt)) {
                    cout << "Appointment successfully booked!\n";
                    foundDoc->removeSlot(slot);
                } else {
                    cout << "You cannot have more than 10 appointments.\n";
                    delete newAppt;
                }
                saveData();
            } else {
                cout << "Doctor not found or slot not available.\n";
            }
        } else if (choice == 4) {
            pat.cancelAppointment();
            saveData();
        } else if (choice == 5) {
            pat.getDetails();
        } else if (choice != 6) {
            cout << "Invalid menu choice!\n";
        }
    } while (choice != 6);
}

// --- Main Application Loop ---
int main() {
    loadData(); // Load previous session data
    
    // Create default Admin for login
    Admin mainAdmin(1, "admin", "admin123");

    int userType;
    string inputStr;
    do {
        cout << "\n=== Hospital Management System ===\n";
        cout << "1. Login as Admin\n";
        cout << "2. Login as Doctor\n";
        cout << "3. Login as Patient\n";
        cout << "4. Exit\n";
        cout << "Select an option: ";
        
        cin >> inputStr;
        if (!isNumber(inputStr)) {
            cout << "Invalid input.\n";
            userType = -1;
            continue;
        }
        userType = stoi(inputStr);

        if (userType == 4) break;

        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        bool loggedIn = false;

        if (userType == 1) {
            if (mainAdmin.login(username, password)) {
                cout << "Admin logged in successfully!\n";
                adminMenu(mainAdmin);
                loggedIn = true;
            }
        } else if (userType == 2) {
            for (int i = 0; i < doctorCount; i++) {
                if (doctors[i]->login(username, password)) {
                    cout << "Doctor logged in successfully!\n";
                    doctorMenu(*doctors[i]);
                    loggedIn = true;
                    break;
                }
            }
        } else if (userType == 3) {
            for (int i = 0; i < patientCount; i++) {
                if (patients[i]->login(username, password)) {
                    cout << "Patient logged in successfully!\n";
                    patientMenu(*patients[i]);
                    loggedIn = true;
                    break;
                }
            }
        } else {
            cout << "Invalid user type selected.\n";
            continue;
        }

        if (!loggedIn && userType >= 1 && userType <= 3) {
            cout << "Invalid username or password.\n";
        }

    } while (userType != 4);

    saveData(); // Save session data before exiting
    
    // Clean up memory
    for (int i = 0; i < doctorCount; i++) {
        delete doctors[i];
    }
    for (int i = 0; i < patientCount; i++) {
        delete patients[i];
    }
    
    cout << "Data saved. Exiting system.\n";
    return 0;
}
