#include <iostream>

// TODO Aufgabe 3:
//  Inkludiert die Datei `euroCheck.h`.
#include "euroCheck.h"
using std::string;

// TODO Aufgabe 1:
//  Definiert die Funktion `inputNextSerialNumber()` so, dass sie eine Seriennummer als `string` auf der Konsole einliest und diese zurückgibt.
string inputNextSerialNumber(){
    string serialnumber;
    std::cout << "gib eine Nummer an: " << endl;
    std::cin >> serialnumber;
    //std::cout << serialnumber << endl;
    return serialnumber;
};

// TODO Aufgabe 3:
//  Implementiert die Funktion `checkSerialNumberAndPrintResult(serialNumber)`.
//  Sie soll mithilfe der Funktion `getEuroSerialNumberVersion(serialNumber)` ermitteln, um welche Version einer Euro-Banknote es sich handelt, und die entsprechende Jahreszahl in der Konsole ausgeben.
//  Anschliessend soll in einer Fallunterscheidung (switch) mit `checkEuroSerialNumber2013/2002(serialNumber)` die Gültigkeit geprüft, und das Ergebnis (Gueltig/Ungueltig) auf der Konsole ausgeben werden.
void checkSerialNumberAndPrintResult(string & serialNumber) {
    int jahr = getEuroSerialNumberVersion(serialNumber);
    cout  << "Diese Banknote ist vom Jahr: " << jahr <<endl;

    switch (jahr) {
        case 2013:
            checkEuroSerialNumber2013(serialNumber);
        case 2002:
            checkEuroSerialNumber2002(serialNumber);
    }

}

int main() {
    //string serialNumber;
    // TODO Aufgabe 4:
    //  Nutzt eine Kontrollstruktur, sodass nacheinander beliebig viele Seriennummern geprüft werden können.

//    while (serialNumber != "fertig") {
//        serialNumber = inputNextSerialNumber();
//        checkSerialNumberAndPrintResult(serialNumber);
//    }

//    string serialNumber = "D12345";
//    checkEuroSerialNumber2002(serialNumber);

    string serialNumber = "N6710165187";
    int numInInt = toNumber(serialNumber[0]);
    string num = to_string(numInInt);
    int quersumme = 0;

    //addition of the digits from converted letter, could be more than 1 digits number
    for (int i = 0; i < num.size(); ++i) {
        int number = toNumber(num[i]);
        quersumme = quersumme + number;
    }
    for (int i = 1; i < serialNumber.size(); ++i) {
        int number1 = toNumber(serialNumber[i]);
        quersumme = quersumme + number1;
    }
    int ziffer;
    int number = quersumme % 9;
    if (8 - number== 0 ) {
        ziffer = 0;
    } else ziffer = 8 - number;

    //Überprüfung der Kontrollnumer
    int quersumme2 = 0;
    for (int n = 1; n < serialNumber.size(); ++n) {
        int number1 = toNumber(serialNumber[n]);
        quersumme2 = quersumme2 + number1;
    }
    quersumme2 = quersumme2 + ziffer;


    while(quersumme2 > 9) {
        string pruefziffer = to_string(quersumme2);
        quersumme2 = 0;
        for (int f = 0; f < pruefziffer.size(); ++f) {
            int nummer = toNumber(pruefziffer[f]);
            quersumme2 = quersumme2 + nummer;
        }
    }
    cout << quersumme2 <<endl;

        // TODO Aufgabe 1:
        //  Ruft `inputNextSerialNumber()` auf, um eine Seriennummer einzugeben.
//        serialNumber = inputNextSerialNumber();

        // TODO Aufgabe 4:
        //  Das Programm soll beendet werden, wenn statt einer Seriennummer "fertig" eingegeben wurde.

    /*
     ???
     */

    return 0;
}
