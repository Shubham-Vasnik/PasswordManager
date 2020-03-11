#include "seesavedpasswords.h"
#include "ui_seesavedpasswords.h"
#include "passwordmanager.h"
#include "savepassword.h"

SeeSavedPasswords::SeeSavedPasswords(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SeeSavedPasswords)
{
    ui->setupUi(this);
    showPassword();
}

SeeSavedPasswords::~SeeSavedPasswords()
{
    delete ui;
}

void SeeSavedPasswords::showPassword(){
    PasswordManager conn;
    QSqlQueryModel *model = new QSqlQueryModel;
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.passwordDb);
    qry->prepare("select * from account");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    conn.connClose();
    qDebug() << (model->rowCount());
}



void SeeSavedPasswords::on_deleteAccount_clicked()
{
    hide();
    del = new Delete(this);
    del->show();
}




void SeeSavedPasswords::on_addAccount_clicked()
{
    hide();
    SavePassword *savePassword;
    savePassword = new SavePassword(this);
    savePassword->show();
}
