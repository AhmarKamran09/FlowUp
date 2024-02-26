#include "client.h"
#include "ui_client.h"
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
#include"QSqlError"

client::client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);


    QWidget *left=new QWidget(this);
    QStackedWidget *rightstacked=new QStackedWidget(this);
    QPushButton **a=new QPushButton*[5];
    QWidget **page = new QWidget*[7];


    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");
    if (!db2.open()) {
        qDebug() << "Failed to open database connection.";
        return;
    }
    QVBoxLayout *leftlayout=new QVBoxLayout(left);
    QLabel *icon= new QLabel;

    //setting colour of widgets

    left->setStyleSheet("background-color:green;");
    rightstacked->setStyleSheet("background-color: lightgreen;");
    this->setStyleSheet("background-color: black;");

    left->setGeometry(0,0,260,790);
    rightstacked->setGeometry(260,0,1276,790);

    icon->setFixedSize(260,200);
    icon->move(0,0);
    icon->setStyleSheet("background-image:url(:/images/left.png)");
    leftlayout->addWidget(icon);

    for (int i = 0; i < 5; i++) {
        a[i]= new QPushButton(left);
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
    a[1]->setText("ASSIGN PROJECT");
    a[2]->setText("RECEIVE PROJECT");
    a[3]->setText("FEEDBACK");
    a[4]->setText("ABOUT US");


    QHBoxLayout *main=new QHBoxLayout(this);

    main->addWidget(left);
    main->addWidget(rightstacked);
    this->setLayout(main);

    getinfo(page[0]);
    giveproject(page[1]);
    getcompletedproject(page[2]);
    sendfeedback(page[3]);
    about(page[5]);
    resources(page[6]);
    QVBoxLayout *set2=new QVBoxLayout(page[4]);
    set2->addWidget(page[5]);
    set2->addWidget(page[6]);


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
void client::giveproject(QWidget *page3){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");
    if (!db.open()) {
        qDebug() << "Failed to open database connection.";
        return;
    }
    QComboBox *comboBox1 = new QComboBox(page3);
    QString queryTable1 = "SELECT clientid FROM clienttable";
    QSqlQuery query1(db);
    query1.prepare(queryTable1);

    if (query1.exec()) {
        while (query1.next()) {
            QString columnName = query1.value(0).toString();
            comboBox1->addItem(columnName);
        }
    } else {
        qDebug() << "Failed to fetch data from table1:";
        // Handle the query error here
    }
    comboBox1->setGeometry(100, 100, 200, 30);

    QLabel* employeeLabel = new QLabel("Select Client ID :", page3);
    employeeLabel->setFont(setfonting(12,true));
    employeeLabel->setGeometry(100, 50, 200, 30);
    QComboBox* comboBox2 = new QComboBox(page3);
    QString queryTable2 = "SELECT companyid FROM companytable";
    QSqlQuery query2(db);
    query2.prepare(queryTable2);

    if (query2.exec()) {
        while (query2.next()) {
            QString columnName = query2.value(0).toString();
            comboBox2->addItem(columnName);
        }
    } else {
        qDebug() << "Failed to fetch data from table2:" ;
        // Handle the query error here
    }
    QLabel* projectLabel = new QLabel("Select Company ID:", page3);
    projectLabel->setFont(setfonting(12,true));
    projectLabel->setGeometry(100, 150, 200, 30);
    comboBox2->setGeometry(100, 200, 200, 30);
    // Create the label for Task ID
    QLabel* taskIDLabel = new QLabel("Project ID:", page3);

    taskIDLabel->setGeometry(100, 250, 200, 30);
    taskIDLabel->setFont(setfonting(12,true));
    // Create the QLineEdit for Task ID
    QLineEdit* taskIDLineEdit = new QLineEdit(page3);
    taskIDLineEdit->setGeometry(300, 250, 200, 30);

    // Create the label for Task Name
    QLabel* taskNameLabel = new QLabel("Project  Name:", page3);
    taskNameLabel->setGeometry(100, 300, 200, 30);
    taskNameLabel->setFont(setfonting(12,true));
    // Create the QLineEdit for Task Name
    QLineEdit* taskNameLineEdit = new QLineEdit(page3);
    taskNameLineEdit->setGeometry(300, 300, 200, 30);

    // Create the label for Details
    QLabel* detailsLabel = new QLabel("Project - Details:", page3);
    detailsLabel->setGeometry(100, 350, 200, 30);
    detailsLabel->setFont(setfonting(12,true));
    // Create the QTextEdit for Details
    QTextEdit* detailsTextEdit = new QTextEdit(page3);
    detailsTextEdit->setGeometry(300, 350, 400, 200);
    detailsTextEdit->setStyleSheet("background-image:url(:/images/table view.png)");

    // ...

    QPushButton* anotherButton = new QPushButton("Assign Now", page3);
    anotherButton->setGeometry(100, 600, 150, 30);
    anotherButton->setFont(setfonting(12,true));

    // Assuming you have already established a connection to the SQLite database

    // Connect the clicked signal to a custom slot
    QObject::connect(anotherButton, &QPushButton::clicked, [=, comboBox1]() {
        // Get the selected values from the comboboxes
        QString selectedEmployee = comboBox1->currentText();
        QString selectedProject = comboBox2->currentText();

        // Get the text from the line edits
        QString taskID = taskIDLineEdit->text();
        QString taskName = taskNameLineEdit->text();

        // Get the text from the text edit
        QString details = detailsTextEdit->toPlainText();
        QString date = "2/3/2024";

        // Prepare the SQL query
        //QSqlQuery query;
        QSqlQuery query;
        query.prepare("INSERT INTO pendingproject (Projectid, Projectname, Clientid, 'Project-Details', Deadline, companyid) VALUES (?,?,?,?,?,?)");

        // Bind the values to the query parameters
        query.addBindValue(taskID);
        query.addBindValue(taskName);
        query.addBindValue(selectedEmployee);
        query.addBindValue(details);
        query.addBindValue(date);
        query.addBindValue(selectedProject);

        // Execute the query
        if (query.exec()) {
            // Data added successfully
            qDebug() << "Data added to the database";
        } else {
            // Error occurred while adding data
            qDebug() << "Failed to add data to the database: " << query.lastError().text();
        }

        // Clear the line edits and text edit
        taskIDLineEdit->clear();
        taskNameLineEdit->clear();
        detailsTextEdit->clear();
    });








}
void client::getcompletedproject(QWidget *page5){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");
    if (!db.open()) {
        qDebug() << "Failed to open database connection.";
        return;
    }

QPushButton* displayButton = new QPushButton("Display Table", page5);
displayButton->setGeometry(20, 20, 120, 30);

// Create a table view
QTableView* tableView = new QTableView(page5);
tableView->setGeometry(20, 60, 600, 400);
// Create a model to retrieve data from the database
QSqlTableModel* tableModel = new QSqlTableModel(page5, db);
tableModel->setTable("pendingproject"); // Set the table name
tableModel->select(); // Retrieve the data from the table

// Set the model for the table view
tableView->setModel(tableModel);

// Connect the button's clicked signal to display the table
connect(displayButton, &QPushButton::clicked, [=]() {
    tableModel->select(); // Refresh the data in the model
});


}
void client::sendfeedback(QWidget *page3){

    QLabel* clientIdLabel = new QLabel("Select Project with Project id:", page3);
    clientIdLabel->setGeometry(20, 40, 200, 30);

    QComboBox* comboBox1 = new QComboBox(page3);
    comboBox1->setGeometry(220, 40, 150, 30);

    QSqlQuery query1;
    query1.prepare("SELECT Projectid FROM completedproject");
    if (!query1.exec()) {
        qDebug() << "Failed to execute query for table1.";
        return;
    }
    while (query1.next()) {
        QString value = query1.value(0).toString();
        comboBox1->addItem(value);
    }

    QLabel* feedbackLabel = new QLabel("Send Your Feedback:", page3);
    feedbackLabel->setGeometry(20, 90, 150, 30);

    QTextEdit* feedbackTextEdit = new QTextEdit(page3);
    feedbackTextEdit->setGeometry(20, 130, 400, 200);

    QPushButton* sendButton = new QPushButton("Send", page3);
    sendButton->setGeometry(20, 350, 100, 30);

    connect(sendButton, &QPushButton::clicked, [=]() {
        QString feedback = feedbackTextEdit->toPlainText();
        QString projectid = comboBox1->currentText();

        QSqlQuery query;
        query.prepare("UPDATE completedproject SET feedback = ? WHERE Projectid = ?");
        query.addBindValue(feedback);
        query.addBindValue(projectid);
        if (query.exec()) {
            qDebug() << "Feedback inserted into the database.";
            feedbackTextEdit->clear();
        } else {
            qDebug() << "Error: Failed to insert feedback into the database.";
        }
    });


}

void client::getinfo(QWidget*page1){


        // Set up the database connection
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db"); // Replace with your SQLite database file name

        if (!db.open()) {
            // Connection failed
            qDebug() << "Failed to open the database.";
            return;
        }

        // Create input field for client ID
        QLineEdit* clientIdLineEdit = new QLineEdit(page1);
        clientIdLineEdit->setGeometry(50, 30, 200, 20); // Adjust position and size as needed
        clientIdLineEdit->show();

        QLabel *w=new QLabel("Enter Your ClientId:",page1);
        w->setGeometry(50, 10, 200, 20);
        w->show();

            QLabel* clientIdLabel = new QLabel(page1);
            QLabel* clientNameLabel = new QLabel(page1);
            QLabel* passwordLabel = new QLabel(page1);
            QLabel* firstNameLabel = new QLabel(page1);
            QLabel* lastNameLabel = new QLabel(page1);

        // Create button to retrieve information
        QPushButton* getInfoButton = new QPushButton("Get Info", page1);
        getInfoButton->setGeometry(50, 80, 80, 20); // Adjust position and size as needed
        getInfoButton->show();

        // Connect button click event to retrieve information

        QObject::connect(getInfoButton, &QPushButton::clicked, [=]() {
                QString clientId = clientIdLineEdit->text();

                // Execute query and retrieve data based on the entered client ID
                QSqlQuery query;
                query.prepare("SELECT clientid, username, password, firstname, lastname FROM clienttable WHERE clientid = ?");
                query.addBindValue(clientId);

                if (query.exec() && query.next()) {
                    QString clientName = query.value(1).toString();
                    QString password = query.value(2).toString();
                    QString firstName = query.value(3).toString();
                    QString lastName = query.value(4).toString();

                    // Update label text with retrieved values
                    // Update label text with retrieved values
                    clientIdLabel->setText("<html><b>Client ID:</b> " + clientId + "</html>");
                    clientNameLabel->setText("<html><b>Client Name:</b> " + clientName + "</html>");
                    passwordLabel->setText("<html><b>Password:</b> " + password + "</html>");
                    firstNameLabel->setText("<html><b>First Name:</b> " + firstName + "</html>");
                    lastNameLabel->setText("<html><b>Last Name:</b> " + lastName + "</html>");


                    // Set label geometry
                    clientIdLabel->setGeometry(50, 120, 200, 20); // Adjust position and size as needed
                    clientNameLabel->setGeometry(50, 150, 200, 20);
                    passwordLabel->setGeometry(50, 180, 200, 20);
                    firstNameLabel->setGeometry(50, 210, 200, 20);
                    lastNameLabel->setGeometry(50, 240, 200, 20);

                    // Show labels
                    clientIdLabel->show();
                    clientNameLabel->show();
                    passwordLabel->show();
                    firstNameLabel->show();
                    lastNameLabel->show();
                } else {
                    // No data found or error occurred
                    clientIdLabel->clear();
                    clientNameLabel->clear();
                    passwordLabel->clear();
                    firstNameLabel->clear();
                    lastNameLabel->clear();
                    qDebug() << "No data found or an error occurred.";
                }
            });
        // Create button to retrieve all values

        QPushButton* showAllButton = new QPushButton("Show All", page1);
       showAllButton->setGeometry(50, 270, 80, 20); // Adjust position and size as needed
        showAllButton->show();
        // Create a table view to display the data
        QTableView* tableView = new QTableView(page1);
     tableView->setGeometry(50, 300, 400, 200);// Adjust position and size as needed
        tableView->show();

        // Create a QSqlQueryModel as the model for the table view
        QSqlQueryModel* model = new QSqlQueryModel(tableView);

        // Connect the "Show All" button click event to retrieve and display all values
        QObject::connect(showAllButton, &QPushButton::clicked, [=]() {
            QString clientId = clientIdLineEdit->text();

            // Execute query and retrieve all values based on the entered client ID
            QSqlQuery query;
            query.prepare("SELECT * FROM clienttable WHERE clientid = ?");
            query.addBindValue(clientId);

            if (query.exec()) {
                // Set the query result as the model for the table view
                model->setQuery(query);

                // Set the header labels for the columns
                model->setHeaderData(0, Qt::Horizontal, "Client ID");
                model->setHeaderData(1, Qt::Horizontal, "Client Name");
                model->setHeaderData(2, Qt::Horizontal, "Password");
                model->setHeaderData(3, Qt::Horizontal, "First Name");
                model->setHeaderData(4, Qt::Horizontal, "Last Name");

                // Set the model for the table view
                tableView->setModel(model);

            } else {
                // No data found or error occurred
                qDebug() << "No data found or an error occurred.";
            }
        });




}

client::~client()
{
    delete ui;
}
