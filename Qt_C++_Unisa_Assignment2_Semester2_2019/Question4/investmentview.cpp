#include<QGridLayout>
#include <QAbstractItemView>

#include "investmentview.h"
#include "investmentcalculator.h"

InvestmentView::InvestmentView()
{
    createGui ();
}

void InvestmentView::createGui (){
    setWindowTitle ("Investment Calculator");
    QGridLayout *layout = new QGridLayout(this);
    QLabel *amountLabel = new QLabel("Initial Amount P: ");
    amountSpinBox = new QDoubleSpinBox();
    amountSpinBox->setPrefix ("R ");
    amountSpinBox->setMinimum (0.00);
    amountSpinBox->setMaximum (1000000000.00);
    QLabel *rateLabel = new QLabel("Interest Rate: ");
    rateSpinBox = new QDoubleSpinBox();
    rateSpinBox->setSuffix (" %");
    rateSpinBox->setMinimum (0.00);
    rateSpinBox->setMaximum (1000.00);
    QLabel *yearLabel = new QLabel("No. of Year(s): ");
    yearsSpinBox = new QSpinBox();
    yearsSpinBox->setSuffix (" year(s)");
    yearsSpinBox->setMinimum (1);
    calculateButton = new QPushButton("Calculate");
    QLabel *headingLabel = new QLabel("Investment Amount over N number of Years");
    displayBox = new QListView();
    displayBox->setEditTriggers (QAbstractItemView::NoEditTriggers);
    layout->addWidget (amountLabel,1,0);
    layout->addWidget (amountSpinBox,1,1);
    layout->addWidget (rateLabel,2,0);
    layout->addWidget (rateSpinBox,2,1);
    layout->addWidget (yearLabel,3,0);
    layout->addWidget (yearsSpinBox,3,1);
    layout->addWidget (calculateButton,4,0);
    layout->addWidget (headingLabel,0,3,0,5);
    layout->addWidget (displayBox,1,3,4,5);
    this->setLayout (layout);

    model = new QStringListModel(this);
    displayBox->setModel (model);

    threadCalc = new QThread();
    investmentCalc = new InvestmentCalculator();
    investmentCalc->moveToThread (threadCalc);
    //making connections
    connect (calculateButton, SIGNAL(clicked()), this, SLOT(evaluateCalculation ()));
    connect (investmentCalc, SIGNAL(newInvestmentAmount(double)),this, SLOT(updateResults(double)));
    connect (threadCalc, SIGNAL(started()), investmentCalc, SLOT(compoundCalculations()));
    connect (investmentCalc, SIGNAL(finished()),this, SLOT(updateThread()));


}


InvestmentView::~InvestmentView (){
    threadCalc->quit ();
    threadCalc->deleteLater ();
    delete investmentCalc;
}

void InvestmentView::disableWidget (){
    amountSpinBox->setDisabled (true);
    rateSpinBox->setDisabled (true);
    yearsSpinBox->setDisabled (true);
    calculateButton->setDisabled (true);
}

void InvestmentView::enableWidget (){
    amountSpinBox->setEnabled (true);
    rateSpinBox->setEnabled (true);
    yearsSpinBox->setEnabled (true);
    calculateButton->setEnabled (true);
}

void InvestmentView::updateThread (){
    threadCalc->quit ();
    enableWidget ();
}

void InvestmentView::updateResults (double results){
//    QTextStream.setRealNumberPrecision (2);

    QString investmentAmount = QString("R%1").arg (results, 0,'f',2); //, QTextStream::FixedNotation
    compoundResults.append (investmentAmount);
    model->setStringList (compoundResults);
}

void InvestmentView::evaluateCalculation (){
    compoundResults.clear ();
    double initialvalue = amountSpinBox->value ();
    double interestvalue = rateSpinBox->value ();
    int yearsvalue = yearsSpinBox->value ();
    investmentCalc->setCounpuntValues (initialvalue, interestvalue,yearsvalue);
    threadCalc->start ();
    disableWidget ();

}
