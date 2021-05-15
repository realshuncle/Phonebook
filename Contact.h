#pragma once
#include <string>
#include <vector>
#include "PhoneNumber.h"

class Contact
{
	//����������� ����������, � ������� �������� ���������� ���������
	static int Amount;
	int Id;
	std::string Name;
	PhoneNumber Phone;
	std::string Information;
public:
	Contact();
	//TODO ����������� � Id
	Contact(std::string name, PhoneNumber phone, std::string information);
	bool SetPhone(std::string phone);
	bool SetName(std::string name);
	static bool SetAmount(int value);
	bool SetInformation(std::string information);
	std::string GetName();
	std::string GetPhone();
	static int GetAmount();
	std::string GetInformation();
};

