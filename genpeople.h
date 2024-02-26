#ifndef GENPEOPLE_H
#define GENPEOPLE_H
#include "QPushButton"
#include <QMainWindow>
#include <QLayout>
#include <QWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QPalette>
#include <QComboBox>
#include <QLineEdit>
#include <qstandarditemmodel.h>
#include <QTableView>
#include <QPlainTextEdit>
#include "calendar.h"
#include "ui_calendar.h"
#include <QFont>

class genpeople
{
public:
  void virtual getinfo(QWidget*page1)=0;
    void resources(QWidget*page2);
  void about(QWidget*page3);
    void setpagedesign(QPushButton** buttons, QStackedWidget* stackedWidget, int selected_page, int selected_button, int no_of_buttons);
    QFont setfonting(int size,bool x);


};

#endif // GENPEOPLE_H
