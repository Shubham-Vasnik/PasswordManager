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

CustomSqlModel::CustomSqlModel(QObject *parent)
    : QSqlQueryModel(parent)
{
}

QVariant CustomSqlModel::data(const QModelIndex &index, int role) const
{
    PasswordManager conn;
    QVariant value = QSqlQueryModel::data(index, role);
    if (value.isValid() && role == Qt::DisplayRole) {
         if (index.column() == 2)
            return conn.decrypt(value.toString());
    }
    return value;
}


void SeeSavedPasswords::showPassword(){
    PasswordManager conn;
    CustomSqlModel *model = new CustomSqlModel;
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.passwordDb);
    qry->prepare("select * from account");
    qry->exec();
    model->setQuery(*qry);
    model->setHeaderData(0, Qt::Horizontal, tr("Account Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("User Name / Email"));
    model->setHeaderData(2, Qt::Horizontal, tr("Password"));

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setStyleSheet("color:#121212 ");
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
