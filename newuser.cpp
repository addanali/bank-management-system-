#include "newuser.h"
#include "ui_newuser.h"
#include <QFile>
#include <QTextStream>
#include <userdialog.h>
#include <QMessageBox>
#include <QDir>
#include <QDebug>

NewUser::NewUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewUser)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('file:///C:/Users/HP/Downloads/WhatsApp Image 2023-12-24 at 1.56.03 PM.jpeg'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

}

NewUser::~NewUser()
{
    delete ui;
}

void NewUser::on_pushButtonNewUserBack_clicked()
{
    hide();
    UserDialog h;
    h.setModal(true);
    h.exec();
}

void NewUser::on_pushButtonNewUserCreateAcc_clicked()

{
    QString username = ui->NewUserLine->text().trimmed();
    QString pin = ui->NewUserPin->text().trimmed();
    QString accnumber = ui->NewUserAccNumberLine->text().trimmed();
    QString depositamount = ui->NewUserDepositFunds->text().trimmed();
    QString city = ui->lineEditNewUserCity->text().trimmed();
    QString cnic = ui->lineEditNewUserCNIC->text().trimmed();
    QString phone = ui->lineEditNUPhoneNumber->text().trimmed();
    QString country = ui->lineEditNewUserNationality->text().trimmed();


    if(username.isEmpty() || pin.isEmpty() || accnumber.isEmpty() || depositamount.isEmpty() || city.isEmpty() || cnic.isEmpty() || phone.isEmpty() || country.isEmpty() )
    {
        QMessageBox::warning(this, tr("Input Error"), tr("Please fill all required fields."));
        return;
    }
    else
    {
        QDir dir("CUsersHPDownloadsBMSPROJzipBMSPROJAdmin Account Data");
        if (!dir.exists())
        {
            if (!dir.mkpath("."))
            {
                QMessageBox::warning(this, tr("Error"), tr("Cannot create directory for storing user data."));
                return;
            }
        }

        QFile file(dir.filePath(username + ".txt"));

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writing: " << file.errorString();
            QMessageBox::warning(this, tr("Error"), tr("Cannot open file for writing"));
            return;
        }

        QTextStream out(&file);
        out << username << "\n";
        out << pin << "\n";
        out << accnumber << "\n";
        out << depositamount << "\n";;
        out << city << "\n";
        out << cnic << "\n";
        out << phone << "\n";
        out << country << "\n";


        file.close();

        QMessageBox::information(this, tr("Account Creation"), tr("Your account has been successfully created."));
    }
}
