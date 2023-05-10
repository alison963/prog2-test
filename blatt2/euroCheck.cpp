#include "euroCheck.h"
#include <iostream>
#include <unordered_map>
using std::string;

bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);
int neunerrest(int quersumme);


unordered_map<char,int> nums2002 {
        {'Z',9},{'Y',1},{'X',2},{'W',3},{'V',4},{'U',5},
        {'T',6},{'S',7},{'R',8},{'P',1},{'N',3},{'M',4},
        {'L',5},{'K',6},{'J',7},{'H',8},{'G',1},
        {'D',2},{'E',3},{'D',4},{'C',5},{'B',6}

};

// TODO Aufgabe 2:
//  Implementiert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
//  Sie soll je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für ungültige Seriennummern.
//  Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
int getEuroSerialNumberVersion(string & serialNumber) {
    if (serialNumber.size() == 12) {
        if(isLetter(serialNumber[0])) {
            if (isLetter(serialNumber[1])) {
                return 2013;
            }
            return 2002;
        }
        return 0;
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

    //quersumme der konvertierten Zahl
    for (int i = 0; i < num.size() ; ++i) {
        int number = toNumber(num[i]);
        quersumme = quersumme + number;
    }
    //+ die Quersumme über alle Zahlen
    for (int i = 1; i < serialNumber.size() - 1 ; ++i) {
        int number1 = toNumber(serialNumber[i]);
        quersumme = quersumme + number1;
    }
    int ziffer;
    int number = quersumme % 9;
    if (8 - number== 0 ) {
        ziffer = 0;
    } else ziffer = 8 - number;
    int pz = toNumber(serialNumber[11]);
    if (ziffer == pz) {
        //Überprüfung der Kontrollnumer
        int quersumme2 = 0;
        //die quersumme über der 10 stelligen Nummer
        for (int n = 1; n < serialNumber.size(); ++n) {
            int number1 = toNumber(serialNumber[n]);
            quersumme2 = quersumme2 + number1;
        }
        int finalNum = neunerrest(quersumme2);
        cout << "erster Buchstabe hat den Wert: " << nums2002[serialNumber[0]] <<" und finalwert ist " << finalNum << endl;
        if(nums2002[serialNumber[0]] == finalNum) {
            return true;
        }
        else
            return false;
    }
    return false;

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

int neunerrest (int quersumme) {
    while(quersumme > 9) {
        string pruefziffer = to_string(quersumme);
        quersumme = 0;
        for (int f = 0; f < pruefziffer.size(); ++f) {
            int nummer = toNumber(pruefziffer[f]);
            quersumme = quersumme + nummer;
        }
    }
    return quersumme;
}