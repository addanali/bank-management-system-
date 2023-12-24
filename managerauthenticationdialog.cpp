#include "managerauthenticationdialog.h"
#include "ui_managerauthenticationdialog.h"
#include <managerauthenticationdialog.h>
#include <QMessageBox>
#include <admindialog.h>
#include <bankmanagerdialog.h>

ManagerAuthenticationDialog::ManagerAuthenticationDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManagerAuthenticationDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

    setWindowTitle(("Manager Login Window"));


    ui->lineEditManagerLoginName->setPlaceholderText("User");
    ui->lineEditManagerLoginPass->setPlaceholderText("Password");


    ui->lineEditManagerLoginName->setClearButtonEnabled(true);
    ui->lineEditManagerLoginPass->setClearButtonEnabled(true);


    ui->lineEditManagerLoginPass->setEchoMode(QLineEdit::Password);

    QIcon user("C:\\Users\\Home\\Downloads\\UserIcon.png");
    QIcon pass("C:\\Users\\Home\\Downloads\\login-password-3-128.png");

    ui->lineEditManagerLoginName->addAction(user, QLineEdit::LeadingPosition);
    ui->lineEditManagerLoginPass->addAction(pass, QLineEdit::LeadingPosition);

}

ManagerAuthenticationDialog::~ManagerAuthenticationDialog()
{
    delete ui;
}

void ManagerAuthenticationDialog::on_pushButtonManagerloginAuthenticate_clicked()
{

        QString ManagerName = ui->lineEditManagerLoginName->text().trimmed();
        QString ManagerPass = ui->lineEditManagerLoginPass->text().trimmed();

        if (ManagerName != "Musab Saleem" || ManagerPass != "2005")
        {
            QMessageBox::warning(this, "Invalid Input", "The Username or Password entered is incorrect.");
            return;
        }
        else
        {
            hide();
            BankManagerDialog ag;
            ag.setModal(true);
            ag.exec();
        }


}


void ManagerAuthenticationDialog::on_pushButtonManagerLoginBack_clicked()
{
    hide();
    AdminDialog aeq;
    aeq.setModal(true);
    aeq.exec();

}

