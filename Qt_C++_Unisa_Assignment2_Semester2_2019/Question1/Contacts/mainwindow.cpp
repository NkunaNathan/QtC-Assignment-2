#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qobjectwriter.h"
#include "contactreader.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // read XML file
    onOpen();

    ui->deleteEntry->setEnabled(false);

    connect(ui->add, SIGNAL(clicked()), this, SLOT(addContact()));
    connect(ui->deleteEntry, SIGNAL(clicked()), this, SLOT(deleteContact()));
    connect(ui->displayWholeList, SIGNAL(clicked()), this, SLOT(displayFull()));
    connect(ui->displayTelList, SIGNAL(clicked()), this, SLOT(displayTel()));
    connect(ui->displayAddrList, SIGNAL(clicked()), this, SLOT(displayAddr()));
}

MainWindow::~MainWindow()
{
    //write list to XML
    onClose();
    delete ui;
}

void MainWindow::onOpen()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", ".", "XML files (*.xml)");
    if(filename.size() != 0)
    {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, "File error", "Could not open file " + filename, QMessageBox::Ok);
            return;
        }
        QXmlSimpleReader reader;
        QXmlInputSource source(&file);
        ContactReader handler;
        reader.setContentHandler(&handler);
        reader.setErrorHandler(&handler);
        reader.parse(source);
        file.close();

        foreach(Contact *c, handler.getList())
            contactList.add(c);
    }
}

void MainWindow::addContact()
{
    // get values from GUI and create Contact
    int c = ui->category->value();
    QString fn = ui->firstName->text();
    QString ln = ui->surname->text();
    QString sa = ui->address->text();
    QString zc = ui->code->text();
    QString cy = ui->city->text();
    QString pn = ui->phone->text();
    Contact *newContact = new Contact(c, fn, ln, sa, zc, cy, pn);

    // add to contact list
    contactList.add(newContact);

    // clear entry fields
    ui->category->setValue(0);
    ui->firstName->clear();
    ui->surname->clear();
    ui->address->clear();
    ui->code->clear();
    ui->city->clear();
    ui->phone->clear();
    ui->category->setFocus();
}

void MainWindow::deleteContact()
{
    // get current item
    if (ui->listWidget->currentIndex().isValid())
    {
        QString contactStr = ui->listWidget->currentItem()->text();
        QStringList data = contactStr.split(",");
        QString phone = data.at(5).trimmed();
        Contact *current = contactList.getContact(phone);

        if (current != NULL)
            contactList.remove(current);
        displayFull();
    }
}

void MainWindow::displayFull()
{
    QStringList str = contactList.toString().split("\n");
    updateDisplay(str);
    ui->deleteEntry->setEnabled(true);
}

void MainWindow::displayAddr()
{
    int cat = ui->catToFind->value();
    QStringList str = contactList.getMailingList(cat);
    updateDisplay(str);
    ui->deleteEntry->setEnabled(false);
}

void MainWindow::displayTel()
{
    int cat = ui->catToFind->value();
    QStringList str = contactList.getPhoneList(cat);
    updateDisplay(str);
    ui->deleteEntry->setEnabled(false);
}

void MainWindow::updateDisplay(QStringList str)
{
    ui->listWidget->clear();
    ui->listWidget->insertItems(0, str);
}

void MainWindow::onClose()
{
    if (contactList.getSize()>0)
    {
        QString filename = QFileDialog::getSaveFileName(this, "Save file", ".", "XML files (*.xml)");
        if(filename.size() != 0)
        {
            QFile file(filename);
            if (!file.open(QIODevice::WriteOnly))
            {
                QMessageBox::critical(this, "File error", "Could not open file " + filename, QMessageBox::Ok);
                return;
            }
            QTextStream toFile(&file);

            QObjectWriter writer;
            toFile << writer.toString(&contactList);

            file.close();
        }
    }
}
