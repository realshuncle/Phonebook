#pragma once
#include <QDomDocument>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include "tinystr.h"
#include "tinyxml.h"
#include "Contact.h"

 class IOXmlController
{
    bool IsOpen(TiXmlDocument doc);
    QDomDocument Document1;
    TiXmlDocument Document;
    //Contact contact;
public:
    IOXmlController();
    IOXmlController(QString path);
    //��������� ���� �� ������
    bool OpenXml(QString path = "");
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

