#include "usertransaction.h"
#include "ui_usertransaction.h"
#include <currentuserloggedin.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

UserTransaction::UserTransaction(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserTransaction)
    , m_username(username)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

}

UserTransaction::~UserTransaction()
{
    delete ui;
}



void UserTransaction::on_pushButtonCurrentUserTransactions_clicked()
{


    QFile file("C:\\Users\\Home\\Documents\\BMSPROJ\\TransactionLogs\\" + m_username + "_transactions.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open file for reading.");
        return;
    }

    QTextStream in(&file);
    QString transactions = in.readAll();
    ui->textEditTransactionHistory->setPlainText(transactions);

    file.close();
}


void UserTransaction::closeEvent(QCloseEvent *event)
{
    emit dialogClosed(m_username);
    QDialog::closeEvent(event);
}

/*void UserTransaction::on_pushButtonUserTHBack_clicked()
{
    hide();
    CurrentUserLoggedIn ad;
    ad.setModal(true);
    ad.exec();
}*/

void UserTransaction::on_pushButtonUserTHBack_clicked()
{
    close();
}
