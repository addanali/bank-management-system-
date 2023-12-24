#include "currentuserwithdrawdialog.h"
#include "ui_currentuserwithdrawdialog.h"
#include <currentuserloggedin.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

CurrentUserWithdrawDialog::CurrentUserWithdrawDialog(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CurrentUserWithdrawDialog)
    , m_username(username)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");
    ui->lineEditUserTransactionEng->setPlaceholderText("Amount in words");
    ui->lineEditUserTransactionNum->setPlaceholderText("Amount in numbers");
}


CurrentUserWithdrawDialog::~CurrentUserWithdrawDialog()
{
    delete ui;
}



void CurrentUserWithdrawDialog::on_pushButtonConfirmWithdraw_clicked()
{
    QString withdrawnum = ui->lineEditUserTransactionNum->text().trimmed();
    QString withdraweng = ui->lineEditUserTransactionEng->text().trimmed();

    if(withdrawnum.isEmpty() || withdraweng.isEmpty())
    {
        QMessageBox::warning(this,"Error", "Please fill all the required fields.");
        return;
    }

    bool ok;
    double withdrawalAmount = withdrawnum.toDouble(&ok);
    if(!ok || withdrawalAmount <= 0)
    {
        QMessageBox::warning(this, "Error", "Invalid withdrawal amount.");
        return;
    }

    QFile file("CUsersHPDownloadsBMSPROJzipBMSPROJ user Account Data/" + m_username + ".txt");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Unable to open user file.");
        return;
    }

    QTextStream in(&file);
    QStringList lines;
    int lineCount = 0;
    double currentBalance = 0;

    while(!in.atEnd())
    {
        QString line = in.readLine();
        lineCount++;
        if(lineCount == 4)
        {
            currentBalance = line.toDouble();
        }
        lines << line;
    }

    if(currentBalance < withdrawalAmount)
    {
        QMessageBox::warning(this, "Error", "Insufficient funds.");
        file.close();
        return;
    }

    currentBalance -= withdrawalAmount;
    lines[3] = QString::number(currentBalance);

    file.resize(0);
    QTextStream out(&file);
    foreach(const QString &line, lines)
    {
        out << line << "\n";
    }

    file.close();

    QDateTime currentDateTime = QDateTime::currentDateTime();
    logTransaction(m_username, withdrawalAmount, currentDateTime);

    QMessageBox::information(this, "Success", "Withdrawal successful.");
}

void CurrentUserWithdrawDialog::logTransaction(const QString &username, double amount, const QDateTime &dateTime)
{
    QFile logFile("CUsersHPDownloadsBMSPROJzipBMSPROJTransactionLogs/" + username + "_transactions.txt");

    if(!logFile.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Unable to open transaction log file.");
        return;
    }

    QTextStream logStream(&logFile);
    logStream << dateTime.toString("yyyy-MM-dd HH:mm:ss") << ", Withdraw of " << amount << "\n";

    logFile.close();
}

/*void CurrentUserWithdrawDialog::on_pushButtonCUWithdrawBack_clicked()
{
    hide();
    CurrentUserLoggedIn ajx;
    ajx.setModal(true);
    ajx.exec();
}*/

void CurrentUserWithdrawDialog::on_pushButtonCUWithdrawBack_clicked()
{
    close();
}

