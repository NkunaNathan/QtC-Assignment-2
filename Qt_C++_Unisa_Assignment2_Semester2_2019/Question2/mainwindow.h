#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "operationsfactory.h"
#include "iofieldfactory.h"
#include "operations.h"
#include "iofield.h"
#include "displaywidget.h"
#include <QSignalMapper>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void display(QVariant results);

    void resetGui();

    void signalHangler();

    void deactivateGUI();

    void on_Add_clicked();

    void on_Subtraction_clicked();

    void handleChecks(QString t);

//    void firstQComboBox(QString data1);

//    void secontQComboBox(QString data2);

private:
    Ui::MainWindow *ui;

    OperationsFactory *opFactory;
//    OperationsFactory */*anof*/;

    QSignalMapper *signalMap;

//    IOField *iofield;

//    displayWidget *ds; only use to allow one to interact with both gui when the widget is showing


};

#endif // MAINWINDOW_H
