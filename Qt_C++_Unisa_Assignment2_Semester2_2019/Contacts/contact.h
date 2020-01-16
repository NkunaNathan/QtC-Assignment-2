#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QObject>

class Contact : public QObject {
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

