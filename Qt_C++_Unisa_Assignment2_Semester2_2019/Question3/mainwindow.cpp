#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle ("Investment Calculator");
    ui->amountSpinBox->setMaximum (1000000000.00);
    ui->amountSpinBox->setPrefix ("R ");
    ui->rateSpinBox->setMaximum (1000.00);
    ui->rateSpinBox->setSuffix (" %");
    ui->yearsSpinBox->setMaximum (100000);
    ui->yearsSpinBox->setMinimum (1);
    ui->yearsSpinBox->setSuffix (" year(s)");
    model = new QStringListModel(this);
    ui->displayBox->setModel (model);
    threadCalc = new QThread();
    investmentCalc = new InvestmentCalculator();
    investmentCalc->moveToThread (threadCalc);
    //making connections
    connect (ui->calcButton, SIGNAL(clicked()), this, SLOT(evaluateCalculation ()));
    connect (investmentCalc, SIGNAL(newInvestmentAmount(double)),this, SLOT(updateResults(double)));
    connect (threadCalc, SIGNAL(started()), investmentCalc, SLOT(compoundCalculations()));
    connect (investmentCalc, SIGNAL(finished()),this, SLOT(updateThread()));


}

MainWindow::~MainWindow()
{
    delete ui;
    threadCalc->quit ();
    threadCalc->deleteLater ();
    delete investmentCalc;
}


void MainWindow::disableWidget (){
    ui->amountSpinBox->setDisabled (true);
    ui->rateSpinBox->setDisabled (true);
    ui->yearsSpinBox->setDisabled (true);
    ui->calcButton->setDisabled (true);
}

void MainWindow::enableWidget (){
    ui->amountSpinBox->setEnabled (true);
    ui->rateSpinBox->setEnabled (true);
    ui->yearsSpinBox->setEnabled (true);
    ui->calcButton->setEnabled (true);
}

void MainWindow::updateThread (){
    threadCalc->quit ();
    enableWidget ();
}

void MainWindow::updateResults (double results){
//    QTextStream.setRealNumberPrecision (2);

    QString investmentAmount = QString("R%1").arg (results, 0,'f',2); //, QTextStream::FixedNotation
    compoundResults.append (investmentAmount);
    model->setStringList (compoundResults);
}

void MainWindow::evaluateCalculation (){
    compoundResults.clear ();
    double initialvalue = ui->amountSpinBox->value ();
    double interestvalue = ui->rateSpinBox->value ();
    int yearsvalue = ui->yearsSpinBox->value ();
    investmentCalc->setCounpuntValues (initialvalue, interestvalue,yearsvalue);
    threadCalc->start ();
    disableWidget ();

}
