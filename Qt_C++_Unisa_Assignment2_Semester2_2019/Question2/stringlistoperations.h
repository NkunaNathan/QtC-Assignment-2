#ifndef STRINGLISTOPERATIONS_H
#define STRINGLISTOPERATIONS_H

#include "operations.h"

class StringListOperations : public Operations
{
public:
    StringListOperations();
    ~StringListOperations();
    QVariant addition (QVariant x, QVariant y);
    QVariant subtraction (QVariant x, QVariant y);
};

#endif // STRINGLISTOPERATIONS_H
