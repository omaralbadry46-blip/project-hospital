#include "Admin.h"
#include <iostream>

using namespace std;

// Constructor
Admin::Admin(int id, string username, string password) : User(id, username, password) {
}

// Login
bool Admin::login(string inputUsername, string inputPassword) {
    if (username == inputUsername && password == inputPassword) {
        return true;
    }
    return false;
}

// Add Doctor
bool Admin::addDoctor(Doctor* doctors[], int& count, int id, string user, string pass, string name, string phone, string email, string spec, int exp) {
    if (count < 100) {
        doctors[count++] = new Doctor(id, user, pass, name, phone, email, spec, exp);
        return true;
    }
    return false;
}

// Remove Doctor
bool Admin::removeDoctor(Doctor* doctors[], int& count, int id) {
    for (int i = 0; i < count; i++) {
        if (doctors[i]->getId() == id) {
            delete doctors[i];
            for (int j = i; j < count - 1; j++) {
                doctors[j] = doctors[j + 1];
            }
            count--;
            return true;
        }
    }
    return false;
}

// Add Patient
bool Admin::addPatient(Patient* patients[], int& count, int id, string user, string pass, string name, int age, string gender, string phone, string history) {
    if (count < 100) {
        patients[count++] = new Patient(id, user, pass, name, age, gender, phone, history);
        return true;
    }
    return false;
}

// Remove Patient
bool Admin::removePatient(Patient* patients[], int& count, int id) {
    for (int i = 0; i < count; i++) {
        if (patients[i]->getId() == id) {
            delete patients[i];
            for (int j = i; j < count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            count--;
            return true;
        }
    }
    return false;
}
