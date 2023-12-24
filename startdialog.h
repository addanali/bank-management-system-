#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>

namespace Ui {
class StartDialoglogo;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

private slots:
    void on_UserLogin_clicked();

    void on_ManagerLogin_clicked();

    void showTime();

    void on_pushButtonManagerLogin_clicked();

private:
    Ui::StartDialoglogo *ui;
};

#endif // STARTDIALOG_H
