#include "genpeople.h"
#include"calendar.h"
#include<QPixmap>
void genpeople::about(QWidget*page3){

  page3->setStyleSheet("background-image:url(:/images/Untitled design (7).png)");
}

void genpeople::resources(QWidget*page2 ){
  page2->setStyleSheet("background-image:url(:/images/Untitled design (8).png)");

}

QFont genpeople::setfonting(int size,bool x){
QFont font;
// Set the font family, size, and bold style
font.setFamily("Amasis MT Pro Black");
font.setPointSize(size);
font.setBold(x);
return font;
}




void genpeople:: setpagedesign(QPushButton** buttons, QStackedWidget* stackedWidget, int selected_page, int selected_button, int no_of_buttons)
{
    stackedWidget->setCurrentIndex(selected_page);

    for (int i = 0; i<no_of_buttons; i++) {
        buttons[i]->setStyleSheet("QPushButton { background-color: lightgreen; border-radius: 10px; }");
    }
    buttons[selected_button]->setStyleSheet("QPushButton { background-color: white; border-radius: 10px; }");

}

