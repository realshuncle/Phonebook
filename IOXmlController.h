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
	//открывает файл на запись
	bool OpenXml(std::string path);
	//открывает файл на запись
	bool SaveXml();
	//удаляет элемент из файла
	bool Delete(int id);
	//реактирует элемент
	bool Edit(int id, Contact contact);
	//ищет элемент в файле
	//nt Find(std::string cond);
	//считывает элемент с файла
	bool Read(Contact &contact, int id, std::string cond = "");
	//записывает новый элемент в файл
	bool Write(Contact contact);
	//Contact ReadFromXml(int id);
	//bool WrightToXml(Contact contact);
};

