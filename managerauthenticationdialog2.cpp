#include "managerauthenticationdialog2.h"
#include "ui_managerauthenticationdialog2.h"
#include <QMessageBox>
#include <startdialog.h>
#include <bankmanagerdialog.h>

ManagerAuthenticationDialog2::ManagerAuthenticationDialog2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManagerAuthenticationDialog2)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

    setWindowTitle(("Manager Login Window"));


    ui->lineEditManagerLoginName2->setPlaceholderText("User");
    ui->lineEditManagerLoginPass2->setPlaceholderText("Password");


    ui->lineEditManagerLoginName2->setClearButtonEnabled(true);
    ui->lineEditManagerLoginPass2->setClearButtonEnabled(true);


    ui->lineEditManagerLoginPass2->setEchoMode(QLineEdit::Password);

    QIcon user("C:\\Users\\Home\\Downloads\\UserIcon.png");
    QIcon pass("C:\\Users\\Home\\Downloads\\login-password-3-128.png");

    ui->lineEditManagerLoginName2->addAction(user, QLineEdit::LeadingPosition);
    ui->lineEditManagerLoginPass2->addAction(pass, QLineEdit::LeadingPosition);

}

ManagerAuthenticationDialog2::~ManagerAuthenticationDialog2()
{
    delete ui;
}

void ManagerAuthenticationDialog2::on_pushButtonManagerloginAuthenticate2_clicked()
{

    QString ManagerName = ui->lineEditManagerLoginName2->text().trimmed();
    QString ManagerPass = ui->lineEditManagerLoginPass2->text().trimmed();

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


void ManagerAuthenticationDialog2::on_pushButtonManagerLoginBack2_clicked()
{
    hide();
    StartDialog aeq;
    aeq.setModal(true);
    aeq.exec();

}

