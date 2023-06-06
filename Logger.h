#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <chrono>
#include <ctime>

class Logger
{
public:
    Logger(const std::string &filename)
        : logFile(filename, std::ofstream::out | std::ofstream::app)
    {
        if (!logFile)
        {
            throw std::runtime_error("Unable to open log file");
        }
    }

    ~Logger()
    {
        if (logFile)
        {
            logFile.close();
        }
    }

    void log(const std::string &message)
    {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        logFile << std::ctime(&now_time) << ": " << message << std::endl;
    }

private:
    std::ofstream logFile;
};

#endif
