#include "bankmanagerdialog.h"
#include "ui_bankmanagerdialog.h"
#include <admindialog.h>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfoList>

BankManagerDialog::BankManagerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BankManagerDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/HP/Downloads/WhatsApp Image 2023-12-24 at 1.56.03 PM.jpeg'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");
    ui->lineEditManagerUsernameEdit->setPlaceholderText("Enter Admin Name");
}

BankManagerDialog::~BankManagerDialog()
{
    delete ui;
}

void BankManagerDialog::on_pushButtonBankManagerDialog_clicked()
{
    hide();
    AdminDialog afr;
    afr.setModal(true);
    afr.exec();
}


void BankManagerDialog::on_pushButtonManagerAddAcc_clicked()
{
    QString adminname = ui->lineEditManagerAddAdminName->text().trimmed();
    QString adminpin = ui->lineEditManagerAddAdminPin->text().trimmed();



    if(adminname.isEmpty() || adminpin.isEmpty() )
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

        QFile file(dir.filePath(adminname + ".txt"));

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writing: " << file.errorString();
            QMessageBox::warning(this, tr("Error"), tr("Cannot open file for writing"));
            return;
        }

        QTextStream out(&file);
        out << adminname << "\n";
        out << adminpin << "\n";



        file.close();

        QMessageBox::information(this, tr("Account Creation"), tr("Admin account has been successfully created."));
    }
}


void BankManagerDialog::on_pushButtonManagerViewAcc_clicked()
{
    QDir directory ("CUsersHPDownloadsBMSPROJzipBMSPROJAdmin Account Data");
    QStringList files = directory.entryList(QDir::Files); // List all files

    QString fileList;
    foreach (QString file, files) {
        QFileInfo fileInfo(directory.filePath(file)); // Create QFileInfo object with full file path
        QString fileNameWithoutExtension = fileInfo.baseName(); // Get the name without the extension
        fileList += fileNameWithoutExtension + "\n"; // Append each filename to the string
    }

    ui->textEditManagerViewAcc->setText(fileList); // Display the filenames in the text edit
}




void BankManagerDialog::on_pushButtonManagerRemoveAcc_clicked()
{
    QString removeaccusername = ui->lineEditManagerRemoveAdmin->text().trimmed();
    if (removeaccusername.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a username.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJAdminAccountData\\" + removeaccusername + ".txt");
    if (file.exists())
    {
        if (!file.remove())
        {
            QMessageBox::warning(this, "Error", "Could not delete Admin account.");
            return;
        }
    }
    else
    {
        QMessageBox::warning(this, "Error", "Admin account not found.");
        return;
    }


    QMessageBox::information(this, "Success", "Admin account deleted successfully.");

    ui->lineEditManagerRemoveAdmin->clear();

}


void BankManagerDialog::on_pushButtonManagerSearch_clicked()
{
    QString username = ui->lineEditManagerUsernameEdit->text().trimmed();

    if (username.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a username to search.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJAdmin Account Data\\" + username + ".txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "User not found.");
        return;
    }

    QTextStream in(&file);
    QString AdminDetails = in.readAll();
    file.close();


    ui->textEditManagerViewAcc_2->setText(AdminDetails);
}


void BankManagerDialog::on_pushButtonManagerEditAcc_clicked()
{
    QString Editusername = ui->lineEditManagerUsernameEdit->text().trimmed();
    if (Editusername.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a username.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJAdmin Account Data\\" + Editusername + ".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open file for writing.");
        return;
    }

    QTextStream out(&file);
    out << ui->textEditManagerViewAcc_2->toPlainText();
    file.close();
    ui->textEditManagerViewAcc_2->clear();
    QMessageBox::information(this, "Success", "Admin details changed successfully.");
}

