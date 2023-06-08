#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

enum Weekday
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

class Course
{
public:
    Course() {}

    Course(std::string name, std::string teacher, Weekday weekday, int lecture)
        : name(name), teacher(teacher), weekday(weekday), lecture(lecture)
    {
        
    }

    std::string getName() const { return name; }
    std::string getTeacher() const { return teacher; }

    void setName(const std::string &newName) { name = newName; }
    void setTeacher(const std::string &newTeacher) { teacher = newTeacher; }
    std::vector<std::string> &getEnrolledStudents() { return enrolledStudents; }
    std::string getCourseCode() const { return courseCode; }
    void setCourseCode(const std::string &newCourseCode) { courseCode = newCourseCode; }
    int getStudentLimit() const { return studentLimit; }
    void setStudentLimit(int newStudentLimit) { studentLimit = newStudentLimit; }
    int getCurrentEnrollment() const { return currentEnrollment; }

    void enrollStudent(const std::string &studentId)
    {
        auto it = std::find(enrolledStudents.begin(), enrolledStudents.end(), studentId);
        if (it != enrolledStudents.end())
        {
            std::cerr << "Student is already enrolled in this course" << std::endl;
        }
        else if (currentEnrollment < studentLimit)
        {
            enrolledStudents.push_back(studentId);
            currentEnrollment++;
        }
        else
        {
            std::cerr << "Course is full" << std::endl;
        }
    }

    void dropStudent(const std::string &studentId)
    {
        auto it = std::find(enrolledStudents.begin(), enrolledStudents.end(), studentId);
        if (it != enrolledStudents.end())
        {
            enrolledStudents.erase(it);
            currentEnrollment--;
        }
        else
        {
            std::cerr << "Student is not enrolled in this course" << std::endl;
        }
    }
    Weekday getWeekday() const { return weekday; }
    int getLecture() const { return lecture; }

    void displayCourseInfo() const
    {
        std::cout << "Course Code: " << courseCode << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Teacher: " << teacher << "\n";
        std::cout << "Weekday: " << weekday << "\n";
        std::cout << "Lecture: " << lecture << "\n";
        std::cout << "Current Enrollment: " << currentEnrollment << "\n";
        std::cout << "Student Limit: " << studentLimit << "\n";
        std::cout << "-------------------\n";
    }

protected:
    std::string name;
    std::string teacher;
    std::vector<std::string> enrolledStudents;
    std::string courseCode;
    int studentLimit = 120;
    int currentEnrollment = 0;
    Weekday weekday;
    int lecture;
};

#endif