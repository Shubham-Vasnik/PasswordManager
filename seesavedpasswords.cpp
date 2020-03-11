#include "seesavedpasswords.h"
#include "ui_seesavedpasswords.h"
#include "passwordmanager.h"

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
