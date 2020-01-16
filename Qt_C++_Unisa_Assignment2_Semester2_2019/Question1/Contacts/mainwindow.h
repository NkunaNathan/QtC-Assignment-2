#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "contactlist.h"

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
    void addContact();
    void deleteContact();
    void displayFull();
    void displayAddr();
    void displayTel();
    void updateDisplay(QStringList str);

private:
    Ui::MainWindow *ui;

    // data members
    ContactList contactList;

    // private member functions
    void onOpen();
    void onClose();
};

#endif // MAINWINDOW_H
