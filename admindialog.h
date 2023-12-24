#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>

namespace Ui {
class pushButtonDeleteAcc;
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = nullptr);
    ~AdminDialog();

private slots:
    void on_pushButtonAdminBack_clicked();

    void on_pushButtonBankAdminSearch_clicked();

    void on_pushButtonAdminSave_clicked();


    void on_pushButtonAdminDeleteAcc_clicked();



    void on_pushButtonBankAdminTransactions_clicked();

    void on_pushButtonBankAdminTransactionsClear_clicked();

    void on_pushButtonBankAdminCH_clicked();

    void on_pushButtonBankAdminCHClear_clicked();

    void on_pushButtonManageAdmins_clicked();

private:
    Ui::pushButtonDeleteAcc *ui;
};

#endif // ADMINDIALOG_H
