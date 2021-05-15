#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Phonebook; }
QT_END_NAMESPACE

class Phonebook : public QMainWindow
{
    Q_OBJECT

public:
    Phonebook(QWidget *parent = nullptr);
    ~Phonebook();

private:
    Ui::Phonebook *ui;
};
#endif // PHONEBOOK_H
