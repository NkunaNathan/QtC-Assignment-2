#include "stringiofield.h"

StringIOField::StringIOField(){
    stringField = new QLineEdit();
}

StringIOField::~StringIOField (){
    delete stringField;
}

QVariant StringIOField::getValue () const{
    return QVariant(stringField->text ());
}

void StringIOField::setValue (QVariant value){
    stringField->setText (value.toString ());
}

QWidget *StringIOField::getWidget () const{
    return stringField;
}
