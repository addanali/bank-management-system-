#ifndef CURRENTUSERBALANCEDIALOG_H
#define CURRENTUSERBALANCEDIALOG_H

#include <QDialog>

namespace Ui {
class CurrentUserBalanceDialog;
}

class CurrentUserBalanceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CurrentUserBalanceDialog(const QString &username, QWidget *parent = nullptr);
    ~CurrentUserBalanceDialog();



private slots:


    void on_pushButtonCULBalance_clicked();

   // void on_pushButtonCUBalanceBack_clicked();



    void on_pushButton_clicked();

private:
    Ui::CurrentUserBalanceDialog *ui;
    QString m_username;
};

#endif // CURRENTUSERBALANCEDIALOG_H
