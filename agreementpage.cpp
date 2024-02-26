#include "agreementpage.h"
#include "ui_agreementpage.h"
#include"loadingpage.h"
#include<QPixmap>
#include<QScrollArea>
#include<QTextEdit>
#include<QPushButton>
#include<QCheckBox>
#include"mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QDebug>

agreementpage::agreementpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agreementpage)
{
    ui->setupUi(this);

    // Read the agreement text from the file
    QFile file(":/Agreementpage.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        qDebug()<< "File did not open";
    }
    QTextStream in(&file);
    QString text=in.readAll();

     // Set the agreement page's layout and elements
    QPixmap image(":/images/c49e8a4429b543158951fbaca6b7a3da-removebg-preview.png");
    ui->label->setPixmap(image);

    ui->label_2->setText("Terms and Conditions");
    QScrollArea* scrollArea = new QScrollArea(this);
    QTextEdit* textEdit = new QTextEdit(scrollArea);
    textEdit->setReadOnly(true);
    textEdit->setPlainText(text);

    scrollArea->setWidget(textEdit);
    scrollArea->setWidgetResizable(true);


    scrollArea->setGeometry(20, 100, 600, 270);

    QCheckBox* checkBox = new QCheckBox("I agree to the terms and conditions", this);
    QPushButton* button = new QPushButton("Proceed", this);
    button->setGeometry(560,380,80,28);
    checkBox->setGeometry(320,381,210,32);

    // Connect the button's clicked signal to the slot for processing the agreement
    connect(button, &QPushButton::clicked, this, [=]() {
        if (checkBox->isChecked()) {
            MainWindow* mainWindow = new MainWindow();
            mainWindow->resize(1000,550);
                       mainWindow->show();
                       this->close();

        }
        else {
             // Display a message indicating that agreement is essential
             ui->label_3->setText("Agreement is Esssential->");

        }
    });

}

agreementpage::~agreementpage()
{
    delete ui;
}
