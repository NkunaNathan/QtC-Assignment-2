#include "ContactFactory.h"
#include <QTime>

//constructor initializing data members with random data
ContactFactory::ContactFactory(){
firstNames<< "AB" << "CD" << "FF" << "G" << "ANN" << "Leo" << "Mathe" << "Marthe" << "Lata" << "Mersault" << "Gerald" << "Tonic" << "Tom" << "Anna" << "Hilda";
lastNames<< "Botha" << "Viljoen" << "Kotze" << "Mentz" << "van der Merwe" << "Naidoo" << "Liang" << "Kritzinger" << "Becker" << "Lubbe" << "Engelbrecht" << "Schoeman"<< "Horne" << "Eloff" << "Selati";
streetAddresses<< "32 Menlyn" << "1 Kelvin" << "74 - 23rd street" << "100 Lion" << "3 Protea Road" << "302 Muskejaat" << "45 Lois Street" << "100 skillpad" << "29 Atterbury Road" << "567 Selati Street" << "34 Preller Street" << "75 Puzzle Road" <<"100 Endless Street" << "45 Leask Street" << "786 Good Hope";
zipCodes<< "0001" << "0010" << "0100" << "1000"<< "1001" << "1010" << "1100" << "1101" << "1110" << "1111" << "1002"<< "1003" << "3045" << "1005" << "0003";
cities << "Pretoria" << "Victoria" << "East City" << "West Rand" << "Potchefstroom" << "Mogale City" << "Cape City" << "Milton" << "Port Elizebath" << "Klersdorp" << "Krugersdorp" << "Randburg" << "Florida" << "Randfontein" << "Ventersdorp";
phoneNumbers << "012 4419087" << "022 4699087" << "013 4699000" << "018 4520123" << "025 1238567" <<"014 5967824" << "015 8951234" << "078 4699123" << "074 3546902" << "020 7864532" <<"032 3402789" <<"004 7878990" <<"034 8902346" <<"021 6748321" <<"022 6990001";

qsrand(QTime::currentTime().msec());
}

//creates and returns a Contact, where the information is randomnly selected
Contact* ContactFactory:: createContact(){
    return (new Contact((qrand()% 3 + 1), firstNames.at((qrand()% 15)), lastNames.at((qrand()% 15)),streetAddresses.at((qrand()% 15)), zipCodes.at((qrand()% 15)), cities.at((qrand()% 15 )), phoneNumbers.at((qrand()% 15 ))));
}


