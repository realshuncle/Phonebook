#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "tinystr.h"
#include "tinyxml.h"

class ContactController
{
    std::vector<int> Contacts;
    bool SetAmount();
    TiXmlDocument Document;
public:
    Contact contact;
    ContactController();
    bool OpenXml(std::string path);
    bool NewXml();
    bool SaveXml();
    bool Delete(int id);
    bool Edit(int id);
    bool Read(int id);
    bool Add();
    bool FindAll(std::string cond = "");
    std::vector<int> GetContacts();
};

