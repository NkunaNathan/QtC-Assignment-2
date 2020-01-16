#include "contactfactory.h"

#include <QTextStream>

QTextStream cout(stdout);

//creates random contacts using ContactFactory
void createRandomContacts(ContactList& cl, int n=10) {
    static ContactFactory cf;
    for (int i=0; i<n; ++i) {
        //cf >> cl;
        cl.add(cf.createContact());
    }
}

int main()
{
    ContactList l1;
    createRandomContacts(l1);

    cout << "Here is the list of randomly generated contacts:"<< endl;
    cout << endl;
    cout << l1.toString();

    int i = 1;

    cout << endl;
    cout<< "Here is the list of telephone numbers of contacts in category " << i << endl;

    QStringList pl = l1.getPhoneList(i);
    foreach(QString s, pl){
        cout<< s <<endl;
    }

    cout << endl;
    cout<< "Total number of contacts is: " << l1.getSize()<<endl;
    cout<<"Number of contacts in category " << i << " is " << pl.size()<<endl;

    i =3;

    cout << endl;
    cout<< "Here is the list of mailing addresses of contacts in category " << i <<endl;
    pl = l1.getMailingList(i);
    foreach(QString s, pl){
        cout<< s<< endl;
    }

    cout << endl;
    cout<<"Total number of contacts is : " << l1.getSize()<<endl;
    cout<<"Number of contacts in category " << i << " is " << pl.size()<<endl;
    cout<<endl;

    Contact* c1 = new Contact(5,"Jay", "Manale", "School of Computing, UNISA", "0003", "Pretoria","012 345 678");
    cout<< "Adding a new contact..." << endl;
    l1.add(c1);
    cout<< "Updated size of the contact list : " << l1.getSize()<< endl;
    cout<< "Updated contact list : " << endl;
    cout<< l1.toString() << endl;
    cout<< "Removing a contact... " << endl;
    l1.remove(c1);
    cout<< "Updated size of the contact list : " << l1.getSize()<< endl;
    cout<< "Updated contact list : " << endl;
    cout<< l1.toString() << endl;

    return 0;
}
