#ifndef STRINGOPERATIONS_H
#define STRINGOPERATIONS_H

#include "operations.h"

class StringOperations : public Operations
{
public:
    StringOperations();
    ~StringOperations();
    QVariant addition (QVariant x, QVariant y);
    QVariant subtraction (QVariant x, QVariant y);
};

#endif // STRINGOPERATIONS_H
