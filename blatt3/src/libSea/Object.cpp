#include "Object.h"
#include "Coordinates.h"
#include <iostream>
using std::cout;

namespace Sea {

    Object::Object(Coordinates const & newCoordinates, unsigned int newSize, Sea::Orientation newOrientation)
    : Coordinates(newCoordinates), size(newSize), orientation(newOrientation)
    {
    }

    bool Object::atCoordinates(Coordinates const & coordinates) const
    {

        // TODO Aufgabe 2:
        //  Nutzt die Funktionalität von `Coordinates`, um zu bestimmen, ob ein Teil dieses Objekts auf den übergebenen Koordinaten (`coordinates`) liegt.
        // Bekomme coordinates als parameter, mit den Informationen die x und y des Feldes wo diese cordinates sind
        // nehme diese und vergleiche sie mit de

        auto orientationAsInt = static_cast<unsigned int> (orientation);
        if (orientationAsInt == 0) {
            for (int i = 0; i <= size; ++i) {
                if (coordinates.samePositionAs(x + i,y )){
                    cout << "Objekt liegt hier" << std::endl;
                    return true;
                }
            }
        }
        else if (orientationAsInt ==1){
            for (int i = 0; i <= size; ++i) {
                if (coordinates.samePositionAs(x ,y + i)){
                    cout << "Objekt liegt hier" << std::endl;
                    return true;
                }
            }
        }
        cout << "kein Objekt liegt hier" << std::endl;
        return false;

    }

    bool Object::intersectsWith(Object const & otherObject) const
    {
        // TODO Aufgabe 2:
        //  Nutzt die Funktion `atCoordinates(..)`, um zu bestimmen, ob sich dieses und das übergebene Objekt (`otherObject`) überschneiden.
        auto orientationAsInt = static_cast<unsigned int> (orientation);

        if (orientationAsInt == 0) {
            for (int i = 0; i < size; ++i) {
                if (otherObject.atCoordinates(Coordinates(x + i,y))) {
                    return true;
                }
            }
        }
        else if ( orientationAsInt == 1 ) {
            for (int i = 0; i < size; ++i) {
                if (otherObject.atCoordinates(Coordinates(x ,y + i))) {
                    return true;
                }
            }
        }
        return false;

    }

}
