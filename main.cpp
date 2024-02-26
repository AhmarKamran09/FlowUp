#include"mainwindow.h"
#include"investor.h"
#include <QApplication>
#include"test.h"
#include"employee.h"
#include "ceo.h"
#include"client.h"
#include"agreementpage.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  MainWindow w1;
    w1.resize(1000,500);
   w1.show();
   return a.exec();
}
