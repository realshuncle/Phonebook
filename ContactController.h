#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "IOXmlController.h"

class ContactController
{
	//������� ������ ���������� ���������
	bool SetAmount(IOXmlController ioxmlctrl);
	std::vector<int> Contacts;
	//Contact contact;
public:
	//����������� �����������
	ContactController(IOXmlController ioxmlctrl);
	//������� ����������
	bool Sort(IOXmlController ioxmlctrl, std::string cond, bool mode = 0);
	//������� �������� �������� ��������������� �������
	bool FindAll(IOXmlController ioxmlctrl, std::string cond = "");
	//������� ������������ ������ id ���������� ���������
	std::vector<int> GetContacts();
	//������� ��������� ���������� ���������
	bool UpdateAmount(int value);
	//������� ��������� �������
	bool Add(IOXmlController ioxmlctrl, Contact contact);
};

