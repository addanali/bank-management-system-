#include "currentuserdepositdialog.h"
#include "ui_currentuserdepositdialog.h"
#include <currentuserloggedin.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

CurrentUserDepositDialog::CurrentUserDepositDialog(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CurrentUserDepositDialog)
    , m_username(username)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");
    ui->lineEditUserTransactionDepositEng->setPlaceholderText("Amount in words");
    ui->lineEditUserTransactionDepositNum->setPlaceholderText("Amount in numbers");
}

CurrentUserDepositDialog::~CurrentUserDepositDialog()
{
    delete ui;
}





void CurrentUserDepositDialog::on_pushButtonConfirmDeposit_clicked()
{
    QString depositnum = ui->lineEditUserTransactionDepositNum->text().trimmed();
    QString depositeng = ui->lineEditUserTransactionDepositEng->text().trimmed();

    if(depositnum.isEmpty() || depositeng.isEmpty())
    {
        QMessageBox::warning(this,"Error", "Please fill all the required fields.");
        return;
    }

    bool ok;
    double depositAmount = depositnum.toDouble(&ok);
    if(!ok || depositAmount <= 0)
    {
        QMessageBox::warning(this, "Error", "Invalid deposit amount.");
        return;
    }

    QFile file("C:/Users/Home/Documents/BMSPROJ/User Account Data/" + m_username + ".txt");
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

    currentBalance += depositAmount;
    lines[3] = QString::number(currentBalance);

    file.resize(0);
    QTextStream out(&file);
    foreach(const QString &line, lines)
    {
        out << line << "\n";
    }

    file.close();

    QDateTime currentDateTime = QDateTime::currentDateTime();
    logTransaction(m_username, depositAmount, currentDateTime);

    QMessageBox::information(this, "Success", "Deposit successful.");
}

void CurrentUserDepositDialog::logTransaction(const QString &username, double amount, const QDateTime &dateTime)
{
    QFile logFile("CUsersHPDownloadsBMSPROJzipBMSPROJTransactionLogs/" + username + "_transactions.txt");

    if(!logFile.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Unable to open transaction log file.");
        return;
    }

    QTextStream logStream(&logFile);
    logStream << dateTime.toString("yyyy-MM-dd HH:mm:ss") << ", Deposit of " << amount << "\n";

    logFile.close();
}

/*void CurrentUserDepositDialog::on_pushButtonCUDepositBack_clicked()
{
    hide();
    CurrentUserLoggedIn ff;
    ff.setModal(true);
    ff.exec();
}*/

void CurrentUserDepositDialog::on_pushButtonCUDepositBack_clicked()
{
    close();
}
