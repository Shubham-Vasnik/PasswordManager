#ifndef SEESAVEDPASSWORDS_H
#define SEESAVEDPASSWORDS_H

#include <QMainWindow>
//#include "savepassword.h"
#include "delete.h"

namespace Ui {
class SeeSavedPasswords;
}

class SeeSavedPasswords : public QMainWindow
{
    Q_OBJECT

public:
void showPassword();
public:
    explicit SeeSavedPasswords(QWidget *parent = nullptr);
    ~SeeSavedPasswords();

private slots:
void on_pushButton_clicked();

void on_deleteAccount_clicked();

void on_pushButton_2_clicked();

void on_addAccount_clicked();

private:
    Ui::SeeSavedPasswords *ui;
//    SavePassword *savePassword;
    Delete *del;
};

#endif // SEESAVEDPASSWORDS_H
