#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "genpeople.h"
#include "ui_employee.h"

#include <QMainWindow>

namespace Ui {
class employee;
}

class employee : public QMainWindow, public genpeople
{
    Q_OBJECT

public:
    explicit employee(QWidget *parent = nullptr);
    ~employee();
    void getinfo(QWidget *page0);
private:
    void sendtask_to_ceo(QWidget *page2);
    void seependingtasks(QWidget *page3);
    void notifications(QWidget *page5);

private:
    Ui::employee *ui;
};

#endif // EMPLOYEE_H

