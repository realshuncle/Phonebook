#include "phonebook.h"
#include <QApplication>
//#include <QLocale>
//#include <QTranslator>
//#include <string>
//#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "CourseworkQT_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }*/
    Phonebook w;
    w.show();
   /*QObject::connect(w.dialogNewContact, SIGNAL(newContactEntered(std::vector<std::string>)),
                         &w, SLOT(onnewContactEntered(std::vector<std::string>)));*/





    //w.
    return a.exec();
}
