#include "ContactList.h"
#include <QList>

//adds a contact
void ContactList::add(Contact* c)
{
    c->setParent(this);
}

//removes a contact if in the list
void ContactList::remove(Contact* c)
{
    QList<Contact*> list = this->findChildren<Contact*>();
    foreach (Contact* co, list)
    {
        if((co->getFirstName() == c->getFirstName()) && (co->getLastName() == c->getLastName()))
        {
           delete co;
        }
    }
}

//returns the size of the list
int ContactList::getSize() const
{
   return this->findChildren<Contact*>().size();
}

//returns the phone list given a category
QStringList ContactList::getPhoneList(int c) const
{
    QStringList phoneList;
    QString entry;
    QList<Contact*> list = this->findChildren<Contact*>();
    foreach (Contact* co, list)
    {
       if (co->getCategory() == c)
       {
           entry = co->getFirstName()+ " " + co->getLastName() + ", " + co->getPhoneNumber();
           phoneList << entry;
       }
    }
    return phoneList;
}

//returns the addresses given a category
QStringList ContactList::getMailingList(int c) const
{
    QStringList mailingList;
    QString entry;
    QList<Contact*> list = this->findChildren<Contact*>();
    foreach (Contact* co, list)
    {
       if (co->getCategory() == c)
       {
           entry = co->getFirstName()+ " " + co->getLastName() + ", " +co->getStreetAddress()+ ", " + co->getCity()+ ", " +co->getZipCode();
           mailingList << entry;
       }
    }
    return mailingList;
}

//returns a string representation of the list
QString ContactList::toString() const
{
    QString entry;
    QList<Contact*> list = this->findChildren<Contact*>();
    foreach (Contact* co, list)
    {
       entry = entry + co->toString() + "\n";
    }
    return entry;
}

Contact * ContactList::getContact(QString phone) const
{
    QList<Contact*> list = this->findChildren<Contact*>();
    foreach (Contact* co, list)
        if(co->getPhoneNumber() == phone)
           return co;
    return NULL;
}
