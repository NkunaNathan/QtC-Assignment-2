#include "stringlistiofield.h"
#include <QStringList>
StringListIOField::StringListIOField(){
    stringListField = new QComboBox();
}

StringListIOField::~StringListIOField (){
    delete stringListField;
}

QVariant StringListIOField::getValue () const{
    return QVariant(stringListField->currentData ());
}

void StringListIOField::setValue (QVariant value){
    stringListField->addItems (value.toStringList ());
}

QWidget* StringListIOField::getWidget () const{
    return stringListField;
}
