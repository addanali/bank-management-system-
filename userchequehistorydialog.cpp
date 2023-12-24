 #include "userchequehistorydialog.h"
#include "ui_userchequehistorydialog.h"
#include <currentuserloggedin.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

UserChequeHistoryDialog::UserChequeHistoryDialog(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserChequeHistoryDialog)
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

UserChequeHistoryDialog::~UserChequeHistoryDialog()
{
    delete ui;
}




void UserChequeHistoryDialog::on_pushButtonCHCheck_clicked()
{


    QFile file("C:\\Users\\Home\\Documents\\BMSPROJ\\Cheques\\" + m_username + "_cheque_history.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open file for reading.");
        return;
    }

    QTextStream in(&file);
    QString chequehistory = in.readAll();
    ui->textEditChequeHistory->setPlainText(chequehistory);

    file.close();
}

/*void UserChequeHistoryDialog::on_pushButtonUserCHBack_clicked()
{
    hide();
    CurrentUserLoggedIn adw;
    adw.setModal(true);
    adw.exec();
}*/

void UserChequeHistoryDialog::on_pushButtonUserCHBack_clicked()
{
    close();
}


