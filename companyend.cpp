#include "companyend.h"
#include "ui_companyend.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include"employee.h"
#include"ceo.h"
#include<QLayout>
companyend::companyend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::companyend)
{
    ui->setupUi(this);

}

companyend::~companyend()
{
    delete ui;
}


void companyend::on_pushButton_clicked()
{
     QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("C:/Users/Abdul Sami/Desktop/New Application From Start/CRM Project/Databases/MainDatabase.db");
    if (!db1.open()) {
        qDebug() << "Failed to connect to database.";
    }
    QString cpid_investor;
    cpid_investor=ui->lineEdit->text();

    if(!db1.open()){
        qDebug()<<"Failed to Connect";
    }

    QSqlQuery qry;
    if(qry.exec("select * from companyparts where investor_cpid='"+cpid_investor+"'" )){
         int count =0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            investor* w = new investor; // Instantiate the investor object on the heap
                       w->setAttribute(Qt::WA_DeleteOnClose); // Schedule the deletion of the object
                       w->showMaximized();
                       this->close();
                       w->show(); // Use show() instead of exec()






                   }
    }
}


void companyend::on_pushButton_2_clicked()
{
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
   db2.setDatabaseName("C:/Users/Abdul Sami/Desktop/Programming/CRM Project/Databases/MainDatabase.db");
   if (!db2.open()) {
       qDebug() << "Failed to connect to database.";
   }
   QString cpid_founder;
   cpid_founder=ui->lineEdit_2->text();

   if(!db2.open()){
       qDebug()<<"Failed to Connect";
   }

   QSqlQuery qry;
   if(qry.exec("select * from companyparts where founder_cpid='"+cpid_founder+"'" )){
        int count =0;
       while(qry.next()){
           count++;
       }
       if(count==1)
         {
           founder* w = new founder; // Instantiate the investor object on the heap
                      w->setAttribute(Qt::WA_DeleteOnClose); // Schedule the deletion of the object
                      w->showMaximized();
                      this->close();
                      w->show(); // Use show() instead of exec()

                 }
   }
}


void companyend::on_pushButton_3_clicked()
{
    QSqlDatabase db3 = QSqlDatabase::addDatabase("QSQLITE");
   db3.setDatabaseName("C:/Users/Abdul Sami/Desktop/Programming/CRM Project/Databases/MainDatabase.db");
   if (!db3.open()) {
       qDebug() << "Failed to connect to database.";
   }
   QString cpid_ceo;
   cpid_ceo=ui->lineEdit_3->text();

   if(!db3.open()){
       qDebug()<<"Failed to Connect";
   }

   QSqlQuery qry;
   if(qry.exec("select * from companyparts where ceo_cpid='"+cpid_ceo+"'" )){
        int count =0;
       while(qry.next()){
           count++;
       }
       if(count==1)
         {
           CEO* w = new CEO;
                      w->setAttribute(Qt::WA_DeleteOnClose);
                      w->showMaximized();
                      this->close();
                      w->show();

                 }
   }
}


void companyend::on_pushButton_4_clicked()
{
    QSqlDatabase db4 = QSqlDatabase::addDatabase("QSQLITE");
   db4.setDatabaseName("C:/Users/Abdul Sami/Desktop/Programming/CRM Project/Databases/MainDatabase.db");
   if (!db4.open()) {
       qDebug() << "Failed to connect to database.";
   }
   QString cpid_employee;
   cpid_employee=ui->lineEdit_4->text();

   if(!db4.open()){
       qDebug()<<"Failed to Connect";
   }

   QSqlQuery qry;
   if(qry.exec("select * from companyparts where employee_cpid='"+cpid_employee+"'" )){
        int count =0;
       while(qry.next()){
           count++;
       }
       if(count==1)
         {


           employee* w = new employee;
                      w->setAttribute(Qt::WA_DeleteOnClose);
                      w->showMaximized();
                      this->close();
                      w->show();
                 }
   }
}

