#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
//#include "IOXmlController.h"
#include "ContactController.h"
#include "dialogeditcontact.h"
#include "dialognewcontact.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Phonebook; }
QT_END_NAMESPACE

class Phonebook : public QMainWindow
{
    Q_OBJECT

public:
    Phonebook(QWidget *parent = nullptr);
    ~Phonebook();

private slots:

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_btSearch_clicked();

    void on_btNew_clicked();

    void onnewContactEntered(const std::vector<std::string> &con);

    void oneditContact(const std::vector<std::string> &con);

    void ondeleteContact(int id);

    //void onnewContactEntered(const QString &con);

    void on_btEdit_clicked();

    void on_tbMain_cellDoubleClicked(int row, int column);

private:
    //IOXmlController FileController;
    ContactController Controller;
    Ui::Phonebook *ui;
    DialogNewContact *dialogNewContact;
    DialogEditContact *dialogEditContact;
};
#endif // PHONEBOOK_H
