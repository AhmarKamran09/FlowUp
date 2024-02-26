#include "employee.h"
#include "ui_employee.h"
#include<QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QFileDialog>
#include <QLineEdit>
#include <QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QFileInfo>
#include<QSqlTableModel>
#include<QFont>
employee::employee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::employee)
{
     ui->setupUi(this);
    QWidget *left1=new QWidget(this);
    QStackedWidget *rightstacked=new QStackedWidget(this);
    QPushButton **a=new QPushButton*[5];
    QWidget **page = new QWidget*[7];


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");
    if (!db.open()) {
        qDebug() << "Failed to open database connection.";
        return;
    }
    QVBoxLayout *leftlayout=new QVBoxLayout(left1);
    QLabel *icon= new QLabel;
    icon->setFixedSize(260,200);
    icon->move(0,0);
    leftlayout->addWidget(icon);
    left1->setStyleSheet("background-color:green;");
    rightstacked->setStyleSheet("background-color: lightgreen;");
    this->setStyleSheet("background-color: black;");
    icon->setStyleSheet("background-image:url(:/images/left.png)");
    left1->setGeometry(0,0,260,790);
    rightstacked->setGeometry(260,0,1276,790);


    icon->setFixedSize(260,200);
    icon->move(-3,-5);
    leftlayout->addWidget(icon);
    for (int i = 0; i < 5; i++) {
        a[i]= new QPushButton(left1);
        leftlayout->addWidget(a[i]);
        a[i]->setFixedSize(250,60);
        //QPalette palette = a[i]->palette();
        //  palette.setColor(QPalette::ButtonText, QColor(Qt::white)); // Set the text color to red
        //  a[i]->setPalette(palette);

        page[i] = new QWidget;
        rightstacked->addWidget(page[i]);
        a[i]->setStyleSheet("QPushButton { background-color: lightgreen; border-radius: 10px; }");
        a[i]->setFont(setfonting(12,true));
    }
    for (int i = 5; i<7; ++i) {
        page[i] = new QWidget;
    }
    a[0]->setText("MY PROFILE");
    a[1]->setText("PENDING TASKS");
    a[2]->setText("SEND TASK");
    a[3]->setText("NOTIFICATIONS");
    a[4]->setText("ABOUT US");


    QHBoxLayout *main=new QHBoxLayout(this);

    main->addWidget(left1);
    main->addWidget(rightstacked);
    this->setLayout(main);

    getinfo(page[0]);
    sendtask_to_ceo(page[2]);
    seependingtasks(page[1]);
    notifications(page[3]);
    about(page[5]);
    resources(page[6]);

    QVBoxLayout *set1=new QVBoxLayout(page[4]);
    set1->addWidget(page[5]);
    set1->addWidget(page[6]);


    connect(a[0], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,0,0,5);
    });

    connect(a[1], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,1,1,5);
    });

    connect(a[2], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,2,2,5);
    });

    connect(a[3], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,3,3,5);
    });

    connect(a[4], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,4,4,5);
    });


}


