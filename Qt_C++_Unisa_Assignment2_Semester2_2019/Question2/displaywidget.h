#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H
#include <QWidget>
#include <QDialog>
#include "iofield.h"
#include "iofieldfactory.h"

class displayWidget: public QDialog
{
    Q_OBJECT
public:
    displayWidget();
    displayWidget(QVariant v);
public slots:
    void display();
private:
    IOField *iofield;
};

#endif // DISPLAYWIDGET_H
