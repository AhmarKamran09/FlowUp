#ifndef COMPANYEND_H
#define COMPANYEND_H

#include <QDialog>

namespace Ui {
class companyend;
}

class companyend : public QDialog
{
    Q_OBJECT

public:
    explicit companyend(QWidget *parent = nullptr);
    ~companyend();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::companyend *ui;

};

#endif // COMPANYEND_H
