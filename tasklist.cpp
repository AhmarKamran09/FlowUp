#include "tasklist.h"
#include "ui_tasklist.h"

tasklist::tasklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tasklist)
{
    ui->setupUi(this);

}

tasklist::~tasklist()
{
    delete ui;
}
