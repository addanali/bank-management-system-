#ifndef MANAGERAUTHENTICATIONDIALOG_H
#define MANAGERAUTHENTICATIONDIALOG_H

#include <QDialog>

namespace Ui {
class ManagerAuthenticationDialog;
}

class ManagerAuthenticationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerAuthenticationDialog(QWidget *parent = nullptr);
    ~ManagerAuthenticationDialog();

private slots:
    void on_pushButtonManagerloginAuthenticate_clicked();

    void on_pushButtonManagerLoginBack_clicked();

private:
    Ui::ManagerAuthenticationDialog *ui;
};

#endif // MANAGERAUTHENTICATIONDIALOG_H
