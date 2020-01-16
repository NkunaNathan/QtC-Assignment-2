#ifndef OPERATIONSFACTORY_H
#define OPERATIONSFACTORY_H

//#include<QVariant>
#include <QString>
#include "operations.h"

class OperationsFactory
{
public:
    Operations *createOperation(QString type) const;
    static OperationsFactory *getInstance();
    static void deleteInstance();

private:
    OperationsFactory();
    static OperationsFactory *onlyInstance;
};

#endif // OPERATIONSFACTORY_H
