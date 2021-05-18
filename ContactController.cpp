#include "ContactController.h"

ContactController::ContactController()
{
   OpenXml("base.contact");
}
/*
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
	return true;
}*/

bool ContactController::FindAll(std::string cond)
{
    //Contact temp;
	Contacts.clear();
    for (int i = 0; i < contact.GetAmount(); i++) {
        Read(i);
        if (long(contact.GetName().find(cond)) != -1 ||
            long(contact.GetPhone().find(cond)) != -1 ||
            long(contact.GetInformation().find(cond)) != -1
			)
			Contacts.push_back(i);
	}
	return true;
}

bool ContactController::Read(int id)
{
    TiXmlHandle doc(&Document);
    TiXmlElement* el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id)).c_str()).Element();
    if (el)
    {
        contact.SetName(el->FirstChild("Name")->FirstChild()->Value());
        contact.SetPhone(el->FirstChild("Phone")->FirstChild()->Value());
        contact.SetInformation(el->FirstChild("Information")->FirstChild()->Value());
        return true;
    }
    return false;
}

std::vector<int> ContactController::GetContacts()
{
	return Contacts;
}

bool ContactController::Add()
{
    //может проверять указатель на NULL
    //TiXmlDocument doc;
    TiXmlElement* root = Document.FirstChildElement();
    //TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
    //doc.LinkEndChild(decl);
    TiXmlText* text;
    TiXmlElement* element;
    TiXmlElement* contactElement = new TiXmlElement(("ID_" + std::to_string(Contact::GetAmount())).c_str());
    root->LinkEndChild(contactElement);

    element = new TiXmlElement("Name");
    text = new TiXmlText(contact.GetName().c_str());
    element->LinkEndChild(text);
    contactElement->LinkEndChild(element);

    element = new TiXmlElement("Phone");
    text = new TiXmlText(contact.GetPhone().c_str());
    element->LinkEndChild(text);
    contactElement->LinkEndChild(element);

    element = new TiXmlElement("Information");
    text = new TiXmlText(contact.GetInformation().c_str());
    element->LinkEndChild(text);
    contactElement->LinkEndChild(element);

    Contact::SetAmount(Contact::GetAmount() + 1);
    Contacts.push_back(Contact::GetAmount());

    return true;
}

/*bool ContactController::UpdateAmount(int value)
{
	Contacts.push_back(Contact::GetAmount() + value);
	Contact::SetAmount(Contact::GetAmount() + value);
	return true;
}*/

bool ContactController::SetAmount()
{
	Contact temp;
	int i = 0;
    while (Read(i))
		i++;
	Contact::SetAmount(i);
    return true;
}

bool ContactController::OpenXml(std::string path)
{
    Contacts.clear();
    if (Document.LoadFile(path.c_str()))
    {
        SetAmount();
        for (int i = 0; i < Contact::GetAmount(); i++)
            Contacts.push_back(i);
        return true;
    }
    NewXml();
    return false;
}

bool ContactController::NewXml()
{
    Document = *new TiXmlDocument("base.contact");
    TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
    Document.LinkEndChild(decl);
    TiXmlElement* element = new TiXmlElement("Contacts");
    Document.LinkEndChild(element);
    contact.SetAmount(0);
    return true;
}

bool ContactController::SaveXml()
{
    Document.SaveFile("base.contact");
    return true;
}

bool ContactController::Delete(int id)
{
    TiXmlHandle doc(&Document);
    //TiXmlElement* el = doc.FirstChildElement().Element();
    TiXmlElement* el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id)).c_str()).Element();
    //превышение количества контактов исключение
    if (el)
    {
        doc.FirstChildElement().Element()->RemoveChild(el);
        int temp = 1;
        TiXmlElement* el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id + temp)).c_str()).Element();
        while (el)
        {
            el->SetValue(("ID_" + std::to_string(id + temp - 1)).c_str());
            temp++;
            el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id + temp)).c_str()).Element();
        }
        Contact::SetAmount(Contact::GetAmount() - 1);
        //Contacts.push_back(Contact::GetAmount());

        return true;
    }
    return false;
}

bool ContactController::Edit(int id)
{
    TiXmlHandle doc(&Document);
    TiXmlElement* el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id)).c_str()).Element();
    //превышение количества контактов исключение
    if (el)
    {
        el->FirstChild("Name")->FirstChild()->SetValue(contact.GetName().c_str());
        el->FirstChild("Phone")->FirstChild()->SetValue(contact.GetPhone().c_str());
        el->FirstChild("Information")->FirstChild()->SetValue(contact.GetInformation().c_str());
        //contact.SetPhone(el->FirstChild("Phone")->FirstChild()->Value());
        //contact.SetInformation(el->FirstChild("Information")->FirstChild()->Value());
        return true;
    }
    return false;
}
