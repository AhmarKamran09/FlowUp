#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include<QPushButton>
#include"clientloginpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onloginbuttonclicked1();
    void onloginbuttonclicked2();
    void onloginbuttonclicked3();




    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;


};
#endif // MAINWINDOW_H
