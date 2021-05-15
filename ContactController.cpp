#include "ContactController.h"

ContactController::ContactController(IOXmlController ioxmlctrl)
{
	SetAmount(ioxmlctrl);
	for (int i = 0; i < Contact::GetAmount(); i++)
		Contacts.push_back(i);
}

bool ContactController::Sort(IOXmlController ioxmlctrl, std::string cond, bool mode)
{
	Contact temp1, temp2;
	std::string str1, str2;
	for (int i = 0; i < Contacts.size(); i++)
	{
		ioxmlctrl.Read(temp1, Contacts[i]);
		for (int j = i; j < Contacts.size(); j++) {
			ioxmlctrl.Read(temp2, Contacts[j]);
			if (cond == "Name")
			{
				str1 = temp1.GetName();
				str2 = temp2.GetName();
			}
			else if (cond == "Phone")
			{
				str1 = temp1.GetPhone();
				str2 = temp2.GetPhone();
			}
			else if (cond == "Information")
			{
				str1 = temp1.GetInformation();
				str2 = temp2.GetInformation();
			}
			else
			{
				return false;
				//TODO исключение сортировки
			}
			if (str1 > str2)
				std::swap(Contacts[i], Contacts[j]);
		}
	}
	if (mode)
		for (int i = 0; i < Contacts.size() / 2; i++)
			std::swap(Contacts[i], Contacts[Contacts.size() - i - 1]);
	/*for (int i = 0; i < Contacts.size(); i++) {

	}*/
	return true;
}

bool ContactController::FindAll(IOXmlController ioxmlctrl, std::string cond)
{
	Contact temp;
	Contacts.clear();
	for (int i = 0; i < Contact::GetAmount(); i++) {
		ioxmlctrl.Read(temp, i);
		if (temp.GetName().find(cond) != -1 ||
			temp.GetPhone().find(cond) != -1 ||
			temp.GetInformation().find(cond) != -1
			)
			Contacts.push_back(i);
	}
	return true;
}

std::vector<int> ContactController::GetContacts()
{
	return Contacts;
}

bool ContactController::UpdateAmount(int value)
{
	Contacts.push_back(Contact::GetAmount() + value);
	Contact::SetAmount(Contact::GetAmount() + value);
	return true;
}

bool ContactController::Add(IOXmlController ioxmlctrl, Contact contact)
{
	//TODO проверка на недобавление
	ioxmlctrl.Write(contact);
	UpdateAmount(1);
	return true;
}

bool ContactController::SetAmount(IOXmlController ioxmlctrl)
{
	Contact temp;
	int i = 0;
	while (ioxmlctrl.Read(temp, i))
		i++;
	Contact::SetAmount(i);
	return 1;
}