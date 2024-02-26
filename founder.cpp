#include "founder.h"
#include "ui_founder.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QFileInfo>
#include<QSqlTableModel>
#include<QFileDialog>
#include<QMessageBox>
#include "calendar.h"
founder::founder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::founder)
{
    ui->setupUi(this);
    QWidget *left=new QWidget(this);
    QStackedWidget *rightstacked=new QStackedWidget(this);
    QPushButton **a=new QPushButton*[6];
    QWidget **page = new QWidget*[12];
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");
    if (!db1.open()) {
        qDebug() << "Failed to open database connection.";
        return;

}
    QVBoxLayout *leftlayout=new QVBoxLayout(left);
    QLabel *icon= new QLabel;

    //setting geometry of widgets
    left->setGeometry(0,0,260,790);
    rightstacked->setGeometry(260,0,1276,790);

    icon->setFixedSize(280,210);
    icon->move(0,0);
    left->setStyleSheet("background-color:green;");
    rightstacked->setStyleSheet("background-color: lightgreen;");
    this->setStyleSheet("background-color: black;");
    icon->setStyleSheet("background-image:url(:/images/left.png)");
    leftlayout->addWidget(icon);
    for (int i = 0; i < 6; i++) {
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

    for (int i =6; i < 12; i++) {
        page[i] = new QWidget;
    }

    a[0]->setText("INFORMATION OF EMPLOYEES");
    a[1]->setText("RECEIVE REPORT");
    a[2]->setText("ADD NOTIFICATION");
    a[3]->setText(" PROJECTS DETAILS");//2
    a[4]->setText("UPDATE EMPLOYEE");//2
    a[5]->setText("ABOUT US");//2
    QHBoxLayout *main=new QHBoxLayout(this);


    main->addWidget(left);
    main->addWidget(rightstacked);
    this->setLayout(main);

    getinfo(page[0]);
    getpendingprojectdetails(page[6]);
    seecompletedprojects(page[7]);
    about(page[10]);
    resources(page[11]);

    addemployee(page[8]);
    delemployee(page[9]);
    receivereport_of_comp_task(page[1]);
    addnotification(page[2]);
    QVBoxLayout *set1=new QVBoxLayout(page[3]);
    QVBoxLayout *set2=new QVBoxLayout(page[4]);
     QVBoxLayout *set3=new QVBoxLayout(page[5]);
    set1->addWidget(page[6]);
    set1->addWidget(page[7]);
    set2->addWidget(page[8]);
    set2->addWidget(page[9]);
    set3->addWidget(page[10]);
    set3->addWidget(page[11]);


    connect(a[0], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,0,0,6);
    });

    connect(a[1], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,1,1,6);
    });

    connect(a[2], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,2,2,6);
    });

    connect(a[3], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,3,3,6);
    });

    connect(a[4], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,4,4,6);
    });

    connect(a[5], &QPushButton::clicked, [this,a,rightstacked]() {
        this->setpagedesign(a, rightstacked,5,5,6);
    });

}

