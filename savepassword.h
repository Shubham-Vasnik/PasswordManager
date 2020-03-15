#ifndef SAVEPASSWORD_H
#define SAVEPASSWORD_H

#include <QDialog>
#include "seesavedpasswords.h"
#include <QSqlQueryModel>


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

class CustomSqlModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    CustomSqlModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &item, int role) const override;
};



#endif // SAVEPASSWORD_H
