#include "Patient.h"
#include "Appointment.h"
#include <iostream>

using namespace std;

// Constructor
Patient::Patient(int id, string username, string password, string name, int age, string gender, string phone, string medicalHistory)
    : User(id, username, password) {
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->phone = phone;
    this->medicalHistory = medicalHistory;
    this->appointmentCount = 0;
}

// Login
bool Patient::login(string inputUsername, string inputPassword) {
    if (this->username == inputUsername && this->password == inputPassword) {
        return true;
    }
    return false;
}

// Make an appointment
bool Patient::makeAppointment(Appointment* newAppointment) {
    if (appointmentCount < 10) {
        appointments[appointmentCount++] = newAppointment;
        return true;
    }
    return false;
}

// Cancel appointment
void Patient::cancelAppointment() {
    if (appointmentCount == 0) {
        cout << "You have no appointments to cancel.\n";
        return;
    }
    
    cout << "Your current appointments:\n";
    for(int i = 0; i < appointmentCount; i++) {
        cout << i + 1 << ". ";
        appointments[i]->displayInfo();
    }
    
    int choice;
    cout << "Enter the number of the appointment to cancel (1-" << appointmentCount << "): ";
    cin >> choice;
    
    if (choice >= 1 && choice <= appointmentCount) {
        int index = choice - 1;
        for (int i = index; i < appointmentCount - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        appointmentCount--;
        cout << "Appointment canceled successfully.\n";
    } else {
        cout << "Invalid choice.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

// Get patient details
void Patient::getDetails() const {
    cout << "--- Patient Details ---\n";
    cout << "ID: " << id << "\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Gender: " << gender << "\n";
    cout << "Phone: " << phone << "\n";
    cout << "Medical History: " << medicalHistory << "\n";
    
    if (appointmentCount > 0) {
        cout << "Current Appointments:\n";
        for(int i = 0; i < appointmentCount; i++) {
            appointments[i]->displayInfo();
        }
    } else {
        cout << "Current Appointment: None\n";
    }
}

// Update details
void Patient::updateDetails(string newPhone, string newMedicalHistory) {
    this->phone = newPhone;
    this->medicalHistory = newMedicalHistory;
    cout << "Details updated successfully!\n";
}
