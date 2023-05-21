#include "Missile.h"
#include "Coordinates.h"

// TODO Aufgabe 3:
//  Definiert die Funktionen der Klasse `Missile`.

namespace GameObjects {
    GameObjects::Missile::Missile(const Sea::Coordinates &newCoordinates)
    : Sea::Coordinates(newCoordinates)
    {
    }

    void GameObjects::Missile::hitSomething() {
        hit = true;
    }

    bool GameObjects::Missile::hasHitSomething() const {
        return hit;
    }
}



