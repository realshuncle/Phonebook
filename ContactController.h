#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "IOXmlController.h"

class ContactController
{
	//функци€ задает количество контактов
	bool SetAmount(IOXmlController ioxmlctrl);
	std::vector<int> Contacts;
	//Contact contact;
public:
	//конструктор контроллера
	ContactController(IOXmlController ioxmlctrl);
	//функци€ сортировки
	bool Sort(IOXmlController ioxmlctrl, std::string cond, bool mode = 0);
	//функци€ отбирает контакты удовлетвор€ющие условию
	bool FindAll(IOXmlController ioxmlctrl, std::string cond = "");
	//функци€ возвращающа€ список id выбраннных контактов
	std::vector<int> GetContacts();
	//функци€ обновл€ет количество контактов
	bool UpdateAmount(int value);
	//функци€ добавл€ет контакт
	bool Add(IOXmlController ioxmlctrl, Contact contact);
};

