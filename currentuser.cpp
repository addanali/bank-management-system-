#include "currentuser.h"
#include "ui_currentuser.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <currentuserloggedin.h>
#include <userdialog.h>
#include <adminauthenticationdialog.h>

CurrentUser::CurrentUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CurrentUser)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");


    ui->lineEditCUAccPin->setEchoMode(QLineEdit::Password);

    ui->lineEditCUUsername->setClearButtonEnabled(true);
    ui->lineEditCUAccPin->setClearButtonEnabled(true);
}


CurrentUser::~CurrentUser()
{
    delete ui;
}

void CurrentUser::on_pushButtonCUAuthenticate_clicked()

{

    QString m_username = ui->lineEditCUUsername->text().trimmed();
    QString inputPin = ui->lineEditCUAccPin->text().trimmed();


    if (m_username.isEmpty() || inputPin.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter both username and PIN.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJUser Account Data\\" + m_username + ".txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "User not found.");
        return;
    }

    QTextStream in(&file);
    QString fileUsername = in.readLine().trimmed();
    QString filePin = in.readLine().trimmed();

    file.close();

    if (m_username == fileUsername && inputPin == filePin)
    {
        QMessageBox::information(this, "User Identified", "Welcome, " + m_username);

        hide();
        CurrentUserLoggedIn e;
        e.setUsername(m_username);
        e.setModal(true);
        e.exec();

        return;

    }

    else
    {

        QMessageBox::warning(this, "Authentication Failed", "Incorrect PIN for the provided username.");
    }

}


void CurrentUser::on_pushButtonCUBack_clicked()
{
    hide();
    UserDialog zx;
    zx.setModal(true);
    zx.exec();
}


void CurrentUser::on_pushButtonCUForgotPin_clicked()
{
    hide();
    AdminAuthenticationDialog you;
    you.setModal(true);
    you.exec();
}

