#ifndef IOFIELD_H
#define IOFIELD_H

#include <QVariant>
#include <QWidget>

class IOField
{
public:
    IOField();
    virtual QVariant getValue() const = 0;
    virtual void setValue(QVariant value) = 0;
    virtual QWidget *getWidget() const = 0;
    virtual ~IOField(){}
};

#endif // IOFIELD_H
