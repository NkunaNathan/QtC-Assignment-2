#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QVariant>
class Operations
{
public:
    Operations();
    virtual ~Operations();
    virtual QVariant addition(QVariant x, QVariant y) = 0;
    virtual QVariant subtraction(QVariant x, QVariant y) = 0;
};

#endif // OPERATIONS_H
