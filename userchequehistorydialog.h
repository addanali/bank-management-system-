#ifndef USERCHEQUEHISTORYDIALOG_H
#define USERCHEQUEHISTORYDIALOG_H

#include <QDialog>

namespace Ui {
class UserChequeHistoryDialog;
}

class UserChequeHistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserChequeHistoryDialog(const QString &username, QWidget *parent = nullptr);
    ~UserChequeHistoryDialog();

private slots:
    void on_pushButtonUserCHBack_clicked();
    void on_pushButtonCHCheck_clicked();

private:
    Ui::UserChequeHistoryDialog *ui;
    QString m_username;
};

#endif // USERCHEQUEHISTORYDIALOG_H
