#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "operationsfactory.h"
#include "iofieldfactory.h"
#include "displaywidget.h"
#include <QTextStream>

QTextStream cout(stdout);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle ("Choices");
    opFactory = OperationsFactory::getInstance ();
//    anof = OperationsFactory::getInstance ();

    //before selecting type of operation that will be perfomed
    //default
    deactivateGUI ();

    //hangles checkBox
    signalMap = new QSignalMapper(this);
    connect(ui->intcheckBox, SIGNAL(clicked()), signalMap, SLOT(map()));
    signalMap->setMapping(ui->intcheckBox, "Int");
    connect(ui->qStringCheckBox, SIGNAL(clicked()), signalMap, SLOT(map()));
    signalMap->setMapping(ui->qStringCheckBox, "QString");
    connect(ui->qStringListCheckBox, SIGNAL(clicked()), signalMap, SLOT(map()));
    signalMap->setMapping(ui->qStringListCheckBox, "QStringList");
//connect checks
    connect(signalMap, SIGNAL(mapped(QString)), this, SLOT(handleChecks(QString)));

    // operation type int, qstring, qstringlist
    connect (ui->Int, SIGNAL(clicked()), this, SLOT(signalHangler()));
    connect (ui->QString, SIGNAL(clicked()), this, SLOT(signalHangler()));
    connect (ui->QStringList, SIGNAL(clicked()), this, SLOT(signalHangler()));

    //QComboBox
//    connect (ui->strListcomboBox1, SIGNAL(editTextChanged(QString)),this, SLOT(firstQComboBox(QString)));
//    connect (ui->strListcomboBox1, SIGNAL(editTextChanged(QString)),this, SLOT(secontQComboBox(QString)));

}

MainWindow::~MainWindow()
{
    opFactory ->deleteInstance ();

    delete signalMap;

    delete ui;

}


void MainWindow::signalHangler (){
    QString obj = QObject::sender ()->objectName ();

    QVariant result;
    Operations *tempOperation;
//    Operations *newOperation;
    tempOperation = opFactory ->createOperation (obj);
//    newOperation = opFactory->createOperation (obj);

    if(ui->Add->isChecked ()){
        if(ui->intcheckBox->isChecked ()){
            if(tempOperation != NULL){
                result = tempOperation->addition (ui->intSpinBox1->value (),ui->intSpinBox2->value ());
//                cout << result.toInt () << endl;

            }
        }if(ui->qStringCheckBox->isChecked ()){
            if(tempOperation != NULL){
                result = tempOperation->addition (ui->stringLineEdit1->text (),ui->stringLineEdit2->text());
//                cout << result.toString () << endl;
            }
        }if(ui->qStringListCheckBox->isChecked ()){
            if(tempOperation != NULL){
                result = tempOperation->addition (ui->strListcomboBox1->currentText (),ui->strListcomboBox2->currentText ());
            }
        }
    }if(ui->Subtraction->isChecked ()){
        if(ui->intcheckBox->isChecked ()){
            if(tempOperation != NULL){
                result = tempOperation->subtraction (ui->intSpinBox1->value (),ui->intSpinBox2->value ());
//                cout << result.toInt () << endl;
            }
        }if(ui->qStringCheckBox->isChecked ()){
            if(tempOperation != NULL){
                result = tempOperation->subtraction (ui->stringLineEdit1->text (),ui->stringLineEdit2->text());
            }
        }if(ui->qStringListCheckBox->isChecked ()){
            if(tempOperation != NULL){
                result = tempOperation->subtraction (ui->strListcomboBox1->currentText (),ui->strListcomboBox2->currentText ());
            }
        }
    }

    delete tempOperation;
    display (result);
    resetGui ();
    deactivateGUI ();

//    ui->Subtraction->setChecked (false);
//    ui->Add->setChecked (false);

}


void MainWindow::on_Add_clicked()
{

    ui->intcheckBox->setEnabled (true);
    ui->qStringCheckBox->setEnabled  (true);
    ui->qStringListCheckBox->setEnabled  (true);
}


