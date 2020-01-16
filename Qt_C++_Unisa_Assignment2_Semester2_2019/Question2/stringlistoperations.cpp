#include "stringlistoperations.h"
#include <QStringListIterator>
#include <QTextStream>
#include <QMessageBox>

StringListOperations::StringListOperations()
{
}

StringListOperations::~StringListOperations (){

}

QVariant StringListOperations::addition (QVariant x, QVariant y){
//    QTextStream cout(stdout); //for debugging reseasons
    QStringList list1, list2, results, finalresults;
    QVariant outList;
    list1 = x.toString ().toLower ().split (",");
//    cout <<"Size of List1 " << list1.size () << endl;
    list2 = y.toString ().toLower ().split (",");
//    cout <<"Size of List2 " << list2.size () << endl;
    foreach (QString s, list1) {
        results += s;
//        cout << "List1 " << s << endl;
    }
    foreach (QString s, list2) {
//        cout << "List2 " << s << endl;
        results += s;
    }
    foreach (QString s, results) {
        finalresults += s.toUpper ();
    }
//    cout <<"Results size " << results.size () << endl;
//    results.toStdList ();
    finalresults.removeDuplicates ();
    outList.setValue(finalresults);
    return outList;
}

QVariant StringListOperations::subtraction (QVariant x, QVariant y){
    QStringList list1, list2,results;
    QVariant outList;
    list1 = x.toString ().toLower ().split (",");
    list2 = y.toString ().toLower ().split (",");
    foreach (QString s, list2) {
        if(list1.contains (s)){
            int index = list1.indexOf (s);
            list1.removeAt (index);
        }
    }
    foreach (QString s, list1) {
        results += s.toUpper ();
    }
    outList.setValue(results);
    return outList;
}
