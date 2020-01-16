#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include <QStringList>
#include <QObject>

class ContactList : public QObject
{
    Q_OBJECT
    public:
       //to add a contact
       void add(Contact* c);
       //to remove a contact
       void remove(Contact* c);
       //to return the phone numbers of all the contacts
       QStringList getPhoneList(int c)const;
       //to return the addresses of all the contacts
       QStringList getMailingList(int c)const;
       //to return a string representation of all the contacts in the list
       QString toString()const;
       //to return the size of the list
       int getSize()const;
       //to return a specific contact based on phone number
       Contact * getContact(QString phone) const;
};

#endif
