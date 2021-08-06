# Phonebook

The purpose of the project: writing a program "Phonebook", which will help to facilitate the storage of user phone numbers.

The task:
It is necessary to create a program "Phonebook".
Contact details contain:
* contact name;
*	telephone;
* additional information about the contact.
The program must provide menu-driven selection and the following functions:
* adding data about a new contact;
* editing data of an existing contact;
* deleting contact data;
* issuing of information about all contacts;
* issuing information about contacts that satisfy the search.

Basic requirements for the project:
1. logical - understandable interface;
2. easy to use;
3. precision in work.

Functional requirements:
1. adding a new contact;
2. deleting a contact;
3. editing a contact;
4. search for contacts that satisfy the search.

To implement the user interface, the Qt framework (https://www.qt.io) was used, and specifically its Qt Widjets module (https://doc.qt.io/qt-6/qtwidgets-index.html).
To work with the xml file that stores contact information, a simple, small tinyxml parser was used, which consists of six files: tinystr.h, tinyxml.h, tinystr.cpp, tinyxml.cpp, tinyxmlerror.cpp, tinyxmlparser.cpp (http://www.grinninglizard.com/tinyxml/).
