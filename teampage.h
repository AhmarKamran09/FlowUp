#ifndef TEAMPAGE_H
#define TEAMPAGE_H
#include<Qtsql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

namespace Ui {
class teampage;
}

class teampage : public QDialog
{
    Q_OBJECT

public:
    explicit teampage(QWidget *parent = nullptr);
    ~teampage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::teampage *ui;
    QSqlDatabase db1;
};

#endif // TEAMPAGE_H
