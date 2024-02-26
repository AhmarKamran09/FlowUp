#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"clientloginpage.h"
#include"teampage.h"
#include"signuppage.h"
#include"loadingpage.h"
#include<QCheckBox>
#include<QPixmap>
#include<QTimer>
#include<QtGui>
#include<QtWidgets>
#include<QPropertyAnimation>
#include<QGraphicsAnchor>
#include<QGraphicsView>
#include<QPropertyAnimation>
#include<QVBoxLayout>
#include<QFont>
#include"agreementpage.h"
#include"calendar.h"
#include"investor.h"
#include"employee.h"
#include"ceo.h"
#include"companyend.h"
#include"joinpart.h"
#include "client.h"
#include"agreementpage.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QLabel *label = new QLabel(this);  // Create a new QLabel widget
        label->setFixedSize(500, 600);
        label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        label->move(-80, 60);
        label->setStyleSheet("background-image: url(:/images/Order_Completed-removebg-preview.png);");


QLabel *label2 = new QLabel(this);
label2->move(57,0);
label2->setText("Change Mode");
    // Create a QCheckBox object for the toggle switch
    QCheckBox *toggleSwitch = new QCheckBox(this);
    toggleSwitch->setGeometry(50, 50, 50, 25); // Set the geometry of the toggle switch
    toggleSwitch->move(8,2);
    // Connect the toggled() signal of the toggle switch to a slot that will handle the state change
    connect(toggleSwitch, &QCheckBox::toggled, this, [=]() {
        if (toggleSwitch->checkState() == Qt::Checked) {
           this->setStyleSheet("background-color: lightgreen");
        } else {
           this->setStyleSheet("background-color: green");
        }
    });

    // Set the stylesheet for the toggle switch to customize its appearance
    toggleSwitch->setStyleSheet("QCheckBox::indicator { width: 25px; height: 25px; }"
                                "QCheckBox::indicator:checked { background-color: blue; }"
                                "QCheckBox::indicator:unchecked { background-color: lightblue; }");



QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
ui->pushButton->setGraphicsEffect(effect);

QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
animation->setDuration(1000);
animation->setLoopCount(-1);
animation->setStartValue(0.2);
animation->setEndValue(1.0);
animation->setEasingCurve(QEasingCurve::OutQuad);
animation->start();


QLabel *label1 = new QLabel(this);  // Create a new QLabel widget
    label1->setFixedSize(600, 300);
    label1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    label1->move(410, 120);
    label1->setStyleSheet("background-image: url(:/images/Introducing_flowup-removebg-preview.png);");
 button1= new QPushButton("Join As Team/Company",this);
 button1->setGeometry(10,20,130,20);
 button1->move(795,366);
 button1->setStyleSheet("background-color: lightgreen;");
 connect(button1, &QPushButton::clicked, this, &MainWindow::onloginbuttonclicked2);

 button2= new QPushButton("Join As Client",this);
 button2->setGeometry(10,10,130,20);
 button2->move(480,366);
 button2->setStyleSheet("background-color: lightgreen;");
 connect(button2, &QPushButton::clicked, this, &MainWindow::onloginbuttonclicked1);

 QLabel *label3 = new QLabel(this);  // Create a new QLabel widget
     label3->setFixedSize(300, 30);
     label3->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
     label3->move(100, 120);
     label3->setStyleSheet("background-image: url(:/images/c49e8a4429b543158951fbaca6b7a3da-removebg-preview.png);");

     button3= new QPushButton("SignUp Now,If you are New Here ",this);
     button3->setGeometry(10,20,200,20);
     button3->move(650,450);
     button3->setStyleSheet("background-color: white;");
     connect(button3, &QPushButton::clicked, this, &MainWindow::onloginbuttonclicked3);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onloginbuttonclicked1(){

    clientloginpage buttonclick;
    buttonclick.setModal(true);
    this->close();
    buttonclick.exec();

}

void MainWindow::onloginbuttonclicked2(){

    teampage buttonclick2;
    buttonclick2.setModal(true);
    this->close();
    buttonclick2.exec();
}

void MainWindow::onloginbuttonclicked3(){

    SignupPage buttonclick3;
    buttonclick3.setModal(true);
    this->close();
    buttonclick3.exec();

}


void MainWindow::on_pushButton_2_clicked()
{
agreementpage *w=new agreementpage;
this->close();
    w->show();
}

