#pragma once
#include <string>
#include <vector>

class Contact
{
    static int Amount;
    std::string Name;
    //PhoneNumber Phone;
    std::string Phone;
    std::string Information;
public:
    Contact();
    Contact(std::string name, std::string phone, std::string information);
    bool SetPhone(std::string phone);
    bool SetName(std::string name);
    static bool SetAmount(int value);
    bool SetInformation(std::string information);
    std::string GetName();
    std::string GetPhone();
    static int GetAmount();
    std::string GetInformation();
};

