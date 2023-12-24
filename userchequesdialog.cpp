#include "userchequesdialog.h"
#include "ui_userchequesdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <currentuserloggedin.h>

UserChequesDialog::UserChequesDialog(const QString &username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserChequesDialog),
    m_username(username)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

     ui->lineEditChequeAmount->setPlaceholderText("Amount In Numbers");
     ui->lineEditChequeAmountEng->setPlaceholderText("Amount In Words");

}
UserChequesDialog::~UserChequesDialog()
{
    delete ui;
}

void UserChequesDialog::on_pushButtonSaveCheque_clicked()
{
    double amount = ui->lineEditChequeAmount->text().toDouble();
    QDateTime currentDateTime = QDateTime::currentDateTime();
    int leafNumber = getNextLeafNumber();

    saveCheque(leafNumber, amount, currentDateTime);
}

int UserChequesDialog::getNextLeafNumber()
{
    QFile file("C:\\Users\\Home\\Documents\\BMSPROJ\\Cheques\\" + m_username + "_cheque_history.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 1;  // Start from 1 if the file doesn't exist or can't be opened.
    }

    int maxLeafNumber = 0;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.count() >= 1) {
            int leafNumber = parts[0].toInt();
            if (leafNumber > maxLeafNumber) {
                maxLeafNumber = leafNumber;
            }
        }
    }
    file.close();

    return maxLeafNumber + 1; // Next available leaf number
}

void UserChequesDialog::saveCheque(int leafNumber, double amount, const QDateTime &dateTime)
{
    QString accountDataFilePath = "C:\\Users\\Home\\Documents\\BMSPROJ\\User Account Data\\" + m_username + ".txt";

    QFile accountFile(accountDataFilePath);
    double currentBalance = 0;
    if (accountFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&accountFile);
        QString line;
        for (int i = 0; i < 4; ++i)
        {
            line = in.readLine();
            if (i == 3)
            {
                currentBalance = line.toDouble();
            }
        }
        accountFile.close();
    }

    double newBalance = currentBalance - amount;
    if (newBalance < 0)
    {
        QMessageBox::warning(this, "Error", "Insufficient funds to issue cheque.");
        return;
    }

    QStringList fileContent;
    if (accountFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&accountFile);
        while (!in.atEnd()) {
            fileContent << in.readLine();
        }
        accountFile.close();
    }

    if (fileContent.size() >= 4)
    {
        fileContent[3] = QString::number(newBalance);
    }

    if (accountFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&accountFile);
        for (const QString &line : std::as_const(fileContent))
        {
            out << line << "\n";
        }
        accountFile.close();
    } else {
        QMessageBox::warning(this, "Error", "Could not open account file for writing.");
        return;
    }

    QFile chequeFile("C:\\Users\\Home\\Documents\\BMSPROJ\\Cheques\\" + m_username + "_cheque_history.txt");
    if (!chequeFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open cheque file for writing.");
        return;
    }

    QTextStream chequeOut(&chequeFile);
    chequeOut << leafNumber << ", Amount= " << amount << ", DateTime= " << dateTime.toString(Qt::ISODate) << "\n";
    QMessageBox::information(this, "Success", "Cheque saved successfully and account updated.");
    chequeFile.close();
}



/*void UserChequesDialog::on_pushButtonUserChequesBack_clicked()
{
    hide();
    CurrentUserLoggedIn ahg;
    ahg.setModal(true);
    ahg.exec();
}*/

void UserChequesDialog::on_pushButtonUserChequesBack_clicked()
{
    close();
}

