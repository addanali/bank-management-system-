#include "logindialog.h"
#include "ui_logindialog.h"
#include <startdialog.h>
LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
    hide ();
    LoginDialog dl;
    dl.setModal(true);
    dl.exec();
}

