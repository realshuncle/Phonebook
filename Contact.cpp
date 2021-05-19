#include "Contact.h"

int Contact::Amount = 0;

Contact::Contact()
{
	Name = "";
    Phone = "NONE";
	Information = "";
}

Contact::Contact(std::string name, std::string phone, std::string information)
{
	Name = name;
	Phone = phone;
	Information = information;
}

bool Contact::SetPhone(std::string phone)
{
    Phone = phone;
	return true;
}

bool Contact::SetName(std::string name)
{
	Name = name;
	return true;
}

bool Contact::SetAmount(int value)
{
	Amount = value;
		return true;
}

bool Contact::SetInformation(std::string information)
{
	Information = information;
	return true;
}

std::string Contact::GetName()
{
	return Name;
}

std::string Contact::GetPhone()
{
    return Phone;
}

int Contact::GetAmount()
{
	return Amount;
}

std::string Contact::GetInformation()
{
	return Information;
}


