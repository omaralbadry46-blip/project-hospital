#ifndef PATIENT_H
#define PATIENT_H

#include "User.h"
#include <string>

using namespace std;

// Forward declaration
class Appointment;

class Patient : public User {
private:
    string name;
    int age;
    string gender;
    string phone;
    string medicalHistory;
    Appointment* appointments[10];
    int appointmentCount;

public:
    // Constructor
    Patient(int id, string username, string password, string name, int age, string gender, string phone, string medicalHistory);

    // Override login
    bool login(string inputUsername, string inputPassword) override;

    // Methods
    bool makeAppointment(Appointment* newAppointment);
    void cancelAppointment();
    void getDetails() const;
    void updateDetails(string newPhone, string newMedicalHistory);

    // Getters for searching and file handling
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    string getPhone() const { return phone; }
    string getMedicalHistory() const { return medicalHistory; }
    int getAppointmentCount() const { return appointmentCount; }
    Appointment* getAppointment(int index) const { 
        if(index >= 0 && index < appointmentCount) return appointments[index];
        return nullptr;
    }
};

#endif 
