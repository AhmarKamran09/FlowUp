#include "test.h"
#include "ui_test.h"
#include"investor.h"
#include"calendar.h"
#include"employee.h"
test::test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
}

test::~test()
{
    delete ui;
}

void test::on_pushButton_clicked()
{

    employee *emp = new employee(this);

        // Set the window modality to ApplicationModal if needed
        emp->setWindowModality(Qt::ApplicationModal);

        // Show the employee widget
        emp->setVisible(true);

}

