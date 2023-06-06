#ifndef STUDENTUSER_H
#define STUDENTUSER_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "User.h"
#include "CourseManager.h"

class StudentUser : public User
{
public:
    StudentUser() {}  
    StudentUser(std::string username, std::string password, std::string name, std::string id)
        : User(username, password, "Student"), name(name), id(id) {}

    std::string getName() const { return name; }
    std::string getId() const { return id; }
    void enrollInCourse(const std::string &courseCode, CourseManager &courseManager)
    {
        if (courseCode.empty())
        {
            std::cerr << "Course code is empty" << std::endl;
            return;
        }

        enrolledCourses.push_back(courseCode);
        courseManager.enrollStudentInCourse(courseCode, getId());
    }
    void dropCourse(const std::string &courseCode, CourseManager &courseManager)
    {
        if (courseCode.empty())
        {
            std::cerr << "Course code is empty" << std::endl;
            return;
        }

        auto it = std::find(enrolledCourses.begin(), enrolledCourses.end(), courseCode);
        if (it != enrolledCourses.end())
        {
            enrolledCourses.erase(it);
            courseManager.dropStudentFromCourse(courseCode, getId());
            std::cout << "Course dropped successfully: " << courseCode << std::endl;
        }
        else
        {
            std::cerr << "Student is not enrolled in course " << courseCode << std::endl;
        }
    }

    void getEnrolledCourses(CourseManager &courseManager) const
    {
        std::cout << "Enrolled Courses: " << std::endl;
        for (const auto &courseCode : enrolledCourses)
        {
            courseManager.displayMemberInfo(courseCode);
        }
    }

    void displayUserInfo() override {
        std::cout << "Username: " << getUsername() << ", ID: " << getId() << ", Role: " << getRole() << std::endl;
        std::cout << "Enrolled Courses: ";
        for (const auto &course : enrolledCourses)
        {
            std::cout << course << " ";
        }
        std::cout << std::endl;
    }

protected:
    std::string name;
    std::string id;
    std::vector<std::string> enrolledCourses;
};

#endif 
