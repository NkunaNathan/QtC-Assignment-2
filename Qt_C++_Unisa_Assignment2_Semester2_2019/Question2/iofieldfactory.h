#ifndef IOFIELDFACTORY_H
#define IOFIELDFACTORY_H

#include "iofield.h"

#include "intiofield.h"
#include "stringiofield.h"
#include "stringlistiofield.h"

class IOFieldFactory
{
public:
    IOFieldFactory();
    IOField *getField(QVariant field) const;
private:

};

#endif // IOFIELDFACTORY_H
