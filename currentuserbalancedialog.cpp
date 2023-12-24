 #include "currentuserbalancedialog.h"
#include "ui_currentuserbalancedialog.h"
#include <currentuserloggedin.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


CurrentUserBalanceDialog::CurrentUserBalanceDialog(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CurrentUserBalanceDialog )
    , m_username(username)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

    connect(ui->pushButtonCULBalance, &QPushButton::clicked, this, &CurrentUserBalanceDialog::on_pushButtonCULBalance_clicked);

}

CurrentUserBalanceDialog::~CurrentUserBalanceDialog()
{
    delete ui;
}





#include <QString>

void CurrentUserBalanceDialog::on_pushButtonCULBalance_clicked()
{
    QFile file("UsersHPDownloadsBMSPROJzipBMSPROJAdmin Account Data\\" + m_username + ".txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Unable to open user data file.");
        return;
    }

    QTextStream in(&file);
    QString line;
    int lineCount = 0;

    while (!in.atEnd() && lineCount < 4)
    {
        line = in.readLine();
        lineCount++;
        if (lineCount == 4)
        {
            ui->textEditBalance->setText(line);
            break;
        }
    }

    file.close();
}



void CurrentUserBalanceDialog::on_pushButton_clicked()
{
    close();
}


