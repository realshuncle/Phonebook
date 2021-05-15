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

private slots:
    void on_actionCreate_triggered();

    void on_actionOpen_triggered();

private:
    Ui::Phonebook *ui;
};
#endif // PHONEBOOK_H
