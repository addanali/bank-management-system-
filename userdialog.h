#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = nullptr);
    ~UserDialog();

private slots:
    void on_NewUser_clicked();

    void on_CurrentUser_clicked();

    void on_pushButtonUserBack_clicked();

private:
    Ui::UserDialog *ui;
};

#endif // USERDIALOG_H
