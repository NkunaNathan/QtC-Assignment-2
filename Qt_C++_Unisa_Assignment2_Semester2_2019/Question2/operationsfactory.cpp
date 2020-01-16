#include "operationsfactory.h"
#include "intoperations.h"
#include "stringlistoperations.h"
#include "stringoperations.h"

OperationsFactory *OperationsFactory::onlyInstance = NULL;

OperationsFactory::OperationsFactory(){
}

OperationsFactory* OperationsFactory::getInstance (){
    if(onlyInstance == NULL)
        onlyInstance = new OperationsFactory();
    return onlyInstance;
}

void OperationsFactory::deleteInstance (){
    delete onlyInstance;
}

Operations * OperationsFactory::createOperation (QString type) const {
    if(type == "Int"){
        return new IntOperations();
    }
    if (type == "QString") {
        return new StringOperations();
    }
    if(type == "QStringList"){
        return new StringListOperations();
    }else
        return NULL;
}
