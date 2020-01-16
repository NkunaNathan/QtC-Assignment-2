#ifndef INTIOFIELD_H
#define INTIOFIELD_H

#include <QSpinBox>

#include "iofield.h"

class IntIOField : public IOField
{
public:
    IntIOField();
    ~IntIOField();
    QVariant getValue () const;
    void setValue (QVariant value);
    QWidget *getWidget () const;
private:
    QSpinBox *intField;
};

#endif // INTIOFIELD_H
