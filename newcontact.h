#ifndef NEWCONTACT_H
#define NEWCONTACT_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class NewContact;
}

class NewContact : public QDialog
{
    Q_OBJECT

public:
    explicit NewContact(QWidget *parent = nullptr);
    ~NewContact();

private slots:
    void on_lePhone_editingFinished();

    void on_lePhone_selectionChanged();

    void on_buttonBox_accepted();

    void closeEvent(QCloseEvent *event);

private:
    Ui::NewContact *ui;
};

#endif // NEWCONTACT_H
