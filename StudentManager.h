#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "User.h"
#include "StudentUser.h"
#include "CourseManager.h"

class StudentManager : public Manager
{
public:
    StudentManager() {}

    void addStudent(const std::string &name, const std::string &id, const std::string &username, const std::string &password)
    {
        if (students.find(username) != students.end())
        {
            std::cerr << "Student already exists" << std::endl;
            return;
        }

        students[username] = StudentUser(username, password, name, id);
        std::cout << "Student added successfully: " << name << std::endl;
    }

    void deleteStudent(const std::string &username)
    {
        auto it = students.find(username);
        if (it == students.end())
        {
            std::cerr << "Student does not exist" << std::endl;
            return;
        }

        students.erase(it);
        std::cout << "Student deleted successfully: " << username << std::endl;
    }

    void showAllStudents() const
    {
        for (const auto &pair : students)
        {
            std::cout << "Name: " << pair.second.getName()
                      << ", ID: " << pair.second.getId()
                      << ", Username: " << pair.second.getUsername() << std::endl;
        }
    }

    StudentUser &getStudent(const std::string &username)
    {
        if (students.find(username) == students.end())
        {
            throw std::invalid_argument("Student not found: " + username);
        }

        return students[username];
    }
    void displayMemberInfo(const std::string &username) override
    {
        auto it = students.find(username);
        if (it == students.end())
        {
            std::cout << "Student does not exist\n";
            return;
        }

        StudentUser &student = it->second;
        std::cout << "Username: " << student.getUsername() << "\n";
        std::cout << "Name: " << student.getName() << "\n";
        std::cout << "ID: " << student.getId() << "\n";
    }

    void changeMemberInfo(const std::string &username, const std::string &newPassword) override
    {
        auto it = students.find(username);
        if (it == students.end())
        {
            std::cout << "Student does not exist\n";
            return;
        }

        StudentUser &student = it->second;
        student.setPassword(newPassword);
        std::cout << "Password changed successfully for student " << username << "\n";
    }

private:
    std::map<std::string, StudentUser> students;
};

#endif 
