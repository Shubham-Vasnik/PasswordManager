#include "passwordmanager.h"
#include "ui_passwordmanager.h"

PasswordManager::PasswordManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PasswordManager)
{
    ui->setupUi(this);

    if(!connOpen()){
        ui->statusbar->showMessage("Failed to open the database");
    }
    QPixmap pix(":/img/img/key.png");
//    int w = ui->img->width();
//    int h = ui->img->height();
    ui->img->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio));
}

PasswordManager::~PasswordManager()
{
    delete ui;
}


void PasswordManager::on_pushButton_clicked()
{
    QString userName = ui->UserName->text();
    QString password = ui->Password->text();

    if(!connOpen()){
        qDebug() << "Failed to open database";
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from master where username='"+userName+"' and password='"+password+"'");

    if(qry.exec()){
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count == 1){
            ui->statusbar->showMessage("Username and Password is correct",3000);
            connClose();
            hide();
            savePassword = new SavePassword(this);
            savePassword->show();

        }
        if(count < 1){
            ui->statusbar->showMessage("Username and Password is not correct",3000);
        }
        if(count > 1){
            ui->statusbar->showMessage("Username and Password is Duplicate",3000);
        }
    }
}
