#include "signuppage.h"
#include "ui_signuppage.h"
#include"agreementpage.h"
#include"mainwindow.h"
#include<QLabel>
#include<QtWidgets>
#include<QtSql>
#include<QLineEdit>
#include<QString>
#include<QMessageBox>
SignupPage::SignupPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupPage)
{
    ui->setupUi(this);
    QLabel *backLabel = new QLabel(this);
    backLabel->setText("<u>&lt;&lt; Back</u>");
    backLabel->setStyleSheet("color: blue;");
    backLabel->setCursor(Qt::PointingHandCursor);
    backLabel->setGeometry(10, 10, 100, 10);
    connect(backLabel, &QLabel::linkActivated, this, [=]() {
        MainWindow *m1=new MainWindow();
        this->close();
        m1->show();

    });
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");
            if (!db.open()) {
                qDebug() << "Failed to open signup database.";
                return;
            }
            else
                qDebug()<<"Connected";

}

SignupPage::~SignupPage()
{
    delete ui;
}

void SignupPage::on_pushButton_clicked()
{
    QString username, password, email, firstname, lastname, fulladdress, phonenumber, startdate, enddate,country,reference,industry,totalinvestment,notes;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    email = ui->lineEdit_5->text();
    firstname = ui->lineEdit_3->text();
    phonenumber = ui->lineEdit_7->text();
    startdate = ui->lineEdit_10->text();
    enddate = ui->lineEdit_13->text();
    lastname = ui->lineEdit_4->text();
    fulladdress = ui->lineEdit_9->text();
    country = ui->lineEdit_12->text();
    reference=ui->lineEdit_11->text();
    industry=ui->lineEdit_8->text();
    totalinvestment=ui->lineEdit_6->text();
    notes=ui->lineEdit_14->text();
    QSqlQuery query;
    query.prepare("INSERT INTO clienttable (username, password, email, firstname, lastname, phonenumber, fulladdress, 'start-date' , 'end-date',country,reference,industry,totalinvestment,notes) VALUES (?,?,?,?,?,?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(email);
    query.addBindValue(firstname);
    query.addBindValue(lastname);
    query.addBindValue(phonenumber);
    query.addBindValue(fulladdress);
    query.addBindValue(startdate);
    query.addBindValue(enddate);
    query.addBindValue(country);
    query.addBindValue(reference);
    query.addBindValue(industry);
    query.addBindValue(totalinvestment);
    query.addBindValue(notes);

    if (!query.exec()) {
        qDebug() << "Failed to insert user data into database:" << query.lastError().text();
     \
    } else {
        qDebug() << "User data inserted into database.";
        QMessageBox::information(this,"Signup Info","Signed Up Successful and Click on Proceed");
    }

}


void SignupPage::on_pushButton_3_clicked()
{
    agreementpage agree;
    agree.setModal(true);
    this->close();
    agree.exec();
}


void SignupPage::on_pushButton_2_clicked()
{
    QString companyusername, password, companyemail, companyname, companysize, companyaddress, companyphonenumber,companyceo, companycountry,companystatus,companytype;
    companyusername = ui->lineEdit_15->text();
    password = ui->lineEdit_16->text();
    companyemail = ui->lineEdit_20->text();
    companyname = ui->lineEdit_17->text();
    companyphonenumber = ui->lineEdit_23->text();
    companyceo = ui->lineEdit_22->text();
    companysize = ui->lineEdit_18->text();
    companyaddress = ui->lineEdit_19->text();
    companycountry = ui->lineEdit_21->text();
    companystatus=ui->lineEdit_25->text();
    companytype=ui->lineEdit_24->text();
    QSqlQuery query2;
    query2.prepare("INSERT INTO companytable (companyusername, password, companyemail, companyname, companysize, companyphonenumber, companyaddress,'company-ceo' ,'company-country','company-status','company-type') VALUES (?,?,?,?,?,?, ?, ?, ?, ?, ?)");
    query2.addBindValue(companyusername);
    query2.addBindValue(password);
    query2.addBindValue(companyemail);
    query2.addBindValue(companyname);
    query2.addBindValue(companysize);
    query2.addBindValue(companyaddress);
    query2.addBindValue(companyphonenumber);
    query2.addBindValue(companyceo);
    query2.addBindValue(companycountry);
    query2.addBindValue(companystatus);
    query2.addBindValue(companytype);


    if (!query2.exec()) {
        qDebug() << "Failed to insert user data into database:" << query2.lastError().text();
         QMessageBox::information(this,"Error ","Phone Number Already register");
    } else {
        qDebug() << "User data inserted into database.";
         QMessageBox::information(this,"Signup Info","Signed Up Successful and Click on Proceed");

    }
}


void SignupPage::on_pushButton_4_clicked()
{
    agreementpage agree2;
    agree2.setModal(true);
    this->close();
    agree2.exec();
}

