#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H

#include <string>
#include <map>
#include <iostream>
#include <stdexcept>
#include "Course.h"
#include "Manager.h"

class CourseManager : public Manager
{
public:
    CourseManager() {}

    void addCourse(const std::string &courseCode, const std::string &name, const std::string &teacher, int studentLimit, Weekday weekday, int lecture)
    {
        if (courses.find(courseCode) != courses.end())
        {
            std::cerr << "Course already exists" << std::endl;
            return;
        }

        Course course(name, teacher, weekday, lecture);
        course.setCourseCode(courseCode);
        course.setStudentLimit(studentLimit);
        courses[courseCode] = course;
    }

    void removeCourse(const std::string &courseCode)
    {
        auto it = courses.find(courseCode);
        if (it == courses.end())
        {
            std::cerr << "Course does not exist" << std::endl;
            return;
        }

        courses.erase(it);
        std::cout << "Course removed successfully: " << courseCode << std::endl;
    }

    void displayAllCourses()
    {
        std::cout << "All courses:" << std::endl;
        for (const auto &course : courses)
        {
            displayMemberInfo(course.first);
        }
    }

    void enrollStudentInCourse(const std::string &courseCode, const std::string &studentId)
    {
        auto it = courses.find(courseCode);
        if (it != courses.end())
        {
            it->second.enrollStudent(studentId);
            std::cout << "Student enrolled in course successfully: " << courseCode << std::endl;
        }
        else
        {
            std::cerr << "Course does not exist" << std::endl;
        }
    }

    void dropStudentFromCourse(const std::string &courseCode, const std::string &studentId)
    {
        auto it = courses.find(courseCode);
        if (it != courses.end())
        {
            it->second.dropStudent(studentId);
            std::cout << "Student dropped from course successfully: " << courseCode << std::endl;
        }
        else
        {
            std::cerr << "Course does not exist" << std::endl;
        }
    }

    void updateCourseInfo(const std::string &courseCode, const std::string &newName, const std::string &newTeacher)
    {
        auto it = courses.find(courseCode);
        if (it != courses.end())
        {
            Course &course = it->second;
            course.setName(newName);
            course.setTeacher(newTeacher);
            std::cout << "Course info updated successfully: " << newName << std::endl;
        }
        else
        {
            std::cerr << "Course does not exist" << std::endl;
        }
    }

    void displayMemberInfo(const std::string &courseCode) override
    {
        auto it = courses.find(courseCode);
        if (it == courses.end())
        {
            std::cout << "Course does not exist\n";
            return;
        }

        Course &course = it->second;
        std::cout << "Course Code: " << course.getCourseCode() << "\n";
        std::cout << "Name: " << course.getName() << "\n";
        std::cout << "Teacher: " << course.getTeacher() << "\n";
        std::cout << "Weekday: ";
        switch (course.getWeekday())
        {
        case Weekday::MONDAY:
            std::cout << "Monday";
            break;
        case Weekday::TUESDAY:
            std::cout << "Tuesday";
            break;
        case Weekday::WEDNESDAY:
            std::cout << "Wednesday";
            break;
        case Weekday::THURSDAY:
            std::cout << "Thursday";
            break;
        case Weekday::FRIDAY:
            std::cout << "Friday";
            break;
        case Weekday::SATURDAY:
            std::cout << "Saturday";
            break;
        case Weekday::SUNDAY:
            std::cout << "Sunday";
            break;
        }
        std::cout << "\n";
        std::cout << "Lecture: " << course.getLecture() << "\n";
    }

    Course &getCourse(const std::string &courseCode)
    {
        if (courses.find(courseCode) == courses.end())
        {
            throw std::invalid_argument("Course does not exist");
        }

        return courses[courseCode];
    }

    void changeMemberInfo(const std::string &courseCode, const std::string &newTeacher) override
    {
        auto it = courses.find(courseCode);
        if (it == courses.end())
        {
            std::cout << "Course does not exist\n";
            return;
        }

        Course &course = it->second;
        course.setTeacher(newTeacher);
        std::cout << "Teacher changed successfully for course " << courseCode << "\n";
    }

private:
    std::map<std::string, Course> courses;
};

#endif
