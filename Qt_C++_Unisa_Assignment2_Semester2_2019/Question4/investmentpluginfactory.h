#ifndef INVESTMENTPLUGINFACTORY_H
#define INVESTMENTPLUGINFACTORY_H

#include<QWebPluginFactory>

class InvestmentPluginFactory : public QWebPluginFactory
{
public:
    InvestmentPluginFactory();
    QList<QWebPluginFactory::Plugin> plugins () const;
    QObject *create (const QString &mimeType,
                     const QUrl &,
                     const QStringList &argumentNames,
                     const QStringList &argumentValues) const;
};

#endif // INVESTMENTPLUGINFACTORY_H
