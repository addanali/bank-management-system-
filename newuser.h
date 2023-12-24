#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>

namespace Ui {
class NewUser;
}

class NewUser : public QDialog
{
    Q_OBJECT

public:
    explicit NewUser(QWidget *parent = nullptr);
    ~NewUser();

private slots:
    void on_pushButtonNewUserBack_clicked();

    void on_pushButtonNewUserCreateAcc_clicked();

private:
    Ui::NewUser *ui;
};

#endif // NEWUSER_H
