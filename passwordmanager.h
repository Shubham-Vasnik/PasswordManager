#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "savepassword.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PasswordManager; }
QT_END_NAMESPACE

class PasswordManager : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase passwordDb;
    bool connOpen(){
    passwordDb = QSqlDatabase::addDatabase("QSQLITE");
    passwordDb.setDatabaseName("C:/sqlite/passwordManager.db");
    if(!passwordDb.open()){
       qDebug() << "Failed to open the database";
       return false;
    }
    else{
        qDebug() << "Connected";
        return true;
    }
    }

    void connClose(){
        passwordDb.close();
        passwordDb.removeDatabase(QSqlDatabase::defaultConnection);
    }

public:
    PasswordManager(QWidget *parent = nullptr);
    ~PasswordManager();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PasswordManager *ui;
    SavePassword *savePassword;
};
#endif // PASSWORDMANAGER_H
