#ifndef TEACHERUSER_H
#define TEACHERUSER_H

#include <string>
#include <map>
#include "User.h"
#include "Course.h"

class TeacherUser : public User
{
public:
    TeacherUser() {}
    TeacherUser(std::string username, std::string password, std::string name, std::string id)
        : User(username, password, "Teacher"), name(name), id(id) {}

    std::string getName() const { return name; }
    std::string getId() const { return id; }
    const std::map<std::string, Course> &getTeachingCourses() const { return teachingCourses; }

    void addCourse(const Course &course)
    {
        teachingCourses[course.getCourseCode()] = course;
    }

    void removeCourse(const std::string &courseCode)
    {
        teachingCourses.erase(courseCode);
    }

    void displayUserInfo() override
    {
        std::cout << "Username: " << getUsername() << ", ID: " << getId() << ", Role: " << getRole() << std::endl;
        std::cout << "Teaching Courses: ";
        for (const auto &pair : teachingCourses)
        {
            std::cout << pair.first << " ";
        }
        std::cout << std::endl;
    }
    void displayTeachingCoursesDetailed() const
    {
        std::cout << "Detailed Information for Teaching Courses: \n";
        for (const auto &pair : teachingCourses)
        {
            pair.second.displayCourseInfo();
        }
    }

protected:
    std::string name;
    std::string id;
    std::map<std::string, Course> teachingCourses;
};

#endif
