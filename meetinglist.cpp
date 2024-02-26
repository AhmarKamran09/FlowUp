#include "meetinglist.h"
#include "ui_meetinglist.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include<QListWidget>
#include<QSqlQuery>
#include<qtableview.h>
#include<QBoxLayout>
meetinglist::meetinglist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::meetinglist)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Abdul Sami/Desktop/Programming/CRM Project/Databases/MainDatabase.db");

    if (!db.open()) {
        qWarning() << "Error opening database: " << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully!";
    }







}

meetinglist::~meetinglist()
{
    delete ui;
}
