#include "IOXmlController.h"



//TODO: � ����� �������� ���������� ����� ��������
//TiXmlDocument IOXmlController::doc;

bool IOXmlController::IsOpen(TiXmlDocument doc)
{
	if (!doc.LoadFile())
		return false;
	return true;
}
bool IOXmlController::OpenXml(QString path)
{
    if (path == "")
    {
        path = QFileDialog::getOpenFileName(nullptr, "Open the file");
    }
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(nullptr, "Warning", "Cannot open file : " + file.errorString());
        return 0;
    }
    //setWindowTitle(fileName);
    if (!Document1.setContent(&file)) {
        file.close();
        return 0;
    }
    file.close();

    //if (Document.LoadFile(path.c_str()))
        //return true;
	//TODO ���������� �� ����������
    //return false;
    return 1;
}

bool IOXmlController::SaveXml()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Open the file");
    QFile file(fileName);
    //TODO: ���� ����������� ���� QFile::NewOnly, ���� �� ����������� QFile::ExistingOnly
    if(!file.open(QFile::WriteOnly))
    {
        QMessageBox::warning(nullptr, "Warning", "Cannot save file :" + file.errorString());
        return 0;
    }
    //setWindowTitle(fileName);
    QTextStream out(&file);
    Document1.save(out, 4);
    file.close();
    return 1;
    //Document.SaveFile();
    //return true;
}

bool IOXmlController::Delete(int id)
{
	TiXmlHandle doc(&Document);
	//TiXmlElement* el = doc.FirstChildElement().Element();
	TiXmlElement* el = doc.FirstChildElement().FirstChild(("ID_" + std::to_string(id)).c_str()).Element();
	//���������� ���������� ��������� ����������
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
	//���������� ���������� ��������� ����������
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
	//���������� ���������� ��������� ����������
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
	////���������� ���������� ��������� ����������
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
	//����� ��������� ��������� �� NULL
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
////TODO ���������� 
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
//	//����� ��������� ��������� �� NULL
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
//		//TODO: ���� ��� ������ ��������
//		return contact;
//		
//	}
//	//TODO: ���� �� �����
//	return Contact();
//}
//
//bool IOXmlController::WrightToXml(Contact contact)
//{
//	//����� ��������� ��������� �� NULL
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
/*
IOXmlController::IOXmlController(QString path)
{
    //TODO ���� �� ����� ���� ������
    QFile file(path);
    if (!file.open(QIODevice::ReadWrite))
        return;
    if (!Document1.setContent(&file)) {
        file.close();
        return;
    }
    file.close();
}
*/