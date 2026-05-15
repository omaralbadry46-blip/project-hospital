#include "Doctor.h"
using namespace std;

// Constructor
Doctor::Doctor(int id, string username, string password, string name, string phone, string email, string specialization, int experienceYears)
    : User(id, username, password) {
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->specialization = specialization;
    this->experienceYears = experienceYears;
    this->slotCount = 0;
}

// Login
bool Doctor::login(string inputUsername, string inputPassword) {
    if (this->username == inputUsername && this->password == inputPassword) {
        return true;
    }
    return false;
}

// Add a slot
bool Doctor::addSlot(string slotTime) {
    if (slotCount < 10) {
        slots[slotCount++] = slotTime;
        return true;
    }
    return false;
}

// Remove a slot
bool Doctor::removeSlot(string slotTime) {
    for (int i = 0; i < slotCount; i++) {
        if (slots[i] == slotTime) {
            for (int j = i; j < slotCount - 1; j++) {
                slots[j] = slots[j + 1];
            }
            slotCount--;
            return true;
        }
    }
    return false;
}

// Display slots
void Doctor::displaySlots() const {
    if (slotCount == 0) {
        cout << "No slots available for Dr. " << name << ".\n";
        return;
    }
    cout << "Available slots for Dr. " << name << ":\n";
    for (int i = 0; i < slotCount; i++) {
        cout << "- " << slots[i] << "\n";
    }
}

// Print doctor details
void Doctor::getDetails() const {
    cout << "--- Doctor Details ---\n";
    cout << "ID: " << id << "\n";
    cout << "Name: Dr. " << name << "\n";
    cout << "Specialization: " << specialization << "\n";
    cout << "Experience: " << experienceYears << " years\n";
    cout << "Phone: " << phone << "\n";
    cout << "Email: " << email << "\n";
}

// Update basic details
void Doctor::updateDetails(string newPhone, string newEmail) {
    this->phone = newPhone;
    this->email = newEmail;
    cout << "Details updated successfully!\n";
}

// Check available slot
bool Doctor::hasAvailableSlot(string time) const {
    for (int i = 0; i < slotCount; i++) {
        if (slots[i] == time) {
            return true;
        }
    }
    return false;
}
