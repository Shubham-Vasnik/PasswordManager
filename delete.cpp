#include "delete.h"
#include "ui_delete.h"
#include "passwordmanager.h"
#include <QMessageBox>
#include "seesavedpasswords.h"

Delete::Delete(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_pushButton_clicked()
{

    QString delAccount = ui->lineEdit->text();

    PasswordManager conn;
    if(!conn.connOpen()){
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from account where account='"+delAccount+"'");

    if(qry.exec()){
        QMessageBox::information(this,"Delete","'"+delAccount+"' Deleted");
        conn.connClose();
    }
    else{
         QMessageBox::critical(this,"Error",qry.lastError().text());
    }
    SeeSavedPasswords *seeSavedPasswords;
    seeSavedPasswords = new SeeSavedPasswords(this);
    seeSavedPasswords->show();
}
