#ifndef CONTACTREADER_H
#define CONTACTREADER_H

#include <QXmlDefaultHandler>
#include <QStringList>
#include <QList>
#include "contact.h"

class ContactReader : public QXmlDefaultHandler
{
public:
    ~ContactReader();
    bool startDocument();
    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts);
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
    bool endDocument();
    QList<Contact*> getList() const;
private:
    QList<Contact*> contactlist;
    QStringList details;
    bool inObject;
};

#endif
