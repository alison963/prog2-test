#ifndef BLATT2_EUROCHECK_H
#define BLATT2_EUROCHECK_H

#include <string>
using namespace std;
// TODO Aufgabe 2:
//  Deklariert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
int getEuroSerialNumberVersion(string & serialNumber);
int toNumber(char c);
bool checkEuroSerialNumber2002(std::string & serialNumber);
bool checkEuroSerialNumber2013(std::string & serialNumber);

#endif //BLATT2_EUROCHECK_H
