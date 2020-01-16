#include "displaywidget.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QRect>

displayWidget::displayWidget(){

}
displayWidget::displayWidget(QVariant v){

    IOFieldFactory ioff;
    iofield = ioff.getField(v);

    QVBoxLayout *layout = new QVBoxLayout();
    QLabel * label = new QLabel("Requested widget: ");
    QPushButton* ok = new QPushButton("OK");

    layout->addWidget(label);
    layout->addWidget(iofield->getWidget());
    layout->addWidget(ok);
    QRect r1(100, 200, 11, 16);
    layout->setGeometry (r1);
    this->setLayout(layout);
    iofield->setValue(v);
    connect(ok, SIGNAL(clicked()),this,SLOT(display()));

}

void displayWidget::display(){
    QString value = iofield->getValue().toString();
    QMessageBox::information(this,"Results",QString("Your results: %1").arg (value),0,0);

}
