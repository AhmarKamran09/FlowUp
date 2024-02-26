#include "ceo.h"
#include "ui_ceo.h"
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

// CEO class constructor
CEO::CEO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CEO)
{
    ui->setupUi(this);

    // Creating the left and right sections of the main window


    QWidget *left=new QWidget(this);
    QStackedWidget *rightstacked=new QStackedWidget(this);
    // Creating an array of QPushButton and QWidget objects

    QPushButton **a=new QPushButton*[8];
    QWidget **page = new QWidget*[14];

    QVBoxLayout *leftlayout=new QVBoxLayout(left);
    QLabel *icon= new QLabel;


 // Setting up the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");
    if (!db.open()) {
        qDebug() << "Failed to open database connection.";
        return;
    }

    // Setting the geometry and stylesheets for the left and right sections
    left->setGeometry(0,0,260,790);
    rightstacked->setGeometry(260,0,1276,790);

    icon->setFixedSize(260,200);
    icon->move(0,0);
    leftlayout->addWidget(icon);
    left->setStyleSheet("background-color:green;");
    rightstacked->setStyleSheet("background-color: lightgreen;");
    this->setStyleSheet("background-color: black;");
    icon->setStyleSheet("background-image:url(:/images/left.png)");
    // Creating and setting up buttons in the left section

    for (int i = 0; i < 8; i++) {
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

    // Creating additional pages for the right section
    for (int i = 8; i < 14; i++) {
        page[i] = new QWidget;
    }

    // Setting the text for the buttons in the left section

    a[0]->setText("INFORMATION OF EMPLOYEES");
    a[1]->setText("DELIVER PROJECT");
    a[2]->setText("ADD NOTIFICATION");
    a[3]->setText("SEND REPORT");
    a[4]->setText("ASSIGN TASKS");
    a[5]->setText("TASKS");
    a[6]->setText("PROJECT DETAILS");
    a[7]->setText("ABOUT US");

    // Setting up the layout for the main window
    QHBoxLayout *main=new QHBoxLayout(this);

    main->addWidget(left);
    main->addWidget(rightstacked);
    this->setLayout(main);

    // Setting up the functionality for each button click
    getinfo(page[0]);
    getpendingprojectdetails(page[10]);
    seecompletedprojects(page[11]);
    about(page[12]);
    resources(page[13]);
    send_project_to_client(page[1]);
    assigntask(page[8]);
    receivetask_from_employee(page[9]);
    sendreport_to_founder_of_comp_project(page[3]);
    receive_details_from_founder(page[4]);
    addnotification(page[2]);

    //setting up layouts
    QVBoxLayout *set1=new QVBoxLayout(page[5]);
    QVBoxLayout *set2=new QVBoxLayout(page[6]);
    QVBoxLayout *set3=new QVBoxLayout(page[7]);
    set1->addWidget(page[8]);
    set1->addWidget(page[9]);
    set2->addWidget(page[10]);
    set2->addWidget(page[11]);
    set3->addWidget(page[12]);
    set3->addWidget(page[13]);


//connecting button
    connect(a[0], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,0,0,8);
    });

    connect(a[1], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,1,1,8);
    });

    connect(a[2], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,2,2,8);
    });

    connect(a[3], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,3,3,8);
    });

    connect(a[4], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,4,4,8);
    });

    connect(a[5], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,5,5,8);
    });

    connect(a[6], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,6,6,8);
    });

    connect(a[7], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,7,7,8);
    });
}




