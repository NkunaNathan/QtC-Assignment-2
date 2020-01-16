#include "contact.h"

//constructor
Contact::Contact(int c, QString fn, QString ln, QString sa, QString zc, QString cy, QString pn):category(c),firstName (fn), lastName (ln), streetAddress(sa), zipCode(zc), city (cy), phoneNumber(pn)
{}

//returns the category
int Contact::getCategory()const{
    return category;
}

//returns the first name
QString Contact::getFirstName()const{
    return firstName;
}

//returns the last name
QString Contact::getLastName()const{
    return lastName;
}

//returns the street address
QString Contact::getStreetAddress()const{
    return streetAddress;
}

//returns the zip code
QString Contact::getZipCode()const{
    return zipCode;
}

//returns the city
QString Contact::getCity()const{
    return city;
}

//returns the phone number
QString Contact::getPhoneNumber()const{
    return phoneNumber;
}

//returns the string representation of contact
QString Contact::toString()const{
    QString result = QString::number(category,10) + ", " + firstName + " " + lastName + ", " + streetAddress +  ", " + zipCode + ", " + city + ", " + phoneNumber;
    return result;
}
