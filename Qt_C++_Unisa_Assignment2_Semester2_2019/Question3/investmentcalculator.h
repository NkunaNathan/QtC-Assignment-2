#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H
#include<QObject>
// in order to use signals and slots in this class need to
// inherite from QObject
class InvestmentCalculator : public QObject
{
    Q_OBJECT
public:
    InvestmentCalculator();
    InvestmentCalculator(double initialAmount, double rate, int years);
    void setCounpuntValues(double initialAmount, double rate, int years);
    double getPrincipalAmount() const;
    double getInterestRate() const;
    int getNumberOfYears() const;

public slots:
    void compoundCalculations();
signals:
    void newInvestmentAmount(double results);
    void finished();

private:
    double principalAmount;
    double interestRate;
    int numberOfYears;
};

#endif // INVESTMENTCALCULATOR_H
