#ifndef BLATT3_MISSILE_H
#define BLATT3_MISSILE_H


#include "Coordinates.h"


// TODO Aufgabe 3:
//  Implementiert die Klasse `Missile` als Erweiterung (Vererbung) der Klasse `Coordinates`, im Namensraum `GameObjects`.
namespace GameObjects {
    class Missile : public Sea::Coordinates {
    private:
        bool hit = false;
    public:
        Missile(Sea::Coordinates const & newCoordinates);
        void hitSomething();
        bool hasHitSomething() const;
    };


}



// TODO Aufgabe 3:
//  Entfernt die Kommentar-Zeichen (//), wenn Aufgabe 3 erledigt ist:
#define CLASS_MISSILE_COMPLETE


#endif //BLATT3_MISSILE_H
