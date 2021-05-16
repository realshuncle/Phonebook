#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "tinystr.h"
#include "tinyxml.h"
//#include "IOXmlController.h"

class ContactController
{
    //функция задает количество контактов
    std::vector<int> Contacts;
    bool SetAmount();
    bool IsOpen(TiXmlDocument doc);
    TiXmlDocument Document;
    //Contact contact;
public:
    //конструктор контроллера
    ContactController();
    //открывает файл на запись
    bool OpenXml(std::string path);
    //создает новый файл
    bool NewXml();
    //открывает файл на запись
    bool SaveXml();
    //удаляет элемент из файла
    bool Delete(int id);
    //реактирует элемент
    bool Edit(int id, Contact contact);
    //считывает элемент с файла
    bool Read(Contact &contact, int id);
    //функция добавляет контакт
    bool Add(Contact contact);
	//функция сортировки
    //bool Sort(IOXmlController ioxmlctrl, std::string cond, bool mode = 0);
	//функция отбирает контакты удовлетворяющие условию
    bool FindAll(std::string cond = "");
	//функция возвращающая список id выбраннных контактов
	std::vector<int> GetContacts();
	//функция обновляет количество контактов
    //bool UpdateAmount(int value);
};

