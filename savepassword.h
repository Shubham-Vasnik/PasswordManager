#ifndef SAVEPASSWORD_H
#define SAVEPASSWORD_H

#include <QDialog>


namespace Ui {
class SavePassword;
}

class SavePassword : public QDialog
{
    Q_OBJECT

public:
    explicit SavePassword(QWidget *parent = nullptr);
    ~SavePassword();

private slots:
    void on_SaveAccountBtn_clicked();

private:
    Ui::SavePassword *ui;
};

#endif // SAVEPASSWORD_H
