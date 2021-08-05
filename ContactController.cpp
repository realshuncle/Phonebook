#include "ContactController.h"

ContactController::ContactController()
{
   OpenXml("base.contact");
}

bool ContactController::FindAll(std::string cond)
{
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
        if (el->FirstChild("Name")->ToElement()->GetText() != nullptr)
             contact.SetName(el->FirstChild("Name")->FirstChild()->Value());
        else
            contact.SetName("");
        if (el->FirstChild("Phone")->ToElement()->GetText() != nullptr)
             contact.SetPhone(el->FirstChild("Phone")->FirstChild()->Value());
        else
            contact.SetPhone("");
        if (el->FirstChild("Information")->ToElement()->GetText() != nullptr)
             contact.SetInformation(el->FirstChild("Information")->FirstChild()->Value());
        else
            contact.SetInformation("");
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
    TiXmlElement* root = Document.FirstChildElement();
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
    TiXmlElement* el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id)).c_str()).Element();
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
        return true;
    }
    return false;
}

bool ContactController::Edit(int id)
{
    TiXmlHandle doc(&Document);
    TiXmlElement* el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id)).c_str()).Element();
    if (el)
    {
        el->FirstChild("Name")->FirstChild()->SetValue(contact.GetName().c_str());
        el->FirstChild("Phone")->FirstChild()->SetValue(contact.GetPhone().c_str());
        el->FirstChild("Information")->FirstChild()->SetValue(contact.GetInformation().c_str());
        return true;
    }
    return false;
}
