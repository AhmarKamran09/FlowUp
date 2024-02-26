#include "loadingpage.h"
#include "ui_loadingpage.h"
#include"clientloginpage.h"
#include<QTimer>
#include<QLabel>
#include<QMovie>
#include"agreementpage.h"
#include"employee.h"
#include"client.h"
LoadingPage::LoadingPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingPage)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LoadingPage::updateProgressBar);
    timer->start(1000); // Interval of 1 second
   ui->progressBar->setStyleSheet("QProgressBar {"
                                  "border: none;"
                                  "border-radius: 50px;"
                                  "text-align: center;"
                                  "background-color: black;"
                                  "}"
                                  "QProgressBar::chunk {"
                                  "border-radius: 50px;"
                                  "background-color: lightgreen;"
                                  "}");
   QMovie *movie = new QMovie(":/ZZ5H.gif");

      // Set the movie to the label and start the animation
      ui->label->setMovie(movie);
      movie->start();
       movie->setScaledSize(ui->label->size());
       QMovie *movie2 = new QMovie(":/Untitled design (1).gif");

          // Set the movie to the label and start the animation
          ui->label_2->setMovie(movie2);
          movie2->start();
           movie2->setScaledSize(ui->label_2->size());


           QTimer::singleShot(8000, this, &LoadingPage::close);
          QTimer::singleShot(8000, [&]() {
            client *e=new client;
            e->showMaximized();

             });

}

LoadingPage::~LoadingPage()
{
    delete ui;
}

void LoadingPage::updateProgressBar()
{
    static int value = 0;
            ui->progressBar->setValue(value);
            value += 10;
            if (value > 100) {
                value = 0;
            }
}

