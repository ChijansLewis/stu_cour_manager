#ifndef TEACHERMANAGER_H
#define TEACHERMANAGER_H

#include <map>
#include <iostream>
#include "Manager.h"
#include "TeacherUser.h"
#include "Course.h"
#include "CourseManager.h"

class TeacherManager : public Manager
{
public:
    
    TeacherManager(CourseManager& courseManager) : courseManager(courseManager) {}

    void addTeacher(const std::string &name, const std::string &id, const std::string &username, const std::string &password)
    {
        if (teachers.find(username) != teachers.end())
        {
            std::cerr << "Teacher already exists" << std::endl;
            return;
        }

        teachers[username] = TeacherUser(username, password, name, id);
        std::cout << "Teacher added successfully: " << name << std::endl;
    }

    void deleteTeacher(const std::string &username)
    {
        auto it = teachers.find(username);
        if (it == teachers.end())
        {
            std::cerr << "Teacher does not exist" << std::endl;
            return;
        }

        teachers.erase(it);
        std::cout << "Teacher deleted successfully: " << username << std::endl;
    }

    void showAllTeachers() const
    {
        for (const auto &pair : teachers)
        {
            std::cout << "Name: " << pair.second.getName()
                      << ", ID: " << pair.second.getId()
                      << ", Username: " << pair.second.getUsername() << std::endl;
        }
    }

    TeacherUser &getTeacher(const std::string &username)
    {
        if (teachers.find(username) == teachers.end())
        {
            throw std::invalid_argument("Teacher not found: " + username);
        }

        return teachers[username];
    }

        void assignCourseToTeacher(const std::string &username, const std::string &courseCode)
    {
        if (teachers.find(username) == teachers.end())
        {
            std::cerr << "Teacher not found: " << username << std::endl;
            return;
        }

        Course &course = courseManager.getCourse(courseCode);
        if (course.getName().empty())
        {
            std::cerr << "Course not found: " << courseCode << std::endl;
            return;
        }

        teachers[username].addCourse(course);
        course.setTeacher(username);

        std::cout << "Course " << courseCode << " assigned to teacher: " << username << std::endl;
    }

    void displayTeachingCourses(const std::string &username)
    {
        if (teachers.find(username) == teachers.end())
        {
            std::cerr << "Teacher not found: " << username << std::endl;
            return;
        }

        const auto &courses = teachers[username].getTeachingCourses();
        std::cout << "Teaching courses for " << username << ": ";
        for (const auto &course : courses)
        {
            std::cout << course.second.getName() << " ";
        }
        std::cout << std::endl;
    }

    void displayMemberInfo(const std::string &username) override
    {
        auto it = teachers.find(username);
        if (it == teachers.end())
        {
            std::cout << "Teacher does not exist\n";
            return;
        }

        TeacherUser &teacher = it->second;
        std::cout << "Username: " << teacher.getUsername() << "\n";
        std::cout << "Name: " << teacher.getName() << "\n";
        std::cout << "ID: " << teacher.getId() << "\n";
    }
    void changeMemberInfo(const std::string &username, const std::string &newPassword) override
{
    auto it = teachers.find(username);
    if (it == teachers.end())
    {
        std::cout << "Teacher does not exist\n";
        return;
    }

    TeacherUser &teacher = it->second;
    teacher.setPassword(newPassword);
    std::cout << "Password changed successfully for teacher " << username << "\n";
}

private:
    std::map<std::string, TeacherUser> teachers;
    CourseManager& courseManager;
};

#endif
