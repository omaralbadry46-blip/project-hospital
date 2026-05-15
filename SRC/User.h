#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

// Abstract class User
class User {
protected:
    int id;
    string username;
    string password;

public:
    // Constructor
    User(int id, string username, string password);
    
    // Virtual destructor is important for abstract classes
    virtual ~User() {}

    // Pure virtual function makes this an abstract class
    virtual bool login(string inputUsername, string inputPassword) = 0;

    // Getters
    int getId() const;
    string getUsername() const;
    string getPassword() const;
};

#endif
