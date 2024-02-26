#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include "employee.h"
namespace Ui {
class client;
}

class client : public QMainWindow,public genpeople
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
    void getinfo(QWidget*page1);
    void giveproject(QWidget *page3);
    void getcompletedproject(QWidget *page5);
    void sendfeedback(QWidget *page3);
private:
    Ui::client *ui;
};

#endif // CLIENT_H
