#include "IOXmlController.h"

//TODO: в файле настроек определить место хранения
//TiXmlDocument IOXmlController::doc;

bool IOXmlController::IsOpen(TiXmlDocument doc)
{
	if (!doc.LoadFile())
		return false;
	return true;
}
bool IOXmlController::OpenXml(std::string path)
{
	if (Document.LoadFile(path.c_str()))
		return true;
	//TODO исключение на неоткрытие
    NewXml();
	return false;
}

bool IOXmlController::NewXml()
{
    Document = *new TiXmlDocument("base.contact");
    return true;
}

bool IOXmlController::SaveXml()
{
    Document.SaveFile("base.contact");
	return true;
}

bool IOXmlController::Delete(int id)
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
		return true;
	}
	return false;
}

bool IOXmlController::Edit(int id, Contact contact)
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

bool IOXmlController::Read(Contact& contact, int id, std::string cond)
{
	TiXmlHandle doc(&Document);
	TiXmlElement* el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id)).c_str()).Element();
	//превышение количества контактов исключение
	if (el)
	{
		contact.SetName(el->FirstChild("Name")->FirstChild()->Value());
		contact.SetPhone(el->FirstChild("Phone")->FirstChild()->Value());
		contact.SetInformation(el->FirstChild("Information")->FirstChild()->Value());
		return true;
	}
	return false;
	
	//TiXmlHandle doc(&Document);
	//TiXmlElement* el;
	////превышение количества контактов исключение
	//if (id > contact.GetAmount())
	//	return false;
	//else
	//{
	//	el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id)).c_str()).Element();
	//	contact.SetName(el->FirstChild("Name")->FirstChild()->Value());
	//	contact.SetPhone(el->FirstChild("Phone")->FirstChild()->Value());
	//	contact.SetInformation(el->FirstChild("Information")->FirstChild()->Value());
	//}
	//return true;
}

bool IOXmlController::Write(Contact contact)
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
	
	//SaveXml();
	/*Document.SaveFile("base.xml");
	Document.Clear();
	Document.LoadFile("base.xml");*/
	//Document.LoadFile("base.xml");


	return true;
}
//
////TODO исключения 
//void IOXmlController::SetAmount()
//{
//	/*TiXmlDocument doc1;
//	doc1.LoadFile("base.xml");*/
//	TiXmlHandle doc(&Doc);
//	TiXmlElement* el;
//
//	if (IsOpen(Doc)) {
//		std::string a = "ID_" + std::to_string(Contact::GetAmount());
//		el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(Contact::GetAmount())).c_str()).Element();
//		while (el) {
//			Contact::SetAmount(Contact::GetAmount() + 1);
//			el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(Contact::GetAmount())).c_str()).Element();
//		}
//	}
//}
//
//Contact IOXmlController::ReadFromXml(int id)
//{
//	Contact contact;
//	//может проверять указатель на NULL
//	TiXmlHandle doc(&Doc);
//	TiXmlElement* el;
//	if (IsOpen(Doc)) 
//	{
//		el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id)).c_str()).Element();
//		if (el) {
//			contact.SetName(el->FirstChild("Name")->FirstChild()->Value());
//			contact.SetPhone(el->FirstChild("Phone")->FirstChild()->Value());
//			contact.SetInformation(el->FirstChild("Information")->FirstChild()->Value());
//		}
//		//TODO: если нет такого контакта
//		return contact;
//		
//	}
//	//TODO: если не файла
//	return Contact();
//}
//
//bool IOXmlController::WrightToXml(Contact contact)
//{
//	//может проверять указатель на NULL
//	//TiXmlDocument doc;
//	TiXmlElement* root = Doc.FirstChildElement();
//	//TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
//	//doc.LinkEndChild(decl);
//	TiXmlText* text;
//	TiXmlElement* element;
//	TiXmlElement* contactElement = new TiXmlElement(("ID_" + std::to_string(Contact::GetAmount())).c_str());
//	root->LinkEndChild(contactElement);
//
//	element = new TiXmlElement("Name");
//	text = new TiXmlText(contact.GetName().c_str());
//	element->LinkEndChild(text);
//	contactElement->LinkEndChild(element);
//
//	element = new TiXmlElement("Phone");
//	text = new TiXmlText(contact.GetPhone().c_str());
//	element->LinkEndChild(text);
//	contactElement->LinkEndChild(element);
//
//	element = new TiXmlElement("Information");
//	text = new TiXmlText(contact.GetInformation().c_str());
//	element->LinkEndChild(text);
//	contactElement->LinkEndChild(element);
//
//	Contact::SetAmount(Contact::GetAmount() + 1);
//
//	return true;
//}
IOXmlController::IOXmlController()
{
    //TODO если не может быть открыт
    Document.LoadFile("base.contact");
}
IOXmlController::IOXmlController(std::string path)
{
	//TODO если не может быть открыт
	Document.LoadFile(path.c_str());
}
