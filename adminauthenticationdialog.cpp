#include "adminauthenticationdialog.h"
#include "ui_adminauthenticationdialog.h"
#include <admindialog.h>
#include <startdialog.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <managerauthenticationdialog.h>

AdminAuthenticationDialog::AdminAuthenticationDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminAuthenticationDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('file:///C:/Users/HP/Downloads/WhatsApp Image 2023-12-24 at 1.56.03 PM.jpeg'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

    setWindowTitle(("Admin Login Window"));


    ui->lineEditAdminName->setPlaceholderText("User");
    ui->lineEditAdminPass->setPlaceholderText("Password");

    ui->lineEditAdminName->setClearButtonEnabled(true);
    ui->lineEditAdminPass->setClearButtonEnabled(true);


    ui->lineEditAdminPass->setEchoMode(QLineEdit::Password);

    QIcon user("C:\\Users\\Home\\Downloads\\UserIcon.png");
    QIcon pass("C:\\Users\\Home\\Downloads\\login-password-3-128.png");

    ui->lineEditAdminName->addAction(user, QLineEdit::LeadingPosition);
    ui->lineEditAdminPass->addAction(pass, QLineEdit::LeadingPosition);

}

AdminAuthenticationDialog::~AdminAuthenticationDialog()
{
    delete ui;
}

void AdminAuthenticationDialog::on_pushButtonAdminloginAuthenticate_clicked()
{
    QString adminusername = ui->lineEditAdminName->text().trimmed();
    QString adminuserpin = ui->lineEditAdminPass->text().trimmed();


    if (adminusername.isEmpty() || adminuserpin.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter both username and PIN.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJAdmin Account Data\\" +adminusername+ ".txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "User not found.");
        return;
    }

    QTextStream in(&file);
    QString adminfileUsername = in.readLine().trimmed();
    QString adminfilePin = in.readLine().trimmed();

    file.close();

    if (adminusername == adminfileUsername && adminuserpin == adminfilePin)
    {
        QMessageBox::information(this, "Admin Identified", "Welcome, " + adminusername);
        hide();
        AdminDialog e;
        e.setModal(true);
        e.exec();
    } else
    {

        QMessageBox::warning(this, "Authentication Failed", "Incorrect PIN for the provided Admin.");
    }
}



void AdminAuthenticationDialog::on_pushButtonAdminLoginBack_clicked()
{
    hide();
    StartDialog ah;
    ah.setModal(true);
    ah.exec();
}


void AdminAuthenticationDialog::on_pushButtonAdminForgotPass_clicked()
{
    hide();
    ManagerAuthenticationDialog qwe;
    qwe.setModal(true);
    qwe.exec();
}

