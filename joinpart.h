#ifndef JOINPART_H
#define JOINPART_H

#include <QMainWindow>

namespace Ui {
class joinpart;
}

class joinpart : public QMainWindow
{
    Q_OBJECT

public:
    explicit joinpart(QWidget *parent = nullptr);
    ~joinpart();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::joinpart *ui;
};

#endif // JOINPART_H
