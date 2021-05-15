#pragma once
#include <string>

class PhoneNumber
{
	std::string Phone;
	bool IsPhone(std::string str);
public:
	PhoneNumber();
	PhoneNumber(std::string phone);
	std::string GetPhone();
	bool SetPhone(std::string phone);
};

