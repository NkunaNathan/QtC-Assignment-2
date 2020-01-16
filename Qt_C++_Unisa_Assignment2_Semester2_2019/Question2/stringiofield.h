#ifndef STRINGIOFIELD_H
#define STRINGIOFIELD_H

#include <QLineEdit>

#include "iofield.h"

class StringIOField : public IOField
{
public:
    StringIOField();
    ~StringIOField();
    QVariant getValue () const;
    void setValue (QVariant value);
    QWidget *getWidget () const;
private:
    QLineEdit *stringField;
};

#endif // STRINGIOFIELD_H
