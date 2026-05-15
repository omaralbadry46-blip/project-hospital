#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

using namespace std;

// Forward declarations
class Doctor;
class Patient;

class Appointment {
private:
    int id;
    string slot;
    Doctor* doctor;
    Patient* patient;

public:
    // Constructor
    Appointment(int id, string slot, Doctor* doctor, Patient* patient);

    // Method to display information
    void displayInfo() const;

    // Getters
    int getId() const { return id; }
    string getSlot() const { return slot; }
    Doctor* getDoctor() const { return doctor; }
    Patient* getPatient() const { return patient; }
};

#endif 
