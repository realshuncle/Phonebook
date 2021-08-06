# Phonebook

The purpose of the project: to write a program "Phonebook", which will help to facilitate the storage of user phone numbers.

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
* logical - understandable interface;
* easy to use;
* precision in work.

Functional requirements:
* adding a new contact;
* deleting a contact;
* editing a contact;
* search for contacts that satisfy the search.

To implement the user interface, the Qt framework (https://www.qt.io) was used, and specifically its Qt Widjets module (https://doc.qt.io/qt-6/qtwidgets-index.html).
To work with the xml file that stores contact information, a simple, small tinyxml parser was used, which consists of six files: tinystr.h, tinyxml.h, tinystr.cpp, tinyxml.cpp, tinyxmlerror.cpp, tinyxmlparser.cpp (http://www.grinninglizard.com/tinyxml/).
