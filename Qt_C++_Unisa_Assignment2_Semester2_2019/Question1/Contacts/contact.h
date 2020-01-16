#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QObject>

class Contact : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int category READ getCategory)
    Q_PROPERTY(QString firstName READ getFirstName)
    Q_PROPERTY(QString lastName READ getLastName)
    Q_PROPERTY(QString streetAddress READ getStreetAddress)
    Q_PROPERTY(QString zipCode READ getZipCode)
    Q_PROPERTY(QString city READ getCity)
    Q_PROPERTY(QString phoneNumber READ getPhoneNumber)
    public:
       //constructor
       Contact(int c, QString fn, QString ln, QString sa, QString zc, QString cy, QString pn);
       //to return a string representation of contact
       QString toString()const;
       //getters
       int getCategory()const;
       QString getFirstName()const;
       QString getLastName()const;
       QString getStreetAddress()const;
       QString getZipCode()const;
       QString getCity()const;
       QString getPhoneNumber()const;
    private:
       //data members
       int category;
       QString firstName;
       QString lastName;
       QString streetAddress;
       QString zipCode;
       QString city;
       QString phoneNumber;
};

#endif

