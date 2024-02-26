#ifndef CALENDAR1_H
#define CALENDAR1_H

#include <QDialog>

namespace Ui {
class calendar1;
}

class calendar1 : public QDialog
{
    Q_OBJECT

public:
    explicit calendar1(QWidget *parent = nullptr);
    ~calendar1();

private:
    Ui::calendar1 *ui;
};

#endif // CALENDAR1_H
