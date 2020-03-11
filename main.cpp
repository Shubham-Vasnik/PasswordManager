#include "passwordmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PasswordManager w;
    w.setWindowTitle("Password Manager");
    w.show();
    return a.exec();
}