void MainWindow::on_Subtraction_clicked()
{
    ui->intcheckBox->setEnabled (true);
    ui->qStringCheckBox->setEnabled  (true);
    ui->qStringListCheckBox->setEnabled  (true);
}

void MainWindow::handleChecks (QString t){
        if(t == "Int"){
            ui->qStringCheckBox->setChecked (false);
            ui->qStringCheckBox->setDisabled (true);
            ui->stringLineEdit1->setDisabled (true);
            ui->stringLineEdit2->setDisabled (true);
            ui->QString->setDisabled (true);
            ui->qStringListCheckBox->setChecked (false);
            ui->qStringListCheckBox->setDisabled (true);
            ui->strListcomboBox1->setDisabled (true);
            ui->strListcomboBox2->setDisabled (true);
            ui->QStringList->setDisabled (true);
            ui->intSpinBox1->setEnabled (true);
            ui->intSpinBox2->setEnabled (true);
            ui->Int->setEnabled (true);
        }if(t == "QString"){
            ui->intcheckBox->setChecked (false);
            ui->intcheckBox->setDisabled (true);
            ui->intSpinBox1->setDisabled (true);
            ui->intSpinBox2->setDisabled (true);
            ui->Int->setDisabled (true);
            ui->qStringListCheckBox->setChecked (false);
            ui->qStringListCheckBox->setDisabled (true);
            ui->strListcomboBox1->setDisabled (true);
            ui->strListcomboBox2->setDisabled (true);
            ui->QStringList->setDisabled (true);
            ui->stringLineEdit1->setEnabled (true);
            ui->stringLineEdit2->setEnabled (true);
            ui->QString->setEnabled (true);
        }if(t == "QStringList"){
            ui->intcheckBox->setChecked (false);
            ui->intcheckBox->setDisabled (true);
            ui->intSpinBox1->setDisabled (true);
            ui->intSpinBox2->setDisabled (true);
            ui->Int->setDisabled (true);
            ui->qStringCheckBox->setChecked (false);
            ui->qStringCheckBox->setDisabled (true);
            ui->stringLineEdit1->setDisabled (true);
            ui->stringLineEdit2->setDisabled (true);
            ui->QString->setDisabled (true);
            ui->strListcomboBox1->setEnabled (true);
            ui->strListcomboBox2->setEnabled (true);
            ui->QStringList->setEnabled (true);
        }
}


void MainWindow::deactivateGUI (){
    ui->intSpinBox1->setDisabled (true);
    ui->intSpinBox2->setDisabled (true);
    ui->stringLineEdit1->setDisabled (true);
    ui->stringLineEdit2->setDisabled (true);
    ui->strListcomboBox1->setDisabled (true);
    ui->strListcomboBox2->setDisabled (true);
    ui->intcheckBox->setDisabled (true);
    ui->qStringCheckBox->setDisabled (true);
    ui->qStringListCheckBox->setDisabled (true);
    ui->Int->setDisabled (true);
    ui->QString->setDisabled (true);
    ui->QStringList->setDisabled (true);
}

void MainWindow::display (QVariant results){

    displayWidget dw(results);
    dw.setModal (true);
    deactivateGUI ();
    dw.exec ();

}

void MainWindow::resetGui (){
    ui->intSpinBox1->setValue (0);
    ui->intSpinBox2->setValue (0);
    ui->Add->setChecked (false);

    ui->Subtraction->setChecked (false);
    ui->intcheckBox->setChecked (false);
    ui->qStringCheckBox->setChecked (false);
    ui->qStringListCheckBox->setChecked (false);
    ui->strListcomboBox1->clearEditText ();
    ui->strListcomboBox2->clearEditText ();
    ui->stringLineEdit1->clear ();
    ui->stringLineEdit2->clear ();
}

//void MainWindow::firstQComboBox (QString data1){
//    QStringList item;
////    data1.split (",");
//    item.append (data1.split (","));
//    ui->strListcomboBox1->addItems (item);
//}

//void MainWindow::secontQComboBox (QString data2){
//    QStringList item;
//    item.append (data2.split (","));
//    ui->strListcomboBox2->addItems (item);
//}
