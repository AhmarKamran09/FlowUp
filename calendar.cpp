#include "calendar.h"
#include "ui_calendar.h"
#include<QPainter>
#include <QTextCharFormat>
#include<QDateTimeEdit>
#include<QTimeEdit>
#include<QPushButton>
#include<QCalendarWidget>
#include<QFile>
#include"meetinglist.h"
Calendar::Calendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{





}

Calendar::~Calendar()
{
    delete ui;
}










void Calendar::on_pushButton_clicked()
{


    QDate selectedDate = ui->dateEdit->date();
     QString labelText = "Event Label"; // Replace with your label text
     QTextCharFormat textFormat;
     textFormat.setBackground(Qt::red);
     textFormat.setFontWeight(QFont::Bold);
     textFormat.setFontPointSize(10);
     textFormat.setToolTip(labelText);
     ui->calendarWidget->setDateTextFormat(selectedDate, textFormat);



}


void Calendar::on_pushButton_2_clicked()
{
    QDate selectedDate = ui->dateEdit_2->date();
     QString labelText = "Event Label"; // Replace with your label text
     QTextCharFormat textFormat;
     textFormat.setBackground(Qt::blue);
     textFormat.setFontWeight(QFont::Bold);
     textFormat.setFontPointSize(10);
     textFormat.setToolTip(labelText);
     ui->calendarWidget->setDateTextFormat(selectedDate, textFormat);
}




