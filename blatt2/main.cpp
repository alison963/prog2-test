#include <iostream>
#include <unordered_map>
#include <map>
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
            if (checkEuroSerialNumber2013(serialNumber))
                cout << "gueltig" << endl;
            else cout << "nicht" << endl;

        case 2002:
            if (checkEuroSerialNumber2002(serialNumber))
                cout << "gueltig" << endl;
            else cout << "nicht" << endl;
    }

}

int main() {
    string serialNumber;
    // TODO Aufgabe 4:
    //  Nutzt eine Kontrollstruktur, sodass nacheinander beliebig viele Seriennummern geprüft werden können.

    while (serialNumber != "fertig") {
        serialNumber = inputNextSerialNumber();
        checkSerialNumberAndPrintResult(serialNumber);
    }







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
