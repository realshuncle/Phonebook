QT       += core gui xml printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Contact.cpp \
    ContactController.cpp \
    PhoneNumber.cpp \
    dialogeditcontact.cpp \
    dialognewcontact.cpp \
    main.cpp \
    phonebook.cpp \
    tinystr.cpp \
    tinyxml.cpp \
    tinyxmlerror.cpp \
    tinyxmlparser.cpp

HEADERS += \
    Contact.h \
    ContactController.h \
    PhoneNumber.h \
    dialogeditcontact.h \
    dialognewcontact.h \
    phonebook.h \
    tinystr.h \
    tinyxml.h

FORMS += \
    dialogeditcontact.ui \
    dialognewcontact.ui \
    phonebook.ui

TRANSLATIONS += \
    CourseworkQT_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
