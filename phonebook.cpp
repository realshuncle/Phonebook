#include "phonebook.h"
#include "IOXmlController.h"
#include "ui_phonebook.h"

Phonebook::Phonebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Phonebook)
{
    //FileController();
    ui->setupUi(this);
    Controller.OpenXml("base.contact");
    for (auto i : Controller.GetContacts())
    {
        Controller.Read()
    }
    ui->tbMain->insertRow(ui->tbMain->rowCount() + 1);
}

Phonebook::~Phonebook()
{
    delete ui;
}

void Phonebook::on_actionNew_triggered()
{
    FileController.NewXml();
}


void Phonebook::on_actionSave_triggered()
{
    FileController.SaveXml();
}

