#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <QDialog>

namespace Ui {
class CurrentUser;
}

class CurrentUser : public QDialog
{
    Q_OBJECT

public:
    explicit CurrentUser(QWidget *parent = nullptr);
    ~CurrentUser();

private slots:



    void on_pushButtonCUAuthenticate_clicked();

    void on_pushButtonCUBack_clicked();

    void on_pushButtonCUForgotPin_clicked();

private:
    Ui::CurrentUser *ui;

};

#endif // CURRENTUSER_H
