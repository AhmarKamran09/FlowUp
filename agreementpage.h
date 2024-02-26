#ifndef AGREEMENTPAGE_H
#define AGREEMENTPAGE_H

#include <QDialog>

namespace Ui {
class agreementpage;
}

class agreementpage : public QDialog
{
    Q_OBJECT

public:
    explicit agreementpage(QWidget *parent = nullptr);
    ~agreementpage();

private slots:


private:
    Ui::agreementpage *ui;
};

#endif // AGREEMENTPAGE_H
