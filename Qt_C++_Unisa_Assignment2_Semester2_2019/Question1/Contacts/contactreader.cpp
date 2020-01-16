#include "contactreader.h"

#include <QDebug>

ContactReader::~ContactReader()
{}

bool ContactReader::startDocument()
{
    return true;
    inObject = false;
}

bool ContactReader::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    Q_UNUSED(namespaceURI); Q_UNUSED(localName);

    // ensure that we are in a Contact object
    if (qName == "object")
    {
        if (atts.value("class") == "Contact")
        {
            inObject = true;
        }
    }

    // gather all the attribute data
    if (qName == "property")
    {
        details.append(atts.value("value"));
    }
    return true;
}

bool ContactReader::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    Q_UNUSED(namespaceURI); Q_UNUSED(localName);

    if (qName == "object")
    {
        if (inObject)
        {
            Contact *c = new Contact(details.at(0).toInt(), details.at(1), details.at(2), details.at(3), details.at(4), details.at(5), details.at(6));
            contactlist.append(c);
            details.clear();
            inObject = false;
        }
    }
    return true;
}

bool ContactReader::endDocument()
{
    return true;
}

QList<Contact*> ContactReader::getList() const
{
    return contactlist;
}
