#include "euroCheck.h"
#include <iostream>

using std::string;

bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);

// TODO Aufgabe 2:
//  Implementiert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
//  Sie soll je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für ungültige Seriennummern.
//  Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
int getEuroSerialNumberVersion(string & serialNumber) {
    if(isLetter(serialNumber[0])) {
        if (isLetter(serialNumber[1])) {
            return 2013;
        }
       return 2002;
    }
    else return 0;
}
// TODO Aufgabe 3+5:
//  Definiert die Funktion `checkEuroSerialNumber2002(serialNumber)`.
//  Format (Leerzeichen helfen nur beim Zählen): L NNNNNNNNNN N
bool checkEuroSerialNumber2002(std::string & serialNumber) {
    int numInInt = toNumber(serialNumber[0]);
    string num = to_string(numInInt);
    int quersumme = 0;
    int ziffer;
    //addition of the digits from converted letter, could be more than 1 digits number
    for (int i = 0; i < num.size(); ++i) {
        int number = toNumber(num[i]);
        quersumme = quersumme + number;
    }
    //addition from rest of serialNumber
    for (int i = 1; i < serialNumber.size()+1; ++i) {
        int number1 = toNumber(serialNumber[i]);
        quersumme = quersumme + number1;
    }

    int number = quersumme % 9;
    if (8 - number== 0 ) {
        ziffer = 0;
    } else ziffer = 8 - number;

    //Überprüfung der Kontrollnumer
    int quersumme2 = 0;
    for (int n = 1; n < serialNumber.size()+1; ++n) {
        int number1 = toNumber(serialNumber[n]);
        quersumme2 = quersumme2 + number1;
    }
    quersumme2 = quersumme2 + ziffer;
    while(quersumme2 > 9) {
        quersumme2 = quersumme2 / 9;
    }
    cout << quersumme2 <<endl;

    return true;
}

// TODO Aufgabe 3+6:
//  Definiert die Funktion `checkEuroSerialNumber2013(serialNumber)`.
//  Format (Leerzeichen helfen nur beim Zählen): LL NNNNNNNNN N
bool checkEuroSerialNumber2013(std::string & serialNumber){

    return true;

}


// L
bool isLetter(char c) {
    return 'A' <= c && c <= 'Z';
}
// N
bool isNumber(char c) {
    return '0' <= c && c <= '9';
}
int toNumber(char c) {
    if (isNumber(c)) {
        return c - '0';
    }
    if (isLetter(c)) {
        return c - 'A' + 1;
    }
    std::cout << "Error: toNumber(char): " << c << std::endl;
    return 0;
}
