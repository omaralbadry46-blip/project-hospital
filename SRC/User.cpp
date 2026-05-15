#include "User.h"
using namespace std;

// Constructor
User::User(int id, string username, string password) {
    this->id = id;
    this->username = username;
    this->password = password;
}

// Get ID
int User::getId() const {
    return id;
}

// Get Username
string User::getUsername() const {
    return username;
}

// Get Password
string User::getPassword() const {
    return password;
}
