#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>

class Manager
{
public:
    virtual ~Manager() {}

    virtual void displayMemberInfo(const std::string &memberId) = 0;

    virtual void changeMemberInfo(const std::string &memberId, const std::string &newInfo) = 0;
};

#endif 
