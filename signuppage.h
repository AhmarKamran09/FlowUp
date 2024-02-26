#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H
#include<Qtsql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

namespace Ui {
class SignupPage;
}

class SignupPage : public QDialog
{
    Q_OBJECT

public:
    explicit SignupPage(QWidget *parent = nullptr);
    ~SignupPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::SignupPage *ui;
};

#endif // SIGNUPPAGE_H
