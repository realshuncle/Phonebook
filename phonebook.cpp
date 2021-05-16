#include "phonebook.h"
#include "IOXmlController.h"
#include "ui_phonebook.h"

Phonebook::Phonebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Phonebook)
{
    int rowCount = 0;
    ui->setupUi(this);
    ui->tbMain->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    for (auto i : Controller.GetContacts())
    {
        dialog = new NewContact();
        ui->tbMain->insertRow(rowCount);
        Controller.Read(i);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString::fromStdString(Controller.contact.GetName()));
        ui->tbMain->setItem(rowCount, 0, item);
        item = new QTableWidgetItem;
        item->setText(QString::fromStdString(Controller.contact.GetPhone()));
        ui->tbMain->setItem(rowCount, 1, item);
        item = new QTableWidgetItem;
        item->setText(QString::fromStdString(Controller.contact.GetInformation()));
        ui->tbMain->setItem(rowCount, 2, item);
        rowCount++;
    }

}

Phonebook::~Phonebook()
{
    delete ui;
}

void Phonebook::on_actionNew_triggered()
{
    for (int i = 0; i < ui->tbMain->rowCount(); ++i)
            ui->tbMain->removeRow(i);
    ui->tbMain->setRowCount(0);
    Controller.NewXml();
}


void Phonebook::on_actionSave_triggered()
{
    Controller.SaveXml();
}

void Phonebook::on_btSearch_clicked()
{
    Controller.FindAll(ui->leSearch->text().toStdString());
    for (int i = 0; i < ui->tbMain->rowCount(); ++i)
            ui->tbMain->removeRow(i);
    ui->tbMain->setRowCount(0);

    int rowCount = 0;
    for (auto i : Controller.GetContacts())
    {

        ui->tbMain->insertRow(rowCount);
        Controller.Read(i);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString::fromStdString(Controller.contact.GetName()));
        ui->tbMain->setItem(rowCount, 0, item);
        item = new QTableWidgetItem;
        item->setText(QString::fromStdString(Controller.contact.GetPhone()));
        ui->tbMain->setItem(rowCount, 1, item);
        item = new QTableWidgetItem;
        item->setText(QString::fromStdString(Controller.contact.GetInformation()));
        ui->tbMain->setItem(rowCount, 2, item);
        rowCount++;
    }

}

void Phonebook::on_btNew_clicked()
{
   // IOXmlController fileController("base.contact");
    dialog->show();
}

