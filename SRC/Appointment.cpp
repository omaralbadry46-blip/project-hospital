#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h" 
#include <iostream>

using namespace std;

// Constructor
Appointment::Appointment(int id, string slot, Doctor* doctor, Patient* patient) {
    this->id = id;
    this->slot = slot;
    this->doctor = doctor;
    this->patient = patient;
}

// Display details
void Appointment::displayInfo() const {
    cout << "--- Appointment Info ---\n";
    cout << "Appointment ID: " << id << "\n";
    cout << "Time Slot: " << slot << "\n";
    
    if (doctor != nullptr) {
        cout << "Doctor: Dr. " << doctor->getName() << " (" << doctor->getSpecialization() << ")\n";
    } else {
        cout << "Doctor: Not assigned\n";
    }

    if (patient != nullptr) {
        cout << "Patient: " << patient->getName() << "\n";
    } else {
        cout << "Patient: Not assigned\n";
    }
}