void CEO::send_project_to_client(QWidget *page){
    QComboBox *project=new QComboBox(page);
    project->setGeometry(5,5,300,40);
    QComboBox *project2=new QComboBox(page);
    project2->setGeometry(400,5,300,40);


    //Select Projectname and projectid from completedproject
    QSqlQuery query;
    if (query.exec("SELECT ProjectId, ProjectName FROM completedproject")) {

        while (query.next()) {
            QString column1Value = query.value(0).toString();
            QString column2Value = query.value(1).toString();

            project->addItem(column1Value);
            project2->addItem(column2Value);
        }
    } else {

        QMessageBox::critical(page, "Error", "Failed to retrieve values from the database.");
    }
    QPushButton *showTableButton = new QPushButton("Show Table", page);
    showTableButton->setGeometry(400, 60, 100, 30);

    // Connect the button's clicked signal to a slot
    connect(showTableButton, &QPushButton::clicked, this, [=]() {

        // Get the current text of the comboboxes
        QString pid = project->currentText();
        QString pname = project2->currentText();

        // Filter the data in the completedproject table
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(QString("SELECT * FROM completedproject WHERE ProjectId = '%1' AND ProjectName = '%2'").arg(pid, pname));

        // Display the filtered data in the table view
        QTableView* tableView = new QTableView(page);
        tableView->setStyleSheet("background-color: darkgrey;");
        tableView->setModel(model);
        tableView->move(5, 100);
        tableView->resize(950, 400);
        tableView->show();
    });

    // Create a line edit
    QLineEdit *lineEdit = new QLineEdit(page);
    lineEdit->setGeometry(5, 60, 200, 30);

    // Create a button to insert the value
    QPushButton *insertValueButton = new QPushButton("Enter Your End-Remarks", page);
    insertValueButton->setGeometry(210, 60, 150, 30);


    connect(insertValueButton, &QPushButton::clicked, this, [=]() {
        QString valueToInsert = lineEdit->text();
        QString pid = project->currentText();
        QString pname = project2->currentText();

        // Perform the insertion into the specific column
        QSqlQuery query;
        query.prepare("UPDATE completedproject SET End-Remarks = :value WHERE ProjectId = :pid AND ProjectName = :pname");
        query.bindValue(":value", valueToInsert);
        query.bindValue(":pid", pid);
        query.bindValue(":pname", pname);

        if (query.exec()) {
            // Update the model to reflect the changes

        } else {
            qDebug() << "Failed to execute query: " ;
        }
    });


}
void CEO::assigntask(QWidget *page1){
    QLabel *assigntasktoemployee= new QLabel(page1);
    assigntasktoemployee->setGeometry(450,5,350,40);
    assigntasktoemployee->setText("Tasks Assign to  Employees");
    assigntasktoemployee->setFont(setfonting(18,true));
    QComboBox *employee=new QComboBox(page1);
    employee->setGeometry(5,5,300,40);
    QSqlQuery query;
    if (query.exec("SELECT ProjectId FROM taskassign")) {

        while (query.next()) {
            QString columnValue = query.value(0).toString();
            employee->addItem(columnValue);
        }

    }
    QSqlQuery query2("SELECT * FROM taskassign");
    if (!query2.exec()) {
        qDebug() << "Failed to execute query.";
        return;
    }

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("taskassign");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    QTableView* tableView = new QTableView(page1);
    tableView->setStyleSheet("background-color: darkgrey;");
    tableView->setModel(model);
    tableView->move(5,45);
    tableView->resize(950,400);
    tableView->setStyleSheet("background-image:url(:/images/table view.png)");


}
void CEO::receivetask_from_employee(QWidget *page2){
    QLabel *assigntasktoemployee= new QLabel(page2);
    QComboBox *employee=new QComboBox(page2);
    employee->setGeometry(5,5,300,40);
    QSqlQuery query;
    if (query.exec("SELECT ProjectId FROM taskcompleted")) {

        while (query.next()) {
            QString columnValue = query.value(0).toString();
            employee->addItem(columnValue);
        }

    }
    assigntasktoemployee->setText("Task Receiving from Employees");
    assigntasktoemployee->setGeometry(450,5,370,40);
    assigntasktoemployee->setFont(setfonting(18,true));

    //sqlquery
    QSqlQuery query2("SELECT * FROM taskcompleted");
    if (!query2.exec()) {
        qDebug() << "Failed to execute query.";
        return;
    }

    //table view model for tasks
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("taskcompleted");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    QTableView* tableView = new QTableView(page2);
    tableView->setStyleSheet("background-color: darkgrey;");
    tableView->setModel(model);
    tableView->move(5,45);
    tableView->resize(950,400);
    tableView->setStyleSheet("background-image:url(:/images/table view.png)");


}
void CEO::sendreport_to_founder_of_comp_project(QWidget *page3){

    QTextEdit* reportTextEdit = new QTextEdit(page3);

    reportTextEdit->setStyleSheet("background-image:url(:/images/table view.png)");
    reportTextEdit->setGeometry(50,50,1000,500);
    // Create a button to open the file dialog
    QPushButton* saveButton = new QPushButton("Save Report", page3);
    saveButton->setGeometry(500,600,260,40);
    saveButton->setFont(setfonting(12,true));
    // Connect the button's clicked signal to a slot that opens the file dialog
    QObject::connect(saveButton, &QPushButton::clicked, [page3, reportTextEdit]() {
        // Get the file path from the file dialog
        QString filePath = QFileDialog::getSaveFileName(page3, "Save Report", "", "Text Files (*.txt)");

        // Check if a file path was selected
        if (!filePath.isEmpty()) {
            QString reportText = reportTextEdit->toPlainText();

            // Get the current date and time
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString dateTimeString = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");

            // Append the date and time to the report text
            QString reportWithDateTime = QString("Report Date & Time: %1\n\n%2").arg(dateTimeString, reportText);

            // Open the file for writing
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                // Create a text stream to write the report
                QTextStream out(&file);

                // Write the report text to the file
                out << reportWithDateTime;

                // Close the file
                file.close();

                // Display a message to the user indicating the report was sent successfully
                QMessageBox::information(page3, "Report Sent", "The report has been sent to the founder successfully.");
            } else {
                // Display an error message if there was an issue opening the file
                QMessageBox::critical(page3, "Error", "Failed to save the report.");
            }
        }
    });

}
void CEO::receive_details_from_founder(QWidget *page4){



QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");


if (!db.open()) {
    qDebug() << "Failed to connect to the database:";


}

QComboBox *comboBox1 = new QComboBox(page4);
QString queryTable1 = "SELECT employeeid FROM employee";
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

QLabel* employeeLabel = new QLabel("Select Employee from ID:", page4);
employeeLabel->setFont(setfonting(12,true));
employeeLabel->setGeometry(100, 50, 200, 30);
QComboBox* comboBox2 = new QComboBox(page4);
QString queryTable2 = "SELECT projectid FROM pendingproject";
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
QLabel* projectLabel = new QLabel("Select Project from ID:", page4);
projectLabel->setFont(setfonting(12,true));
projectLabel->setGeometry(100, 150, 200, 30);
comboBox2->setGeometry(100, 200, 200, 30);
// Create the label for Task ID
QLabel* taskIDLabel = new QLabel("Task ID:", page4);

taskIDLabel->setGeometry(100, 250, 200, 30);
taskIDLabel->setFont(setfonting(12,true));
// Create the QLineEdit for Task ID
QLineEdit* taskIDLineEdit = new QLineEdit(page4);
taskIDLineEdit->setGeometry(300, 250, 200, 30);

// Create the label for Task Name
QLabel* taskNameLabel = new QLabel("Task Name:", page4);
taskNameLabel->setGeometry(100, 300, 200, 30);
taskNameLabel->setFont(setfonting(12,true));
// Create the QLineEdit for Task Name
QLineEdit* taskNameLineEdit = new QLineEdit(page4);
taskNameLineEdit->setGeometry(300, 300, 200, 30);

// Create the label for Details
QLabel* detailsLabel = new QLabel("Details:", page4);
detailsLabel->setGeometry(100, 350, 200, 30);
detailsLabel->setFont(setfonting(12,true));
// Create the QTextEdit for Details
QTextEdit* detailsTextEdit = new QTextEdit(page4);
detailsTextEdit->setGeometry(300, 350, 400, 200);
detailsTextEdit->setStyleSheet("background-image:url(:/images/table view.png)");

// Create the button
QPushButton* anotherButton = new QPushButton("Assign Now", page4);
anotherButton->setGeometry(100, 600, 150, 30);
anotherButton->setFont(setfonting(12,true));
// Assuming you have already established a connection to the SQLite database

// Connect the clicked signal to a custom slot
QObject::connect(anotherButton, &QPushButton::clicked, [=]() {
    // Get the selected values from the comboboxes
    QString selectedEmployee = comboBox1->currentText();
    QString selectedProject = comboBox2->currentText();

    // Get the text from the line edits
    QString taskID = taskIDLineEdit->text();
    QString taskName = taskNameLineEdit->text();

    // Get the text from the text edit
    QString details = detailsTextEdit->toPlainText();

    // Prepare the SQL query
    QSqlQuery query;
    query.prepare("INSERT INTO taskassign (Taskid, Taskname, EmployeeId, ProjectId, details) "
                  "VALUES (:taskID, :taskName, :selectedEmployee, :selectedProject, :details)");

    // Bind the values to the query parameters
    query.bindValue(":selectedEmployee", selectedEmployee);
    query.bindValue(":selectedProject", selectedProject);
    query.bindValue(":taskID", taskID);
    query.bindValue(":taskName", taskName);
    query.bindValue(":details", details);

    // Execute the query
    if (query.exec()) {
        // Data added successfully
        qDebug() << "Data added to the database";
    } else {
        // Error occurred while adding data
        qDebug() << "Failed to add data to the database: " ;
    }

    // Clear the line edits and text edit
    taskIDLineEdit->clear();
    taskNameLineEdit->clear();
    detailsTextEdit->clear();
});


}

CEO::~CEO()
{
    delete ui;
}

