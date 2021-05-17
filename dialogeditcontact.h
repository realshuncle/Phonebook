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
    //QString getTextboxText();
    ~DialogEditContact();

    void SetDate(std::vector<std::string> date);
    /*void SetPhone(std::string);
    void SetInformation();
    void SetID();*/

private slots:
    void closeEvent(QCloseEvent *event);
    //new
    void onButtonOkPressed();
    //void onTextBoxReturnPressed();
    void on_btOk_clicked();

    void on_btCancel_clicked();

private:
    std::string Id;
    Ui::DialogEditContact *ui;

signals:
    //new
    void newContactEntered(const std::vector<std::string> &con);
    //void newContactEntered(const QString &con);
    //void newTextEntered(const QString &text);
};

#endif // DIALOGNEWCONTACT_H