void founder::addemployee(QWidget *page0){
    QComboBox *employee1=new QComboBox(page0);
    QComboBox *employee2=new QComboBox(page0);

    employee1->addItem("Male");
    employee1->addItem("Female");
    employee1->addItem("Non-Binary");

    employee2->addItem("Management");
    employee2->addItem("Marketing");
    employee2->addItem("Development");
    employee2->addItem("Accounts");
    employee2->addItem("Operations ");





    QLabel **empinfo = new QLabel*[7];
    QLineEdit **info = new QLineEdit*[7];
    QPushButton *deletebutton=new QPushButton(page0);
    deletebutton->setText("ADD");

    deletebutton->setFont(setfonting(15,true));

    QLabel *heading=new QLabel(page0);
    heading->setText("ADD EMPLOYEE");
    heading->setGeometry(400,0,300,44);
    heading->setStyleSheet("background-color: white;");
    heading->setFont(setfonting(18,true));

    for (int i = 0; i < 5; i++) {
        info[i] = new QLineEdit(page0);
    }

    for (int i = 0; i < 7; i++) {
        empinfo[i] = new QLabel(page0);

        empinfo[i]->setFont(setfonting(12,true));

    }

    empinfo[0]->setText("NAME");
    empinfo[1]->setText("ID");
    empinfo[2]->setText("GENDER");
    empinfo[3]->setText("EMAIL");
    empinfo[4]->setText("CONTACT NO.");
    empinfo[5]->setText("DESIGNATION");
    empinfo[6]->setText("ADDRESS");

    deletebutton->setGeometry(850,325,200, 30);

    empinfo[0]->setGeometry(5,45,70, 30);
    empinfo[1]->setGeometry(5,125,50, 30);
    empinfo[2]->setGeometry(5,205,70, 30);
    empinfo[3]->setGeometry(650,45,80, 30);
    empinfo[4]->setGeometry(650,125,120, 30);
    empinfo[5]->setGeometry(650,205,120, 30);
    info[0]->setGeometry(5,85,400, 30);
    info[1]->setGeometry(5,165,400, 30);
    employee1->setGeometry(5,245,400, 30);
    info[2]->setGeometry(650,85,400, 30);
    info[3]->setGeometry(650,165,400, 30);
    employee2->setGeometry(650,245,400, 30);
    empinfo[6]->setGeometry(5,285,80, 30);
    info[4]->setGeometry(5,325,800, 30);
    page0->setStyleSheet("background-image:url(:/images/deleteemployee.png)");


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

void founder::delemployee(QWidget *page1){

    page1->setStyleSheet("background-image:url(:/images/deleteemployee.png)");

    QLabel **empinfo = new QLabel*[2];
    QLineEdit **info = new QLineEdit*[2];
    QPushButton *deleteButton = new QPushButton(page1);
    deleteButton->setText("DELETE");

    deleteButton->setFont(setfonting(15,true));

    QLabel *heading = new QLabel(page1);
    heading->setText("DELETE EMPLOYEE");
    heading->setFont(setfonting(18,true));
    heading->setGeometry(400, 0, 300, 44);
    heading->setStyleSheet("background-color: white;");

    for (int i = 0; i < 2; i++) {
        info[i] = new QLineEdit(page1);
        empinfo[i] = new QLabel(page1);
    }

    empinfo[0]->setText("NAME");
    empinfo[1]->setText("ID");

    empinfo[0]->setFont(setfonting(12,true));
    empinfo[1]->setFont(setfonting(12,true));

    deleteButton->setGeometry(400, 200, 200, 30);

    empinfo[0]->setGeometry(5, 45, 100, 30);
    empinfo[1]->setGeometry(5, 125, 50, 30);
    info[0]->setGeometry(5, 85, 400, 30);
    info[1]->setGeometry(5, 165, 400, 30);

    connect(deleteButton, &QPushButton::clicked, [info]() {
        QString name = info[0]->text();
        QString id = info[1]->text();
        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("C:/Users/Ahmar Kamran/OneDrive/Desktop/presentation/CRM Project/Databases/MainDatabase.db");

        //Open the database
        if (!database.open()) {
            // Handle the error if the database fails to open
            qDebug() << "Database error:" ;
            return;
        }
        // Assuming you have a valid database connection named 'dbConnection'
        QSqlQuery query(database);
        query.prepare("DELETE FROM employee WHERE employeename = :name AND employeeid = :id");
        query.bindValue(":name", name);
        query.bindValue(":id", id);

        if (query.exec()) {
            qDebug() << "Row deleted successfully!";
        } else {
            qDebug() << "Failed to delete row:" ;
        }
    });

}
void founder::receivereport_of_comp_task(QWidget *page5){


    QPushButton* openButton = new QPushButton("Open Report", page5);
     openButton->setGeometry(500,600,260,40);
       openButton->setFont(setfonting(12,true));
       // Create a QTextEdit widget to display the report content
       QTextEdit* reportTextEdit = new QTextEdit(page5);
     reportTextEdit->setReadOnly(true);
     reportTextEdit->setStyleSheet("background-image:url(:/images/table view.png)");

         reportTextEdit->setGeometry(50,50,1000,500);
       // Connect the button's clicked signal to a slot that opens the file dialog
       QObject::connect(openButton, &QPushButton::clicked, [page5, reportTextEdit]() {
           // Open the file dialog to select a text file
           QString filePath = QFileDialog::getOpenFileName(page5, "Open Report", "", "Text Files (*.txt)");

           // Check if a file was selected
           if (!filePath.isEmpty()) {
               // Open the file for reading
               QFile file(filePath);
               if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                   // Read the content of the file
                   QTextStream in(&file);
                   QString fileContent = in.readAll();

                   // Close the file
                   file.close();

                   // Set the file content to the QTextEdit widget
                   reportTextEdit->setPlainText(fileContent);
               } else {
                   // Display an error message if there was an issue opening the file
                   QMessageBox::critical(page5, "Error", "Failed to open the file.");
               }
           }
       });

}
void founder::addnotification(QWidget *page3){

    QTextEdit* notificationTextEdit = new QTextEdit(page3);

       notificationTextEdit->setStyleSheet("background-image:url(:/images/table view.png)");
    notificationTextEdit->setGeometry(50,50,1000,500);
        // Create a button to add the notification to the file
        QPushButton* addButton = new QPushButton("Add Notification", page3);

    addButton->setGeometry(500,600,260,40);
    addButton->setFont(setfonting(12,true));
        // Connect the button's clicked signal to a slot that adds the notification to the file
        QObject::connect(addButton, &QPushButton::clicked, [notificationTextEdit]() {
            // Get the notification text from the QTextEdit widget
            QString notificationText = notificationTextEdit->toPlainText();

            // Open a file dialog to select the folder for the "notification.txt" file
            QString folderPath = QFileDialog::getExistingDirectory(nullptr, "Select Folder", QDir::homePath());

            if (!folderPath.isEmpty()) {
                // Create the file path for "notification.txt" in the selected folder
                QString filePath = folderPath + "/notification.txt";

                // Open the file for appending
                QFile file(filePath);
                if (file.open(QIODevice::Append | QIODevice::Text)) {
                    // Create a text stream to write the notification text
                    QTextStream out(&file);

                    // Write the notification text followed by a newline character
                    out << notificationText << "\n";

                    // Close the file
                    file.close();

                    // Display a message to indicate the notification was added successfully
                    QMessageBox::information(nullptr, "Notification Added", "The notification has been added successfully.");
                } else {
                    // Display an error message if there was an issue opening the file
                    QMessageBox::critical(nullptr, "Error", "Failed to open the notification file.");
                }
            }
        });


}
founder::~founder()
{
    delete ui;
}

