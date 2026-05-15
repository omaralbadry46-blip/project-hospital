#ifndef DOCTOR_H
#define DOCTOR_H

#include "User.h"
#include <string>
#include <iostream>

using namespace std;

class Doctor : public User {
private:
    string name;
    string phone;
    string email;
    string specialization;
    int experienceYears;
    string slots[10];
    int slotCount;

public:
    // Constructor
    Doctor(int id, string username, string password, string name, string phone, string email, string specialization, int experienceYears);

    // Override login
    bool login(string inputUsername, string inputPassword) override;

    // Methods
    bool addSlot(string slotTime);
    bool removeSlot(string slotTime);
    void displaySlots() const;
    void getDetails() const;
    void updateDetails(string newPhone, string newEmail);

    // Getters
    string getSpecialization() const { return specialization; }
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }
    int getExperienceYears() const { return experienceYears; }
    int getSlotCount() const { return slotCount; }
    string getSlot(int index) const {
        if (index >= 0 && index < slotCount) return slots[index];
        return "";
    }

    bool hasAvailableSlot(string time) const;
};

#endif 
