#ifndef CONTACTFACTORY_H
#define CONTACTFACTORY_H
#include "contactlist.h"

class ContactFactory{    

    public:
       //no-arg constructor
       ContactFactory();
       //returns a random contact
       Contact* createContact();

    private:
       //data members
       QStringList firstNames;
       QStringList lastNames;
       QStringList streetAddresses;
       QStringList zipCodes;
       QStringList cities;
       QStringList phoneNumbers;
};
#endif
