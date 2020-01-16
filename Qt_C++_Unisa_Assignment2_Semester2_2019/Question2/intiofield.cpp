#include "intiofield.h"

IntIOField::IntIOField(){
    intField = new QSpinBox();
}

QVariant IntIOField::getValue () const{
    return QVariant(intField->value ());
}

void IntIOField::setValue (QVariant value){
    intField->setValue (value.toInt ());
}

QWidget* IntIOField::getWidget () const{
    return intField;
}

IntIOField::~IntIOField (){
    delete intField;
}
