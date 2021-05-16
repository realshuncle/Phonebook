#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include "IOXmlController.h"
#include "ContactController.h"

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

private:
    //IOXmlController FileController;
    ContactController Controller;
    Ui::Phonebook *ui;
};
#endif // PHONEBOOK_H
