#include "joinpart.h"
#include "ui_joinpart.h"
#include "ceo.h"
#include "employee.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

joinpart::joinpart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::joinpart)
{
    ui->setupUi(this);

    // Open the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");

    if (!db.open()) {
        qDebug() << "Failed to connect to database.";
    }
}

joinpart::~joinpart()
{
    delete ui;
}

void joinpart::on_pushButton_clicked()
{
    QString cpid_investor = ui->lineEdit->text();

    QSqlQuery qry;
    if (qry.exec("SELECT * FROM companyparts WHERE investor_cpid='" + cpid_investor + "'")) {
        int count = 0;
        while (qry.next()) {
            count++;
        }
        if (count == 1) {
            investor* w = new investor;
            w->setAttribute(Qt::WA_DeleteOnClose);
            w->showMaximized();
          //  this->close();
            w->show();
        }
    }
}

void joinpart::on_pushButton_2_clicked()
{
    QString cpid_founder = ui->lineEdit_2->text();

    QSqlQuery qry;
    if (qry.exec("SELECT * FROM companyparts WHERE founder_cpid='" + cpid_founder + "'")) {
        int count = 0;
        while (qry.next()) {
            count++;
        }
        if (count == 1) {
            founder* w = new founder;
            w->setAttribute(Qt::WA_DeleteOnClose);
            w->showMaximized();
           // this->close();
            w->show();
        }
    }
}

void joinpart::on_pushButton_3_clicked()
{
    QString cpid_ceo = ui->lineEdit_3->text();

    QSqlQuery qry;
    if (qry.exec("SELECT * FROM companyparts WHERE ceo_cpid='" + cpid_ceo + "'")) {
        int count = 0;
        while (qry.next()) {
            count++;
        }
        if (count == 1) {
            CEO* w = new CEO;
            w->setAttribute(Qt::WA_DeleteOnClose);
            w->showMaximized();
           // this->close();
            w->show();
        }
    }
}

void joinpart::on_pushButton_4_clicked()
{
    QString cpid_employee = ui->lineEdit_4->text();

    QSqlQuery qry;
    if (qry.exec("SELECT * FROM companyparts WHERE employee_cpid='" + cpid_employee + "'")) {
        int count = 0;
        while (qry.next()) {
            count++;
        }
        if (count == 1) {
            employee* w = new employee;
            w->setAttribute(Qt::WA_DeleteOnClose);
            w->showMaximized();
          //  this->close();
            w->show();
        }
    }
}
