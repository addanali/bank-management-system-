#ifndef ADMINAUTHENTICATIONDIALOG_H
#define ADMINAUTHENTICATIONDIALOG_H

#include <QDialog>

namespace Ui {
class AdminAuthenticationDialog;
}

class AdminAuthenticationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminAuthenticationDialog(QWidget *parent = nullptr);
    ~AdminAuthenticationDialog();

private slots:
    void on_pushButtonAdminloginAuthenticate_clicked();

    void on_pushButtonAdminLoginBack_clicked();

    void on_pushButtonAdminForgotPass_clicked();

private:
    Ui::AdminAuthenticationDialog *ui;
};

#endif // ADMINAUTHENTICATIONDIALOG_H
