#include "iofieldfactory.h"
#include <QDebug>



IOFieldFactory::IOFieldFactory()
{
}

IOField *IOFieldFactory::getField (QVariant field) const{
    if(QString(field.typeName ()) == "int")
        return new IntIOField();
    if(QString(field.typeName ())== "QString")
        return new StringIOField();
    if(QString(field.typeName ())== "QStringList")
        return new StringListIOField();
    else
        return 0;
}
