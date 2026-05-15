#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Doctor.h"
#include "Patient.h"
#include <string>

using namespace std;

class Admin : public User {
public:
    // Constructor
    Admin(int id, string username, string password);

    // Override login
    bool login(string inputUsername, string inputPassword) override;

    // Methods
    bool addDoctor(Doctor* doctors[], int& count, int id, string user, string pass, string name, string phone, string email, string spec, int exp);
    bool removeDoctor(Doctor* doctors[], int& count, int id);
    
    bool addPatient(Patient* patients[], int& count, int id, string user, string pass, string name, int age, string gender, string phone, string history);
    bool removePatient(Patient* patients[], int& count, int id);
};

#endif 