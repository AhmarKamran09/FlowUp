#ifndef LOADINGPAGE_H
#define LOADINGPAGE_H

#include <QDialog>

namespace Ui {
class LoadingPage;
}

class LoadingPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoadingPage(QWidget *parent = nullptr);
    ~LoadingPage();
private slots:
    void updateProgressBar();


private:
    Ui::LoadingPage *ui;
};

#endif // LOADINGPAGE_H
