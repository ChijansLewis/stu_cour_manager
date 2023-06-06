#ifndef UI_H
#define UI_H

#include <iostream>
#include <sstream>
#include "UserManager.h"
#include "CourseManager.h"
#include "StudentManager.h"
#include "Logger.h"
#include "Course.h"
#include "TeacherUser.h"
#include "TeacherManager.h"

class UI
{
public:
    UI(UserManager &userManager, CourseManager &courseManager, StudentManager &studentManager, TeacherManager &teacherManager)
        : userManager(userManager), courseManager(courseManager), studentManager(studentManager), teacherManager(teacherManager), logger("log.txt") {}

    void start()
    {
        while (true)
        {
            std::stringstream ss;
            if (userManager.getCurrentUser() == "NO")
            {
                if (userManager.getCurrentUser() == "NO")
                {
                    std::cout << "\n---------------WELCOME-----------------" << std::endl;
                    std::cout << "1. Admin login" << std::endl;
                    std::cout << "2. Admin register" << std::endl;
                    std::cout << "3. Student login" << std::endl;
                    std::cout << "4. Student register" << std::endl;
                    std::cout << "5. Teacher login" << std::endl;
                    std::cout << "6. Teacher register" << std::endl;
                    std::cout << "7. Exit" << std::endl;
                    std::cout << "----------------------------------------" << std::endl;

                    int choice;
                    std::cin >> choice;

                    std::string username, password;
                    std::string studentName, studentId;
                    std::string teacherName, teacherId;
                    switch (choice)
                    {
                    case 1:
                        std::cout << "Enter username: " << std::endl;
                        std::cin >> username;
                        std::cout << "Enter password: " << std::endl;
                        std::cin >> password;
                        if (userManager.loginUser(username, password))
                        {
                            std::cout << "Login successful!" << std::endl;
                            ss << "Admin login successful: " << username;
                            logger.log(ss.str());
                            ss.str("");
                        }
                        else
                        {
                            std::cout << "Login failed!" << std::endl;
                            ss << "Admin login attempt failed for username: " << username;
                            logger.log(ss.str());
                            ss.str("");
                        }
                        break;
                    case 2:
                        std::cout << "Enter username: " << std::endl;
                        std::cin >> username;
                        std::cout << "Enter password: " << std::endl;
                        std::cin >> password;
                        userManager.registerUser(username, password, "Admin");
                        ss << "Admin registration successful for username: " << username;
                        logger.log(ss.str());
                        ss.str("");
                        break;
                    case 3:
                        std::cout << "Enter username: " << std::endl;
                        std::cin >> username;
                        std::cout << "Enter password: " << std::endl;
                        std::cin >> password;
                        if (userManager.loginUser(username, password))
                        {
                            std::cout << "Login successful!" << std::endl;
                            ss << "Student login successful: " << username;
                            logger.log(ss.str());
                            ss.str("");
                        }
                        else
                        {
                            std::cout << "Login failed!" << std::endl;
                            ss << "Student login attempt failed for username: " << username;
                            logger.log(ss.str());
                            ss.str("");
                        }
                        break;
                    case 4:
                        std::cout << "Enter student name: " << std::endl;
                        std::cin >> studentName;
                        std::cout << "Enter student ID: " << std::endl;
                        std::cin >> studentId;
                        std::cout << "Enter username: " << std::endl;
                        std::cin >> username;
                        std::cout << "Enter password: " << std::endl;
                        std::cin >> password;
                        userManager.registerUser(username, password, "Student");
                        studentManager.addStudent(studentName, studentId, username, password);
                        ss << "Student registration successful for username: " << username;
                        logger.log(ss.str());
                        ss.str("");
                        break;
                    case 5:
                        std::cout << "Enter username: " << std::endl;
                        std::cin >> username;
                        std::cout << "Enter password: " << std::endl;
                        std::cin >> password;
                        if (userManager.loginUser(username, password))
                        {
                            std::cout << "Login successful!" << std::endl;
                            ss << "Teacher login successful: " << username;
                            logger.log(ss.str());
                            ss.str("");
                        }
                        else
                        {
                            std::cout << "Login failed!" << std::endl;
                            ss << "Teacher login attempt failed for username: " << username;
                            logger.log(ss.str());
                            ss.str("");
                        }
                        break;

                    case 6:
                        std::cout << "Enter teacher name: " << std::endl;
                        std::cin >> teacherName;
                        std::cout << "Enter teacher ID: " << std::endl;
                        std::cin >> teacherId;
                        std::cout << "Enter username: " << std::endl;
                        std::cin >> username;
                        std::cout << "Enter password: " << std::endl;
                        std::cin >> password;
                        userManager.registerUser(username, password, "Teacher");
                        teacherManager.addTeacher(teacherName, teacherId, username, password);
                        ss << "Teacher registration successful for username: " << username;
                        logger.log(ss.str());
                        ss.str("");
                        break;

                    case 7:
                        logger.log("Exit selected");
                        std::cout << "Thank you for using the system. Goodbye!" << std::endl;
                        exit(0);

                    default:
                        ss << "Invalid choice selected: " << choice;
                        logger.log(ss.str());
                        ss.str("");
                        std::cout << "Invalid choice. Please choose again." << std::endl;
                    }
                }
            }
            else if (userManager.getCurrentRole() == "Admin")
            {
                std::cout << "\n---------------Admin-----------------" << std::endl;
                std::cout << "Welcome, " << userManager.getCurrentUser() << std::endl;
                std::cout << "1. Change password" << std::endl;
                std::cout << "2. Add course" << std::endl;
                std::cout << "3. Delete course" << std::endl;
                std::cout << "4. Show all courses" << std::endl;
                std::cout << "5. Add student" << std::endl;
                std::cout << "6. Delete student" << std::endl;
                std::cout << "7. Show all students" << std::endl;
                std::cout << "8. Enroll student in course" << std::endl;
                std::cout << "9. Drop student from course" << std::endl;
                std::cout << "10. Update course information" << std::endl;
                std::cout << "11. Add teacher" << std::endl;
                std::cout << "12. Delete teacher" << std::endl;
                std::cout << "13. Log out" << std::endl;
                std::cout << "----------------------------------------" << std::endl;

                int choice;
                int studentLimit;
                Weekday weekday;
                int lecture;
                std::string teacherName;
                TeacherUser teacherUser;
                std::cin >> choice;

                std::string username = userManager.getCurrentUser();
                std::string password;
                std::string courseName, teacher;
                std::string studentName, studentId;
                std::string courseCode, teacherId;
                Course newCourse(courseName, teacher, weekday, lecture);
                switch (choice)
                {
                case 1:
                    std::cout << "Enter new password: " << std::endl;
                    std::cin >> password;
                    userManager.changePassword(username, password);
                    ss << "Admin " << username << " changed his/her password.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 2:

                    std::cout << "Enter course name: " << std::endl;
                    std::cin >> courseName;
                    std::cout << "Enter course code: " << std::endl;
                    std::cin >> courseCode;
                    std::cout << "Enter teacher's name: " << std::endl;
                    std::cin >> teacherName;

                    try
                    {
                        teacherUser = teacherManager.getTeacher(teacherName);
                    }
                    catch (std::invalid_argument &e)
                    {
                        std::cerr << e.what() << std::endl;
                        break;
                    }

                    std::cout << "Enter student limit: " << std::endl;
                    std::cin >> studentLimit;
                    std::cout << "Enter course weekday (0 = Monday, 1 = Tuesday, ..., 6 = Sunday): " << std::endl;
                    int input;
                    std::cin >> input;
                    std::cout << "Enter course lecture (1-11): " << std::endl;
                    std::cin >> lecture;
                    if (input < 0 || input > 6)
                    {
                        std::cerr << "Invalid weekday" << std::endl;
                        break;
                    }
                    weekday = static_cast<Weekday>(input);
                    newCourse.setCourseCode(courseCode);
                    newCourse.setTeacher(teacherName);
                    newCourse.setStudentLimit(studentLimit);
                    courseManager.addCourse(courseCode, courseName, teacherName, studentLimit, weekday, lecture);
                    teacherManager.assignCourseToTeacher(teacherName, courseCode);
                    ss << "Admin " << username << " added a new course " << courseName << " taught by " << teacherName << ".";
                    logger.log(ss.str());
                    ss.str("");
                    break;

                case 3:
                    std::cout << "Enter course name: " << std::endl;
                    std::cin >> courseName;
                    courseManager.removeCourse(courseName);
                    ss << "Admin " << username << " removed the course " << courseName << ".";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 4:
                    courseManager.displayAllCourses();
                    ss << "Admin " << username << " viewed all courses.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 5:
                    std::cout << "Enter student name: " << std::endl;
                    std::cin >> studentName;
                    std::cout << "Enter student ID: " << std::endl;
                    std::cin >> studentId;
                    std::cout << "Enter username: " << std::endl;
                    std::cin >> username;
                    std::cout << "Enter password: " << std::endl;
                    std::cin >> password;
                    userManager.registerUser(username, password, "Student");
                    studentManager.addStudent(studentName, studentId, username, password);
                    ss << "Admin " << username << " added a new student " << studentName << " with ID " << studentId << ".";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 6:
                    std::cout << "Enter student username: " << std::endl;
                    std::cin >> username;
                    studentManager.deleteStudent(username);
                    ss << "Admin " << username << " deleted the student with username " << username << ".";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 7:
                    studentManager.showAllStudents();
                    ss << "Admin " << username << " viewed all students.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 8:
                    courseManager.displayAllCourses();
                    std::cout << "Enter student username: " << std::endl;
                    std::cin >> username;
                    std::cout << "Enter course code: " << std::endl;
                    std::cin >> courseCode;
                    courseName = courseCode;

                    if (courseManager.getCourse(courseCode).getCurrentEnrollment() < courseManager.getCourse(courseCode).getStudentLimit())
                    {
                        studentManager.getStudent(username).enrollInCourse(courseName, courseManager);
                        ss << "Admin " << username << " enrolled student " << username << " in the course " << courseName << ".";
                        logger.log(ss.str());
                        ss.str("");
                    }
                    else
                    {
                        std::cout << "Course is full, can't enroll." << std::endl;
                    }
                    break;
                case 9:
                    std::cout << "Enter student username: " << std::endl;
                    std::cin >> username;
                    std::cout << "Enter course code: " << std::endl;
                    std::cin >> courseCode;
                    studentManager.getStudent(username).dropCourse(courseCode, courseManager);
                    ss << "Admin " << username << " dropped student " << username << " from the course " << courseCode << ".";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 10:
                    std::cout << "This function is maintaining..." << std::endl;
                    ss << "Admin " << username << " attempted to access an under maintenance function.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 11:
                    std::cout << "Enter teacher's name: " << std::endl;
                    std::cin >> teacherName;
                    std::cout << "Enter teacher's ID: " << std::endl;
                    std::cin >> teacherId;
                    std::cout << "Enter username: " << std::endl;
                    std::cin >> username;
                    std::cout << "Enter password: " << std::endl;
                    std::cin >> password;
                    teacherManager.addTeacher(teacherName, teacherId, username, password);
                    ss << "Admin " << username << " added a new teacher " << teacherName << ".";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 12:
                    std::cout << "Enter teacher's username: " << std::endl;
                    std::cin >> username;
                    teacherManager.deleteTeacher(username);
                    ss << "Admin " << userManager.getCurrentUser() << " deleted a teacher " << username << ".";
                    logger.log(ss.str());
                    ss.str("");
                    break;

                case 13:
                    userManager.clearCurrentUser();
                    ss << "Admin " << username << " logged out.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                default:
                    std::cout << "Invalid choice. Please choose again." << std::endl;
                    ss << "Admin " << username << " made an invalid choice.";
                    logger.log(ss.str());
                    ss.str("");
                }
            }
            else if (userManager.getCurrentRole() == "Student")
            {
                std::cout << "\n---------------Student-----------------" << std::endl;
                std::cout << "Welcome, " << userManager.getCurrentUser() << std::endl;
                std::cout << "1. Change password" << std::endl;
                std::cout << "2. Enroll in course" << std::endl;
                std::cout << "3. Drop course" << std::endl;
                std::cout << "4. Show all courses" << std::endl;
                std::cout << "5. View enrolled courses" << std::endl;
                std::cout << "6. Log out" << std::endl;
                std::cout << "----------------------------------------" << std::endl;

                int choice;
                std::cin >> choice;

                std::string username = userManager.getCurrentUser();
                std::string password;
                std::string courseName;
                std::string courseCode;
                switch (choice)
                {
                case 1:
                    std::cout << "Enter new password: " << std::endl;
                    std::cin >> password;
                    userManager.changePassword(username, password);
                    ss << "Student " << username << " changed his/her password.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 2:
                    courseManager.displayAllCourses();
                    std::cout << "Enter course code: " << std::endl;
                    std::cin >> courseCode;
                    courseName = courseCode;
                    if (courseManager.getCourse(courseCode).getCurrentEnrollment() < courseManager.getCourse(courseCode).getStudentLimit())
                    {
                        studentManager.getStudent(username).enrollInCourse(courseName, courseManager);
                        ss << "Student " << username << " enrolled in the course " << courseName << ".";
                        logger.log(ss.str());
                        ss.str("");
                    }
                    else
                    {
                        std::cout << "Course is full, can't enroll." << std::endl;
                    }
                    break;

                case 3:
                    std::cout << "Enter course code: " << std::endl;
                    std::cin >> courseCode;
                    studentManager.getStudent(username).dropCourse(courseCode, courseManager);
                    ss << "Student " << username << " dropped the course " << courseCode << ".";
                    logger.log(ss.str());
                    ss.str("");
                    break;

                case 4:
                    courseManager.displayAllCourses();
                    ss << "Student " << username << " viewed all courses.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 5:
                {
                    std::cout << "You are enrolled in the following courses:" << std::endl;
                    studentManager.getStudent(username).getEnrolledCourses(courseManager);
                    ss << "Student " << username << " viewed his/her enrolled courses.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                }
                case 6:
                    userManager.clearCurrentUser();
                    ss << "Student " << username << " logged out.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                default:
                    std::cout << "Invalid choice. Please choose again." << std::endl;
                    ss << "Student " << username << " made an invalid choice.";
                    logger.log(ss.str());
                    ss.str("");
                }
            }
            else if (userManager.getCurrentRole() == "Teacher")
            {
                std::cout << "\n---------------Teacher-----------------" << std::endl;
                std::cout << "Welcome, " << userManager.getCurrentUser() << std::endl;
                std::cout << "1. Change password" << std::endl;
                std::cout << "2. Add course" << std::endl;
                std::cout << "3. Delete course" << std::endl;
                std::cout << "4. Show all courses" << std::endl;
                std::cout << "5. View teaching courses" << std::endl;
                std::cout << "6. Log out" << std::endl;
                std::cout << "----------------------------------------" << std::endl;

                int choice;
                std::cin >> choice;

                int lecture;
                Weekday weekday;
                std::string username = userManager.getCurrentUser();
                std::string password;
                std::string courseName;
                std::string courseCode;
                Course course(courseName, username, weekday, lecture);
                switch (choice)
                {
                case 1:
                    std::cout << "Enter new password: " << std::endl;
                    std::cin >> password;
                    userManager.changePassword(username, password);
                    ss << "Teacher " << username << " changed his/her password.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 2:
                    std::cout << "Enter course name: " << std::endl;
                    std::cin >> courseName;
                    std::cout << "Enter course code: " << std::endl;
                    std::cin >> courseCode;
                    std::cout << "Enter course weekday (0 = Monday, 1 = Tuesday, ..., 6 = Sunday): " << std::endl;
                    int input;
                    std::cin >> input;
                    std::cout << "Enter course lecture: " << std::endl;
                    std::cin >> lecture;
                    if (input < 0 || input > 6)
                    {
                        std::cerr << "Invalid weekday" << std::endl;
                        break;
                    }
                    weekday = static_cast<Weekday>(input);

                    teacherManager.getTeacher(username).addCourse(course);
                    ss << "Teacher " << username << " added the course " << courseName << ".";
                    logger.log(ss.str());
                    ss.str("");
                    break;

                case 3:
                    std::cout << "Enter course code: " << std::endl;
                    std::cin >> courseCode;
                    teacherManager.getTeacher(username).removeCourse(courseCode);
                    ss << "Teacher " << username << " removed the course " << courseCode << ".";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 4:
                    courseManager.displayAllCourses();
                    ss << "Teacher " << username << " viewed all courses.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 5:
                    std::cout << "You are teaching the following courses:" << std::endl;
                    teacherManager.getTeacher(username).displayTeachingCoursesDetailed();
                    ss << "Teacher " << username << " viewed his/her teaching courses.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                case 6:
                    userManager.clearCurrentUser();
                    ss << "Teacher " << username << " logged out.";
                    logger.log(ss.str());
                    ss.str("");
                    break;
                default:
                    std::cout << "Invalid choice. Please choose again." << std::endl;
                    ss << "Teacher " << username << " made an invalid choice.";
                    logger.log(ss.str());
                    ss.str("");
                }
            }
        }
    }

private:
    UserManager &userManager;
    CourseManager &courseManager;
    StudentManager &studentManager;
    TeacherManager &teacherManager;
    std::string getInput(const std::string &prompt);
    Logger logger;
};

#endif
