#include "userdialog.h"
#include "ui_userdialog.h"
#include <newuser.h>
#include <currentuser.h>
#include <startdialog.h>

UserDialog::UserDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");
}

UserDialog::~UserDialog()
{
    delete ui;
}

void UserDialog::on_NewUser_clicked()
{
    hide();
    NewUser c;
    c.setModal(true);
    c.exec();
}


void UserDialog::on_CurrentUser_clicked()
{
    hide();
    CurrentUser d;
    d.setModal(true);
    d.exec();
}


void UserDialog::on_pushButtonUserBack_clicked()
{
    hide ();
    StartDialog i;
    i.setModal(true);
    i.exec();
}

