#include "PhoneNumber.h"
//TODO проверка яляется ли строка номером телефона
bool PhoneNumber::IsPhone(std::string str)
{
	return true;
}

PhoneNumber::PhoneNumber()
{
	Phone = "NONE";
}
//TODO исключение если не телефон
PhoneNumber::PhoneNumber(std::string phone)
{
	if (IsPhone(phone))
		Phone = phone;
}

std::string PhoneNumber::GetPhone()
{
	return Phone;
}
//TODO также если не является телефоном
bool PhoneNumber::SetPhone(std::string phone)
{
	if (IsPhone(phone))
	{
		Phone = phone;
		return true;
	}
	return false;
}
