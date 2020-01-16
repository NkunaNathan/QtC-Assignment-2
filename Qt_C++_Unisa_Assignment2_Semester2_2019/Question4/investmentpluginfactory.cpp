#include "investmentpluginfactory.h"

//#include"investmentcalculator.h"
#include "investmentview.h"

InvestmentPluginFactory::InvestmentPluginFactory()
{
}

QList<QWebPluginFactory::Plugin>InvestmentPluginFactory::plugins () const{
    QWebPluginFactory::Plugin investment;
    investment.name = QString("application/investment");
    investment.description = QString("Investment Calculator");
    QList<QWebPluginFactory::Plugin> list;
    list.append (investment);
    return list;
}

QObject *InvestmentPluginFactory::create (const QString &mimeType,
                                          const QUrl &,
                                          const QStringList &argumentNames,
                                          const QStringList &argumentValues) const{
    if(mimeType == "application/investment"){
        InvestmentView *investmentcalculator = new InvestmentView();
        return investmentcalculator;
    }else{
        return 0;
    }
}
