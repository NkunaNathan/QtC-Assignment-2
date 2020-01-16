#include "investmentcalculator.h"
#include <QMutex>
#include <QTime>
#include <QWaitCondition>
#include <QtGlobal>
#include <QVariant>
#include<cstdlib>
#include <cmath>
#include <QTextStream>
#include<iostream>
using namespace std;

InvestmentCalculator::InvestmentCalculator()
    :principalAmount(0.00), interestRate(0.00), numberOfYears(1){
    qsrand (QTime::currentTime ().msec ());
}
InvestmentCalculator::InvestmentCalculator(double initialAmount, double rate, int years):
    principalAmount(initialAmount), interestRate(rate),numberOfYears(years){
    qsrand (QTime::currentTime ().msec ());
}

void InvestmentCalculator::setCounpuntValues (double initialAmount, double rate, int years){
    principalAmount = initialAmount;
    interestRate = rate;
    numberOfYears = years;
}

double InvestmentCalculator::getInterestRate () const{
    return interestRate;
}

double InvestmentCalculator::getPrincipalAmount () const{
    return principalAmount;
}

int InvestmentCalculator::getNumberOfYears () const{
    return numberOfYears;
}

void InvestmentCalculator::compoundCalculations (){
//    QTextStream cout(stdout);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    bool ok;
    int yearIncreament = 1;


    while(yearIncreament <= numberOfYears){
        double futureValue;
        double rateInterest;
        QVariant value , futureAmount;
        value.setValue(interestRate/100.00);
        rateInterest = value.toDouble ();
        cout << "Interest Rate: " << rateInterest << endl;
        //interest rate in % to be divide by 100 so that it can be in decimal form
        futureAmount.setValue( principalAmount*(1+rateInterest)); // pow((1+rateInterest),yearIncreament));
//        futureAmount.
//        futureAmount.setValue(futureValue);
        futureValue = futureAmount.toDouble (&ok);
        cout << "Future value R" << futureValue << endl;
        principalAmount = futureValue;
        cout << "Principal amount: R" << principalAmount << endl;
        emit newInvestmentAmount (futureValue);

        QMutex mutex;
        mutex.lock ();
        QWaitCondition waitTime;
        waitTime.wait (&mutex, 1000);
        mutex.unlock ();
        yearIncreament++;
    }
    emit finished ();
}
