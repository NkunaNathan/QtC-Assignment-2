#ifndef STRINGLISTIOFIELD_H
#define STRINGLISTIOFIELD_H

#include <QComboBox>

#include "iofield.h"

class StringListIOField : public IOField
{
public:
    StringListIOField();
    ~StringListIOField();
    QVariant getValue () const;
    void setValue (QVariant value);
    QWidget *getWidget () const;
private:
    QComboBox *stringListField;
};

#endif // STRINGLISTIOFIELD_H
