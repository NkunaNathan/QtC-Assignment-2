#include "stringoperations.h"
#include <QRegularExpression>
//#include <QStringList>
//#include <QTextStream>


StringOperations::StringOperations(){
}
StringOperations::~StringOperations (){

}

QVariant StringOperations::addition (QVariant x, QVariant y){
    QString X = x.toString ();
    QString Y = y.toString ();
    QString rslt = X.append (Y);
    QVariant result;
    result.setValue(rslt);
    return result;
//    could've written a one line return statement
//    return QVariant(x.toString () + y.toString ());
}

QVariant StringOperations::subtraction (QVariant x, QVariant y){
//    QTextStream cout(stdout); for debugging reasons
    int comp = QString::compare (x.toString (),y.toString (),Qt::CaseInsensitive);
//    cout << comp << endl;
    QString s1, s2;
    QString s3 = "";
//    QString toRemove;
    QVariant results;
    s1 = x.toString ().toLower ();
    s2 = y.toString ().toLower ();

    if(comp != 0){
        for(int j(0); j < s2.length (); j++){
            QString istring = static_cast<QString> (s2[j]);
//            cout <<"Checking " << istring << endl;
//            cout << "contains" << s1.contains (istring,Qt::CaseInsensitive) << endl;
            if(s1.contains (istring,Qt::CaseInsensitive)){
//                toRemove = static_cast<QString>(s1[j]);
//                cout <<"Checking == toRemove" << toRemove << endl;
                s1.remove (QRegularExpression(istring));
           }
        }
//        cout << s1 << endl;
        results.setValue(s1.toUpper ());
    }else{
        results.setValue(s3);
    }
    return results;
}
