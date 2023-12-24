#include "startdialog.h"
#include "ui_startdialog.h"
#include<adminauthenticationdialog.h>
#include <userdialog.h>
#include <QTimer>
#include <QDateTime>
#include <managerauthenticationdialog2.h>

StartDialog::StartDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartDialoglogo)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('file:///C:/Users/HP/Downloads/WhatsApp Image 2023-12-24 at 1.56.03 PM.jpeg'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();


}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_UserLogin_clicked()
{
    hide();
    UserDialog a;
    a.setModal(true);
    a.exec();
}


void StartDialog::on_ManagerLogin_clicked()
{
    hide();
    AdminAuthenticationDialog b;
    b.setModal(true);
    b.exec();
}

void StartDialog::showTime()
{

    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->DigitalClock->setText(time_text);


}



void StartDialog::on_pushButtonManagerLogin_clicked()
{
    hide();
    ManagerAuthenticationDialog2 rty;
    rty.setModal(true);
    rty.exec();
}

