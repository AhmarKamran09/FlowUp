#ifndef CLIENTLOGINPAGE_H
#define CLIENTLOGINPAGE_H

#include <QDialog>
#include<QFormLayout>
#include<QPushButton>
#include<QLineEdit>
#include<Qtsql>
#include<QtDebug>
#include<QFileInfo>
namespace Ui {
class clientloginpage;
}

class clientloginpage : public QDialog
{
    Q_OBJECT

public:
    explicit clientloginpage(QWidget *parent = nullptr);
    ~clientloginpage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::clientloginpage *ui;
    QSqlDatabase db;

};

#endif // CLIENTLOGINPAGE_H
