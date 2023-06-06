#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <map>
#include <iostream>
#include "User.h"
#include "Manager.h"

class UserManager : public Manager
{
public:
    UserManager() {}

    void registerUser(const std::string &username, const std::string &password, const std::string &role)
    {
        if (users.find(username) != users.end())
        {
            std::cerr << "User already exists" << std::endl;
            return;
        }

        users[username] = User(username, password, role);
        std::cout << "User registered successfully: " << username << std::endl;
    }

    bool loginUser(const std::string &username, const std::string &password)
    {
        auto it = users.find(username);
        if (it == users.end())
        {
            std::cerr << "User does not exist" << std::endl;
            return false;
        }

        if (it->second.getPassword() == password)
        {
            currentUser = username;
            currentRole = it->second.getRole();
            std::cout << "Login successful: " << username << std::endl;
            return true;
        }
        else
        {
            std::cerr << "Incorrect password for user " << username << std::endl;
            return false;
        }
    }

    void changePassword(const std::string &username, const std::string &newPassword)
    {
        if (currentUser.empty())
        {
            std::cerr << "No user is currently logged in. Operation not permitted." << std::endl;
            return;
        }
        auto it = users.find(username);
        if (it == users.end())
        {
            std::cerr << "User does not exist" << std::endl;
            return;
        }

        User &user = it->second;
        user.setPassword(newPassword);
        std::cout << "Password changed successfully: " << username << std::endl;
    }

    std::string getCurrentUser() const { return currentUser.empty() ? "NO" : currentUser; }
    std::string getCurrentRole() const { return currentRole.empty() ? "NO" : currentRole; }

    void clearCurrentUser()
    {
        currentUser = "";
        currentRole = "";
    }

    void displayMemberInfo(const std::string &username) override
    {
        auto it = users.find(username);
        if (it == users.end())
        {
            std::cout << "User does not exist\n";
            return;
        }

        User &user = it->second;
        std::cout << "Username: " << user.getUsername() << "\n";
        std::cout << "Role: " << user.getRole() << "\n";
    }

    void changeMemberInfo(const std::string &username, const std::string &newPassword) override
    {
        auto it = users.find(username);
        if (it == users.end())
        {
            std::cout << "User does not exist\n";
            return;
        }

        User &user = it->second;
        user.setPassword(newPassword);
        std::cout << "Password changed successfully for user " << username << "\n";
    }

    

private:
    std::map<std::string, User> users;
    std::string currentUser;
    std::string currentRole;
};

#endif 
