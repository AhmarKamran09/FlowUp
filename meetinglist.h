#ifndef MEETINGLIST_H
#define MEETINGLIST_H

#include <QDialog>

namespace Ui {
class meetinglist;
}

class meetinglist : public QDialog
{
    Q_OBJECT

public:
    explicit meetinglist(QWidget *parent = nullptr);
    ~meetinglist();

private:
    Ui::meetinglist *ui;
};

#endif // MEETINGLIST_H
