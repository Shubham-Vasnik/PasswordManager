#include "savepassword.h"
#include "ui_savepassword.h"
#include "passwordmanager.h"
#include "QMessageBox"

SavePassword::SavePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SavePassword)
{
    ui->setupUi(this);
    PasswordManager conn;
    if(!conn.connOpen()){
        ui->label->setText("Failed to open the database");
    }
}

SavePassword::~SavePassword()
{
    delete ui;
}

void SavePassword::on_SaveAccountBtn_clicked()
{
    PasswordManager conn;
    QString newAccountName = ui->NewAccountName->text();
    QString newUserName = ui->NewUserName->text();
    QString newPassword = ui->NewPassword->text();
    QString newEnPassword = conn.encrypt(newPassword);

    if(!conn.connOpen()){
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into account (account,username,password) values ('"+newAccountName+"','"+newUserName+"','"+newEnPassword+"')");

    if(qry.exec()){
        QMessageBox::information(this,"Saved","'"+newAccountName+"' Saved");
        conn.connClose();
    }
    else{
         QMessageBox::critical(this,"Error",qry.lastError().text());
    }
}

void SavePassword::on_pushButton_2_clicked()
{
    hide();
    seeSavedPasswords = new SeeSavedPasswords(this);
    seeSavedPasswords->show();
}
