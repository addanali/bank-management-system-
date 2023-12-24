#ifndef BANKMANAGERDIALOG_H
#define BANKMANAGERDIALOG_H

#include <QDialog>

namespace Ui {
class BankManagerDialog;
}

class BankManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BankManagerDialog(QWidget *parent = nullptr);
    ~BankManagerDialog();

private slots:
    void on_pushButtonBankManagerDialog_clicked();

    void on_pushButtonManagerAddAcc_clicked();

    void on_pushButtonManagerViewAcc_clicked();

    void on_pushButtonManagerRemoveAcc_clicked();

    void on_pushButtonManagerSearch_clicked();

    void on_pushButtonManagerEditAcc_clicked();

private:
    Ui::BankManagerDialog *ui;
};

#endif // BANKMANAGERDIALOG_H
