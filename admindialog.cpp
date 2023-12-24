#include "admindialog.h"
#include "ui_admindialog.h"
#include <adminauthenticationdialog.h>
#include <managerauthenticationdialog.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

AdminDialog::AdminDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pushButtonDeleteAcc)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('CUsersHPDownloadsWhatsApp Image 2023-12-24 at 1.56.03 PM.jpeg'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

    connect(ui->pushButtonBankAdminTransactions, &QPushButton::clicked, this, &AdminDialog::on_pushButtonBankAdminTransactions_clicked);

    ui->lineEditAdminDialogUserName->setPlaceholderText("Username");
    ui->lineEditAdminDialogUserNameCH->setPlaceholderText("Username");
    ui->lineEditAdminDialogUserNameTransactions->setPlaceholderText("Username");

}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::on_pushButtonAdminBack_clicked()
{
    hide();
    AdminAuthenticationDialog ab;
    ab.setModal(true);
    ab.exec();
}


void AdminDialog::on_pushButtonBankAdminSearch_clicked()
{
    QString username = ui->lineEditAdminDialogUserName->text().trimmed();

    if (username.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a username to search.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJUser Account Data\\" + username + ".txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "User not found.");
        return;
    }

    QTextStream in(&file);
    QString userDetails = in.readAll();
    file.close();


    ui->textEditAdmin->setText(userDetails);
}

void AdminDialog::on_pushButtonAdminSave_clicked()
{
    QString username = ui->lineEditAdminDialogUserName->text().trimmed();
    if (username.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a username.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJUser Account Data\\" + username + ".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open file for writing.");
        return;
    }

    QTextStream out(&file);
    out << ui->textEditAdmin->toPlainText();
    file.close();

    QMessageBox::information(this, "Success", "User details changed successfully.");
}




void AdminDialog::on_pushButtonAdminDeleteAcc_clicked()
{
    QString username = ui->lineEditAdminDialogUserName->text().trimmed();
    if (username.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a username.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJUser Account Data\\" + username + ".txt");
    if (file.exists())
    {
        if (!file.remove())
        {
            QMessageBox::warning(this, "Error", "Could not delete user account.");
            return;
        }
    }
    else
    {
        QMessageBox::warning(this, "Error", "User account not found.");
        return;
    }


    QMessageBox::information(this, "Success", "User account deleted successfully.");

    ui->lineEditAdminDialogUserName->clear();
    ui->textEditAdmin->clear();
}






void AdminDialog::on_pushButtonBankAdminTransactions_clicked()
{
    QString usernametransactions = ui->lineEditAdminDialogUserNameTransactions->text().trimmed();
    if (usernametransactions.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a username.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJUser Account Data\\" + usernametransactions + "_transactions.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open file for reading.");
        return;
    }

    QTextStream in(&file);
    QString transactions = in.readAll();
    ui->textEditAdminTransactions->setPlainText(transactions);

    file.close();
}



void AdminDialog::on_pushButtonBankAdminTransactionsClear_clicked()
{
    ui->textEditAdminTransactions->clear();
}


void AdminDialog::on_pushButtonBankAdminCH_clicked()
{
    QString usernamechequehistory = ui->lineEditAdminDialogUserNameCH->text().trimmed();
    if (usernamechequehistory.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a username.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJUser Account Data\\" + usernamechequehistory + "_cheque_history.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open file for reading.");
        return;
    }

    QTextStream in(&file);
    QString chequehistory = in.readAll();
    ui->textEditAdminChequeHistory->setPlainText(chequehistory);

    file.close();
}


void AdminDialog::on_pushButtonBankAdminCHClear_clicked()
{
    ui->textEditAdminChequeHistory->clear();
}


void AdminDialog::on_pushButtonManageAdmins_clicked()
{
    hide();
    ManagerAuthenticationDialog abcd;
    abcd.setModal(true);
    abcd.exec();
}

