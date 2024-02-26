#include "investor.h"
#include "ui_investor.h"
#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QFileInfo>
#include<QSqlTableModel>
#include <QGraphicsDropShadowEffect>
investor::investor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::investor)
{

    ui->setupUi(this);
    QWidget *left=new QWidget(this);
    QStackedWidget *rightstacked=new QStackedWidget(this);
    QPushButton **a=new QPushButton*[4];
    QWidget **page = new QWidget*[6];
    QGraphicsDropShadowEffect **effect = new QGraphicsDropShadowEffect*[4];

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");
    if (!db.open()) {
        qDebug() << "Failed to open database connection.";
        return;
    }
    QLabel *icon= new QLabel(left);

    //setting colour of widgets

    left->setStyleSheet("background-color:green;");
    rightstacked->setStyleSheet("background-color: lightgreen;");
    this->setStyleSheet("background-color: black;");
    //setting geometry of widgets

    left->setGeometry(0,0,260,790);

    rightstacked->setGeometry(260,0,1276,790);
   icon->setFixedSize(260,200);
    icon->move(0,0);
   icon->setStyleSheet("background-image:url(:/images/left.png)");

    for (int i = 0; i < 4; i++) {
        a[i]= new QPushButton(left);
        effect[i] = new QGraphicsDropShadowEffect;
        effect[i]->setColor(Qt::black);

        effect[i]->setOffset(0, 0);
        effect[i]->setBlurRadius(10);

        // Apply the effect to the button
        a[i]->setGraphicsEffect(effect[i]);
        page[i] = new QWidget;
        rightstacked->addWidget(page[i]);
        a[i]->setStyleSheet("QPushButton { background-color: lightgreen; border-radius: 10px; }");
        a[i]->setFont(setfonting(12,true));
    }

    a[0]->setGeometry(0,210,250,60);
    a[1]->setGeometry(0,280,250,60);
    a[2]->setGeometry(0,350,250,60);
    a[3]->setGeometry(0,420,250,60);


    for (int i = 4; i<6; ++i) {
        page[i] = new QWidget;
    }
    a[0]->setText("INFORMATION OF EMPLOYEES");
    a[1]->setText("PENDING PROJECTS");
    a[2]->setText("COMPLETED PROJECTS");
    a[3]->setText("ABOUT US");




    getinfo(page[0]);
    getpendingprojectdetails(page[1]);
    seecompletedprojects(page[2]);
    about(page[4]);
    resources(page[5]);
    QVBoxLayout *set1=new QVBoxLayout(page[3]);
    set1->addWidget(page[4]);
    set1->addWidget(page[5]);


    connect(a[0], &QPushButton::clicked, [this,a,rightstacked]() {
    this->setpagedesign(a, rightstacked,0,0,4);
    });

    connect(a[1], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,1,1,4);
    });
    connect(a[2], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,2,2,4);
    });
    connect(a[3], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,3,3,4);
    });

}
void investor::seecompletedprojects(QWidget *page3){

    QLabel *label=new QLabel(page3);
    label->setText("COMPLETED PROJECTS");
    label->setFont(setfonting(25,true));
    label->setGeometry(5,5,400,100);
    // Create the model and table view

    QSqlQuery query("SELECT * FROM completedproject");
    if (!query.exec()) {
        qDebug() << "Failed to execute query.";
        return;
    }

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("completedproject");

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    QTableView* tableView = new QTableView(page3);
    tableView->setStyleSheet("background-color: darkgrey;");
    tableView->setModel(model);
    tableView->move(5,105);
    tableView->resize(950,400);
    tableView->setStyleSheet("background-image:url(:/images/table view.png)");

}



void investor::getpendingprojectdetails(QWidget *page2){
    QLabel *label=new QLabel(page2);
    label->setText("PENDING PROJECTS");
    label->setFont(setfonting(25,true));
    label->setGeometry(5,5,400,100);
    // Create the model and table view
    QSqlQuery query("SELECT * FROM pendingproject");
    if (!query.exec()) {
        qDebug() << "Failed to execute query.";
        return;
    }

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("pendingproject");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    QTableView* tableView = new QTableView(page2);
    tableView->setStyleSheet("background-color: darkgrey;");
    tableView->setModel(model);
    tableView->move(5,105);
    tableView->resize(950,400);
    tableView->setStyleSheet("background-image:url(:/images/table view.png)");
}

void investor::getinfo(QWidget* page1) {
    QString countString,countString2,countString3;
    QString targetWord = "development";
    QSqlQuery query2;
    query2.prepare("SELECT COUNT(*) AS count FROM employee WHERE designation LIKE '%' || :targetWord || '%'");

    query2.bindValue(":targetWord", targetWord);

    if (query2.exec() && query2.next()) {

        int count = query2.value("count").toInt();


        countString = QString::number(count);

    }
    QString targetWord2 = "management";
    QSqlQuery query3;
    query3.prepare("SELECT COUNT(*) AS count FROM employee WHERE designation LIKE '%' || :targetWord2 || '%'");

    query3.bindValue(":targetWord2", targetWord2);

    if (query3.exec() && query3.next()) {

        int count = query3.value("count").toInt();


        countString2 = QString::number(count);

    }
    QString targetWord3 = "marketing";
    QSqlQuery query4;
    query4.prepare("SELECT COUNT(*) AS count FROM employee WHERE designation LIKE '%' || :targetWord3 || '%'");

    query4.bindValue(":targetWord3", targetWord3);

    if (query4.exec() && query4.next()) {

        int count = query4.value("count").toInt();


        countString3 = QString::number(count);

    }

    QLabel* label1 = new QLabel(QString("Development: %1").arg(countString));
    QLabel* label2 = new QLabel(QString("Management: %1").arg(countString2));
    QLabel* label3 = new QLabel(QString("marketing: %1").arg(countString3));
    label1->setParent(page1);
    label2->setParent(page1);
    label3->setParent(page1);
    label1->setFont(setfonting(25,true));
    label2->setFont(setfonting(25,true));
    label3->setFont(setfonting(25,true));
    label1->setAlignment(Qt::AlignCenter);
    label2->setAlignment(Qt::AlignCenter);
    label3->setAlignment(Qt::AlignCenter);
    label1->setGeometry(0,0,418,200);
    label2->setGeometry(423,0,418,200);
    label3->setGeometry(846,0,418,200);
    label1->setStyleSheet("background-color: red;");
    label2->setStyleSheet("background-color: blue;");
    label3->setStyleSheet("background-color: green;");
    // Create the model and table view


    QSqlQuery query("SELECT * FROM employee");
    if (!query.exec()) {
        qDebug() << "Failed to execute query.";
        return;
    }

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("employee");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();


    QTableView* tableView = new QTableView(page1);
    tableView->setStyleSheet("background-color: darkgrey;");
    tableView->setModel(model);
    tableView->setFixedSize(950,400);
    tableView->move(0,200);
    tableView->setStyleSheet("background-image:url(:/images/table view.png)");

}

investor::~investor()
{
    delete ui;
}
