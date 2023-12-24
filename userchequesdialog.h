#ifndef USERCHEQUESDIALOG_H
#define USERCHEQUESDIALOG_H

#include <QDialog>
#include <QDateTime>

namespace Ui {
class UserChequesDialog;
}

class UserChequesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserChequesDialog(const QString &username, QWidget *parent = nullptr);
    ~UserChequesDialog();

private slots:
    void on_pushButtonSaveCheque_clicked();

    void on_pushButtonUserChequesBack_clicked();

private:
    Ui::UserChequesDialog *ui;
    int getNextLeafNumber();
    void saveCheque(int leafNumber, double amount, const QDateTime &dateTime);
    QString filePath;
    QString m_username;
};

#endif // USERCHEQUESDIALOG_H
