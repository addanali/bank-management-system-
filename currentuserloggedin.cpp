#include "currentuserloggedin.h"
#include "ui_currentuserloggedin.h"
#include <currentuser.h>
#include <usertransaction.h>
#include <currentuserwithdrawdialog.h>
#include <currentuserbalancedialog.h>
#include <currentuserdepositdialog.h>
#include <userchequesdialog.h>
#include <userchequehistorydialog.h>

CurrentUserLoggedIn::CurrentUserLoggedIn( QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CurrentUserLoggedIn)

{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { "
                        "background-image: url('C:/Users/Home/Pictures/background QT plain.png'); "
                        "background-repeat: no-repeat; "
                        "background-position: center; "
                        "background-size: cover; "
                        "}");

}

CurrentUserLoggedIn::~CurrentUserLoggedIn()
{
    delete ui;
}



void CurrentUserLoggedIn::setUsername(const QString &username)
{
    m_username = username;
}


void CurrentUserLoggedIn::on_pushButton_clicked()
{
    hide();
    CurrentUser f;
    f.setModal(true);
    f.exec();
}


void CurrentUserLoggedIn::on_pushButtonCULTransactions_clicked()
{
    UserTransaction abl(m_username, this);
    abl.setModal(true);
    abl.exec();
    show();

}


void CurrentUserLoggedIn::on_pushButtonCULWithdraw_clicked()
{
    CurrentUserWithdrawDialog abo(m_username, this);
    abo.setModal(true);
    abo.exec();
    show();

}



void CurrentUserLoggedIn::on_pushButtonCULBalance_clicked()
{
    CurrentUserBalanceDialog abg(m_username, this);
    abg.setModal(true);
    abg.exec();
    show();
}




void CurrentUserLoggedIn::on_pushButtonCULDeposit_clicked()
{
    CurrentUserDepositDialog abf(m_username, this);
    abf.setModal(true);
    abf.exec();
    show();

}


void CurrentUserLoggedIn::on_pushButtonCULCheques_clicked()
{

    UserChequesDialog abp(m_username, this);
    abp.setModal(true);
    abp.exec();
    show();

}


void CurrentUserLoggedIn::on_pushButtonCULChequeHistory_clicked()
{
    UserChequeHistoryDialog abs(m_username, this);
    abs.setModal(true);
    abs.exec();
    show();
}

