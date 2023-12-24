#ifndef CURRENTUSERLOGGEDIN_H
#define CURRENTUSERLOGGEDIN_H

#include <QDialog>

namespace Ui {
class CurrentUserLoggedIn;
}

class CurrentUserLoggedIn : public QDialog
{
    Q_OBJECT



public:
    explicit CurrentUserLoggedIn(QWidget *parent = nullptr);
    ~CurrentUserLoggedIn();


    void setUsername(const QString &username);



private slots:
    void on_pushButton_clicked();

    void on_pushButtonCULTransactions_clicked();

    void on_pushButtonCULWithdraw_clicked();

    void on_pushButtonCULBalance_clicked();

    void on_pushButtonCULDeposit_clicked();

    void on_pushButtonCULCheques_clicked();

    void on_pushButtonCULChequeHistory_clicked();

private:

    Ui::CurrentUserLoggedIn *ui;

    QString m_username;


};

#endif // CURRENTUSERLOGGEDIN_H
