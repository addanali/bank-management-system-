#ifndef CURRENTUSERDEPOSITDIALOG_H
#define CURRENTUSERDEPOSITDIALOG_H

#include <QDialog>
#include <QString>
#include <QDateTime>

namespace Ui {
class CurrentUserDepositDialog;
}

class CurrentUserDepositDialog : public QDialog {
    Q_OBJECT

public:
    explicit CurrentUserDepositDialog(const QString &username, QWidget *parent = nullptr);
    ~CurrentUserDepositDialog();


private slots:
    void on_pushButtonCUDepositBack_clicked();
    void on_pushButtonConfirmDeposit_clicked();

signals:
    void usernameSentBack(const QString &username);


private:
    Ui::CurrentUserDepositDialog *ui;
    QString m_username;

    void logTransaction(const QString &username, double amount, const QDateTime &dateTime);
};

#endif // CURRENTUSERDEPOSITDIALOG_H
