#ifndef FOUNDER_H
#define FOUNDER_H
#include <QMainWindow>
#include "investor.h"
namespace Ui {
class founder;
}
class founder : virtual public QMainWindow,public investor
{
    Q_OBJECT

public:
    explicit founder(QWidget *parent = nullptr);
    ~founder();
    void addnotification(QWidget *page3);
private:
    void addemployee(QWidget *page0);
    void delemployee(QWidget *page1);
    void receivereport_of_comp_task(QWidget *page5);

private:
    Ui::founder *ui;
 };

#endif // FOUNDER_H

