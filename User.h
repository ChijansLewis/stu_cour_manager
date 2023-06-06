#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User
{
public:
    User() {}  
    User(std::string username, std::string password, std::string role)
        : username(username), password(password), role(role) {}

    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    std::string getRole() const { return role; }                                  
    void setPassword(const std::string &newPassword) { password = newPassword; }  
    virtual void displayUserInfo() {
        std::cout << "Username: " << getUsername() << ", Role: " << getRole() << std::endl;
    }

protected:
    std::string username;
    std::string password;
    std::string role;
};

#endif 
