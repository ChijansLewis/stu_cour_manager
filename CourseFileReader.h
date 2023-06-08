#ifndef COURSEFILEREADER_H
#define COURSEFILEREADER_H

#include "Course.h"
#include "CourseManager.h"
#include <vector>
#include <fstream>
#include <sstream>

class CourseFileReader
{
public:
    void readCourses(CourseManager &manager, const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file)
        {
            throw std::runtime_error("Unable to open file");
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream ss(line);
            std::string courseCode, name, teacher;
            int studentLimit;
            std::string weekdayStr;
            int lecture;

            std::getline(ss, courseCode, ',');
            std::getline(ss, name, ',');
            std::getline(ss, teacher, ',');
            std::getline(ss, weekdayStr, ',');
            ss >> lecture >> studentLimit;

            Weekday weekday;
            if (weekdayStr == "MONDAY")
                weekday = Weekday::MONDAY;
            else if (weekdayStr == "TUESDAY")
                weekday = Weekday::TUESDAY;
            else if (weekdayStr == "WEDNESDAY")
                weekday = Weekday::WEDNESDAY;
            else if (weekdayStr == "THURSDAY")
                weekday = Weekday::THURSDAY;
            else if (weekdayStr == "FRIDAY")
                weekday = Weekday::FRIDAY;
            else if (weekdayStr == "SATURDAY")
                weekday = Weekday::SATURDAY;
            else if (weekdayStr == "SUNDAY")
                weekday = Weekday::SUNDAY;
            
            studentLimit = 100;

            manager.addCourse(courseCode, name, teacher, studentLimit, weekday, lecture);
        }
    }
};

#endif
