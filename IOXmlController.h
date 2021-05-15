#pragma once
#include "tinystr.h"
#include "tinyxml.h"
#include "Contact.h"

 class IOXmlController
{
	bool IsOpen(TiXmlDocument doc);
	TiXmlDocument Document;
	//Contact contact;
public:
	IOXmlController(std::string path);
	//��������� ���� �� ������
	bool OpenXml(std::string path);
	//��������� ���� �� ������
	bool SaveXml();
	//������� ������� �� �����
	bool Delete(int id);
	//���������� �������
	bool Edit(int id, Contact contact);
	//���� ������� � �����
	//nt Find(std::string cond);
	//��������� ������� � �����
	bool Read(Contact &contact, int id, std::string cond = "");
	//���������� ����� ������� � ����
	bool Write(Contact contact);
	//Contact ReadFromXml(int id);
	//bool WrightToXml(Contact contact);
};

