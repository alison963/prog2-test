#include <iostream>
#include <vector>
using std::vector;

#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "init.h"
#include "game.h"
#include "test.h"


int main()
{
//    if (testPassed()) {
//        vector<PlayerSea> playerSeas;
//        initializePlayerSeasWithShips(playerSeas);
//
//        gameLoop(playerSeas);
//    }
Sea::Object obj1(Sea::Coordinates(0,1),3,Sea::Orientation::X);
Sea::Object obj2(Sea::Coordinates(0,0),3,Sea::Orientation::Y);

    if (obj1.intersectsWith(obj2)) std::cout << "true";
return 0;
}
