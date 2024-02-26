#include "teampage.h"
#include "ui_teampage.h"
#include"loadingpage.h"
#include<QLabel>
#include<QtSql>
#include<QLineEdit>
#include<QString>
#include"clientloginpage.h"
#include<QDebug>
#include"joinpart.h"
teampage::teampage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teampage)
{
    ui->setupUi(this);
    QLabel *backLabel = new QLabel(this);
    backLabel->setText("<u>&lt;&lt; Back</u>");
    backLabel->setStyleSheet("color: blue;");
    backLabel->setCursor(Qt::PointingHandCursor);
    backLabel->setGeometry(10, 10, 100, 20);
    db1=QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");
}

teampage::~teampage()
{
    delete ui;
}

void teampage::on_pushButton_clicked()
{
    QString username,password;
    username=ui->lineEdit_companyusername->text();
    password=ui->lineEdit_companypassword->text();
    if(!db1.open()){
        qDebug()<<"Failed to Connect";
    }
    else
        qDebug()<<"Connected Successful";
    QSqlQuery qry1;
    if(qry1.exec("select * from companytable where companyusername='"+username+"'and password='"+password+"'" )){
         int count =0;
        while(qry1.next()){
            count++;
        }
        if(count==1)
          {
            joinpart *e=new joinpart;
            this->close();
            e->show();
            qDebug()<<"Connected";

                  }
        if(count>1)
            ui->label_3->setText("Incorrect username and  Password");
        if(count<1)
            ui->label_3->setText("Incorrect username and  Password");
    }
}

