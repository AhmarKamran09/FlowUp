#include "clientloginpage.h"
#include "ui_clientloginpage.h"
#include"mainwindow.h"
#include"loadingpage.h"
#include<QLabel>
#include<QPushButton>
#include<QLayout>
#include<QFormLayout>
#include<QLineEdit>
#include<QWidget>
#include<QLayout>
#include<QtSql>
#include<QLineEdit>
#include<QString>
clientloginpage::clientloginpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientloginpage)
{
    ui->setupUi(this);
   db=QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");

   QLabel *backLabel = new QLabel(this);
   backLabel->setText("<u>&lt;&lt; Back</u>");
   backLabel->setStyleSheet("color: blue;");
   backLabel->setCursor(Qt::PointingHandCursor);
   backLabel->setGeometry(10, 10, 100, 20);
   connect(backLabel, &QLabel::linkActivated, this, [=]() {
       this->close();

   });
}

clientloginpage::~clientloginpage()
{
    delete ui;
}

void clientloginpage::on_pushButton_clicked()
{
    QString username,password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();
    if(!db.open()){
        qDebug()<<"Failed to Connect";
    }

    QSqlQuery qry;
    if(qry.exec("select * from clienttable where username='"+username+"'and password='"+password+"'" )){
         int count =0;
        while(qry.next()){
            count++;
        }
        if(count==1)
          {
            LoadingPage l1;
            l1.setModal(true);
            this->close();
            l1.exec();
                  }

        if(count>1)
           ui->label_3->setText("Incorrect username and Password");
        if(count<1)
             ui->label_3->setText("Incorrect username and Password");
    }
}

