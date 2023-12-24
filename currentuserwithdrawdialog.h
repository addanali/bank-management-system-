#ifndef CURRENTUSERWITHDRAWDIALOG_H
#define CURRENTUSERWITHDRAWDIALOG_H

#include <QDialog>

namespace Ui {
class CurrentUserWithdrawDialog;
}

class CurrentUserWithdrawDialog : public QDialog
{
    Q_OBJECT

public slots:
   // void handleUsername(const QString &username);

public:
    explicit CurrentUserWithdrawDialog(const QString &username, QWidget *parent = nullptr);
    ~CurrentUserWithdrawDialog();


private slots:
    void on_pushButtonCUWithdrawBack_clicked();

    void on_pushButtonConfirmWithdraw_clicked();


signals:
    void usernameSentBack(const QString &username);

private:
    Ui::CurrentUserWithdrawDialog *ui;

     QString m_username;

    void logTransaction(const QString &username, double amount, const QDateTime &dateTime);

};


#endif // CURRENTUSERWITHDRAWDIALOG_H
