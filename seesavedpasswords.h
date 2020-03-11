#ifndef SEESAVEDPASSWORDS_H
#define SEESAVEDPASSWORDS_H

#include <QMainWindow>


namespace Ui {
class SeeSavedPasswords;
}

class SeeSavedPasswords : public QMainWindow
{
    Q_OBJECT

public:
void showPassword();
public:
    explicit SeeSavedPasswords(QWidget *parent = nullptr);
    ~SeeSavedPasswords();

private:
    Ui::SeeSavedPasswords *ui;
};

#endif // SEESAVEDPASSWORDS_H
