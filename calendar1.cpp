#include "calendar1.h"
#include "ui_calendar1.h"

calendar1::calendar1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendar1)
{
    ui->setupUi(this);
}

calendar1::~calendar1()
{
    delete ui;
}
