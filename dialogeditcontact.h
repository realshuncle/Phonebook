#ifndef DIALOGEDITCONTACT_H
#define DIALOGEDITCONTACT_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class DialogEditContact;
}

class DialogEditContact : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditContact(QWidget *parent = nullptr);
    ~DialogEditContact();

    void SetDate(std::vector<std::string> date);

private slots:
    void closeEvent(QCloseEvent *event);
    void onButtonOkPressed();
    void onButtonDeletePressed();
    void on_btOk_clicked();
    void on_btCancel_clicked();
    void on_btDelete_clicked();

private:
    std::string Id;

    Ui::DialogEditContact *ui;

signals:
    void editContactEntered(const std::vector<std::string> &con);

    void deleteContactEntered(int id);
};

#endif // DIALOGEDITCONTACT_H
