#include "PhoneNumber.h"
//TODO �������� ������� �� ������ ������� ��������
bool PhoneNumber::IsPhone(std::string str)
{
	return true;
}

PhoneNumber::PhoneNumber()
{
	Phone = "NONE";
}
//TODO ���������� ���� �� �������
PhoneNumber::PhoneNumber(std::string phone)
{
	if (IsPhone(phone))
		Phone = phone;
}

std::string PhoneNumber::GetPhone()
{
	return Phone;
}
//TODO ����� ���� �� �������� ���������
bool PhoneNumber::SetPhone(std::string phone)
{
	if (IsPhone(phone))
	{
		Phone = phone;
		return true;
	}
	return false;
}
