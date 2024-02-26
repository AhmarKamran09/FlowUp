#ifndef CEO_H
#define CEO_H

#include <QWidget>
#include "founder.h"

namespace Ui {
class CEO;
}

class CEO : virtual public QMainWindow,public founder
{
    Q_OBJECT

public:
    explicit CEO(QWidget *parent = nullptr);
    ~CEO();

private:
    void send_project_to_client(QWidget *page);
    void assigntask(QWidget *page1);
    void receivetask_from_employee(QWidget *page2);
    void sendreport_to_founder_of_comp_project(QWidget *page3);
    void receive_details_from_founder(QWidget *page4);
private:
    Ui::CEO *ui;
};

#endif // CEO_H