void employee::getinfo(QWidget *page0)
{
    QComboBox *employee1=new QComboBox(page0);
    QComboBox *employee2=new QComboBox(page0);
    employee1->setStyleSheet("background-color:white;");
    employee2->setStyleSheet("background-color:white;");

    page0->setStyleSheet("background-image:url(:/images/table view.png)");
    employee1->addItem("male");
    employee1->addItem("female");
    employee1->addItem("non-binary");

    employee2->addItem("Management");
    employee2->addItem("Marketing");
    employee2->addItem("Development");
    employee2->addItem("Accounts");
    employee2->addItem("Operations");
    QLabel **empinfo = new QLabel*[7];
    QLineEdit **info = new QLineEdit*[7];
    QPushButton *deletebutton=new QPushButton(page0);
    deletebutton->setText("SHOW");
    deletebutton->setStyleSheet("background-color:red;");

    QLabel *heading=new QLabel(page0);
    heading->setText("MY PROFILE");
    heading->setFont(setfonting(24,true));
    heading->setGeometry(400,0,300,44);
    heading->setStyleSheet("background-color:darkgreen;");


    for (int i = 0; i < 7; i++) {
        empinfo[i] = new QLabel(page0);
        empinfo[i]->setStyleSheet("background-color:darkgreen;");
        empinfo[i]->setFont(setfonting(12,true));
    }

    for (int i = 0; i < 5; i++) {
        info[i] = new QLineEdit(page0);


        info[i]->setStyleSheet("background-color: white;");
    }

    empinfo[0]->setText("NAME");
    empinfo[1]->setText("ID");
    empinfo[2]->setText("GENDER");
    empinfo[3]->setText("EMAIL");
    empinfo[4]->setText("CONTACT NO.");
    empinfo[5]->setText("DESIGNATION");
    empinfo[6]->setText("ADDRESS");

    deletebutton->setGeometry(850,325,200, 30);

    empinfo[0]->setGeometry(5,45,200, 30);
    empinfo[1]->setGeometry(5,125,200, 30);
    empinfo[2]->setGeometry(5,205,200, 30);
    empinfo[3]->setGeometry(650,45,200, 30);
    empinfo[4]->setGeometry(650,125,200, 30);
    empinfo[5]->setGeometry(650,205,200, 30);
    info[0]->setGeometry(5,85,400, 30);
    info[1]->setGeometry(5,165,400, 30);
    employee1->setGeometry(5,245,400, 30);
    info[2]->setGeometry(650,85,400, 30);
    info[3]->setGeometry(650,165,400, 30);
    employee2->setGeometry(650,245,400, 30);
    empinfo[6]->setGeometry(5,285,200, 30);
    info[4]->setGeometry(5,325,800, 30);


    QObject::connect(deletebutton, &QPushButton::clicked, [=]() {
        QString name = info[0]->text();
        QString id = info[1]->text();
        QString gender = employee1->currentText();
        QString email = info[2]->text();
        QString contactNo = info[3]->text();
        QString designation = employee2->currentText();
        QString address = info[4]->text();

        // Create a connection to the SQLite database
        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");

        // Open the database
        if (!database.open()) {
            // Handle the error if the database fails to open
            qDebug() << "Database error:" ;
            return;
        }

        // Prepare the SQL query
        QSqlQuery query;
        query.prepare("INSERT INTO employee ( employeeid,employeename, address,contactno, email, designation,Gender) "
                      "VALUES (:id, :name, :address, :contactNo, :email, :designation, :gender)");
        query.bindValue(":name", name);
        query.bindValue(":id", id);
        query.bindValue(":gender", gender);
        query.bindValue(":email", email);
        query.bindValue(":contactNo", contactNo);
        query.bindValue(":designation", designation);
        query.bindValue(":address", address);

        // Execute the query
        if (!query.exec()) {
            // Handle the error if the query fails to execute
           qDebug()<<"Error";
        }

        // Close the database connection
        database.close();

        // Clear the line edits and comboboxes after insertion
        info[0]->clear();
        info[1]->clear();
        info[2]->clear();
        info[3]->clear();
        info[4]->clear();
        employee1->setCurrentIndex(0);
        employee2->setCurrentIndex(0);
    });

}
void employee:: sendtask_to_ceo(QWidget *page2){

    QTextEdit* textEdit = new QTextEdit(page2);
    textEdit->setGeometry(100, 280, 400, 200);
    textEdit->setStyleSheet("background-image:url(:/images/table view.png)");


    QLabel* detailLabel = new QLabel("Detail:", page2);
    detailLabel->setFont(setfonting(12,true));
    detailLabel->setGeometry(100, 250, 100, 20);

       QString text = textEdit->toPlainText();
        QLabel* taskIDLabel = new QLabel("Task ID:", page2);
       taskIDLabel->setFont(setfonting(12,true));
            QLineEdit* taskIDLineEdit = new QLineEdit(page2);
             taskIDLineEdit->setGeometry(300, 50, 200, 20);
              taskIDLabel->setGeometry(100, 50, 200, 20);
            // Create QLabel and QLineEdit for Task Name
            QLabel* taskNameLabel = new QLabel("Task Name:", page2);
              taskNameLabel->setFont(setfonting(12,true));
            QLineEdit* taskNameLineEdit = new QLineEdit(page2);
            taskNameLineEdit->setGeometry(300, 100, 200, 20);
            taskNameLabel->setGeometry(100, 100, 200, 20);
             // Create QLabel and QLineEdit for Created By
            QLabel* createdByLabel = new QLabel("Created By:", page2);
            createdByLabel->setFont(setfonting(12,true));
            QLineEdit* createdByLineEdit = new QLineEdit(page2);
            createdByLineEdit->setGeometry(300, 150, 200, 20);
            createdByLabel->setGeometry(100, 150, 200, 20);
            // Create QLabel and QLineEdit for Project ID
            QLabel* projectIDLabel = new QLabel("Project ID:", page2);
            QLineEdit* projectIDLineEdit = new QLineEdit(page2);
            projectIDLabel->setFont(setfonting(12,true));
            projectIDLineEdit->setGeometry(300, 200, 200, 20);
             projectIDLabel->setGeometry(100, 200, 200, 20);
             QPushButton* button = new QPushButton("Send Task", page2);
            button->setGeometry(100, 500, 150, 30);
             button->setFont(setfonting(12,true));
            QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
            database.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db"); // Replace with your database name
            if (!database.open()) {
                qDebug() << "Failed to open the database.";
            }

            // Connect the button's clicked() signal to a lambda function for database insertion
            connect(button, &QPushButton::clicked, this, [=]() {
                // Get the text from the QTextEdit and QLineEdit fields
                QString text = textEdit->toPlainText();
                QString taskID = taskIDLineEdit->text();
                QString taskName = taskNameLineEdit->text();
                QString createdBy = createdByLineEdit->text();
                QString projectID = projectIDLineEdit->text();

                // Execute the SQL query to insert the string into the database
                QSqlQuery query(database);
                query.prepare("INSERT INTO completedtasks (TaskId, TaskName, Details, ProjectId,Created_by) "
                              "VALUES (:taskID,  :taskName,:text, :projectID, :Created_by)");
               query.bindValue(":taskID", taskID);
                query.bindValue(":taskName", taskName);
                 query.bindValue(":text", text);
              query.bindValue(":projectID", projectID);
               query.bindValue(":createdBy", createdBy);

                if (!query.exec()) {
                    qDebug() << "Failed to execute the query.";
                }
            });





}
void employee:: seependingtasks(QWidget *page3){


    QSqlQuery query2("SELECT * FROM taskassign");
    if (!query2.exec()) {
        qDebug() << "Failed to execute query.";
        return;
    }

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("taskassign");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    QTableView* tableView = new QTableView(page3);
    tableView->setStyleSheet("background-color: white;");
    tableView->setModel(model);
    tableView->move(5,45);
    tableView->resize(950,400);

}
void employee:: notifications(QWidget *page5){
    QTextEdit* textEdit = new QTextEdit(page5);
    textEdit->setGeometry(50, 50, 1000, 500);
    textEdit->setStyleSheet("background-image:url(:/images/table view.png)");


    // Create a button to open the file
    QPushButton* openButton = new QPushButton("See Notifications", page5);
    openButton->setFont(setfonting(12,true));

    openButton->setGeometry(500, 600, 300, 50);

    // Connect the button's clicked signal to a slot
    connect(openButton, &QPushButton::clicked, this, [=]() {
        // Open a file dialog to select a file
        QString filePath = QFileDialog::getOpenFileName(page5, "Open File");

        if (!filePath.isEmpty()) {
            // Read the contents of the file
            QFile file(filePath);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                QString fileContents = in.readAll();
                file.close();

                // Add the current time to the file content
                QString currentTime = QTime::currentTime().toString("hh:mm:ss");
                QString contentWithTime = "[" + currentTime + "] " + fileContents;

                // Set the file content with time in the QTextEdit
                textEdit->setText(contentWithTime);
            }
        }
    });



}


employee::~employee()
{
    delete ui;
}
