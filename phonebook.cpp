#include "phonebook.h"
#include "ui_phonebook.h"

Phonebook::Phonebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Phonebook)
{
    ui->setupUi(this);
}

Phonebook::~Phonebook()
{
    delete ui;
}

