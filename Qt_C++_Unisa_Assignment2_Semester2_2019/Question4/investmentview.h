#ifndef INVESTMENTVIEW_H
#define INVESTMENTVIEW_H
#include <QDialog>
#include <QStringListModel>
#include <QThread>

#include <QDoubleSpinBox>
#include <QLabel>
#include <QListView>
#include <QPushButton>
#include <QSpinBox>

#include "investmentcalculator.h"

class InvestmentView : public QDialog
{
    Q_OBJECT
public:
    InvestmentView();
    ~InvestmentView();

private:
    QStringListModel *model;
    QStringList compoundResults;
    InvestmentCalculator *investmentCalc;
    QThread *threadCalc;

    //creating a gui info
    QDoubleSpinBox *amountSpinBox;
    QDoubleSpinBox *rateSpinBox;
    QSpinBox *yearsSpinBox;
    QPushButton *calculateButton;
    QListView *displayBox;
    void createGui();

private slots:
    void updateResults(double results);
    void updateThread();
    void disableWidget();
    void enableWidget();
    void evaluateCalculation();
};

#endif // INVESTMENTVIEW_H
