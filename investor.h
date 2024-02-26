#ifndef INVESTOR_H
#define INVESTOR_H
#include "genpeople.h"
#include <QMainWindow>

namespace Ui {
class investor;
}

class investor : virtual public QMainWindow,public genpeople
{
    Q_OBJECT

public:
    explicit investor(QWidget *parent = nullptr);
    void getpendingprojectdetails(QWidget*page2);
       void seecompletedprojects(QWidget *page3);
    void getinfo(QWidget*page1);
    ~investor();
    private slots:



private:
    Ui::investor *ui;
};

#endif // INVESTOR_H
