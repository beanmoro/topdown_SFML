#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "includes.h"
#include "player.h"
#include "map.h"

class Game {
public:
    Game();
    ~Game();

    void gRun();

private:
    void gInit();
    void gLoop();
    void gDraw();

    sf::RenderWindow gWindow;
    sf::Vector2i gScreenDimension;

    sf::Vector2i gMousePosition;

    Player gPlayer;

    Map gMap;

    bool gState;


};



#endif // GAME_H_INCLUDED
