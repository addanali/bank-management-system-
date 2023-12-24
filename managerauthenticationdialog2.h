#ifndef MANAGERAUTHENTICATIONDIALOG2_H
#define MANAGERAUTHENTICATIONDIALOG2_H

#include <QDialog>

namespace Ui {
class ManagerAuthenticationDialog2;
}

class ManagerAuthenticationDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerAuthenticationDialog2(QWidget *parent = nullptr);
    ~ManagerAuthenticationDialog2();

private slots:
    void on_pushButtonManagerloginAuthenticate2_clicked();

    void on_pushButtonManagerLoginBack2_clicked();

private:
    Ui::ManagerAuthenticationDialog2 *ui;
};

#endif // MANAGERAUTHENTICATIONDIALOG2_H
