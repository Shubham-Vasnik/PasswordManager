#ifndef SAVEPASSWORD_H
#define SAVEPASSWORD_H

#include <QDialog>
#include "seesavedpasswords.h"


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

    void on_pushButton_2_clicked();

private:
    Ui::SavePassword *ui;
    SeeSavedPasswords *seeSavedPasswords;
};

#endif // SAVEPASSWORD_H
