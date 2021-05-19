#pragma once
#include <string>
#include <vector>
//#include "PhoneNumber.h"

class Contact
{
	//статическая переменная, в которой хранится количество контактов
	static int Amount;
	int Id;
	std::string Name;
    //PhoneNumber Phone;
    std::string Phone;
	std::string Information;
public:
	Contact();
    //Contact(std::string name, PhoneNumber phone, std::string information);
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

