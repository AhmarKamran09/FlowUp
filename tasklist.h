#ifndef TASKLIST_H
#define TASKLIST_H

#include <QDialog>

namespace Ui {
class tasklist;
}

class tasklist : public QDialog
{
    Q_OBJECT

public:
    explicit tasklist(QWidget *parent = nullptr);
    ~tasklist();

private:
    Ui::tasklist *ui;
};

#endif // TASKLIST_H
