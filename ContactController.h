#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "tinystr.h"
#include "tinyxml.h"
//#include "IOXmlController.h"

class ContactController
{
    //������� ������ ���������� ���������
    std::vector<int> Contacts;
    bool SetAmount();
    bool IsOpen(TiXmlDocument doc);
    TiXmlDocument Document;
    //Contact contact;
public:
    //����������� �����������
    ContactController();
    //��������� ���� �� ������
    bool OpenXml(std::string path);
    //������� ����� ����
    bool NewXml();
    //��������� ���� �� ������
    bool SaveXml();
    //������� ������� �� �����
    bool Delete(int id);
    //���������� �������
    bool Edit(int id, Contact contact);
    //��������� ������� � �����
    bool Read(Contact &contact, int id);
    //������� ��������� �������
    bool Add(Contact contact);
	//������� ����������
    //bool Sort(IOXmlController ioxmlctrl, std::string cond, bool mode = 0);
	//������� �������� �������� ��������������� �������
    bool FindAll(std::string cond = "");
	//������� ������������ ������ id ���������� ���������
	std::vector<int> GetContacts();
	//������� ��������� ���������� ���������
    //bool UpdateAmount(int value);
};

