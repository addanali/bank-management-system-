#ifndef USERTRANSACTION_H
#define USERTRANSACTION_H

#include <QDialog>
#include <QCloseEvent>


namespace Ui {
class UserTransaction;
}

class UserTransaction : public QDialog
{
    Q_OBJECT

public:
    explicit UserTransaction(const QString &username, QWidget *parent = nullptr);
    ~UserTransaction();

protected:
    void closeEvent(QCloseEvent *event) override;


signals:
    void dialogClosed(const QString &username);


private slots:
    void on_pushButtonUserTHBack_clicked();

    void on_pushButtonCurrentUserTransactions_clicked();

private:
    Ui::UserTransaction *ui;
    QString m_username;
};

#endif // USERTRANSACTION_H
