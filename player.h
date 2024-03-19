#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "includes.h"
#include "bullets.h"
#include "map.h"
#include "utilities.h"

class Player {

public:
    Player();
    ~Player();

    void pInit();
    void pUpdate(sf::Vector2i mouseCoords, Map _map);
    void pDraw(sf::RenderWindow* window);


private:

    sf::Vector2f pPosition;
    sf::IntRect pDimensions;
    float pDirection;
    float pSpeed;

    sf::Texture pTexture;
    sf::Sprite pSprite;

    //capricho
    sf::Texture pFireTexture;
    sf::Sprite  pFireSprite;
    bool pFire;
    sf::SoundBuffer pFireSoundFile;
    sf::Sound pFireSound;

    bool pMovementButton[4];
    bool pFireButton;
    int index = 0;
    int pFireDelay;

    Bullet pBullets[200];



};

#endif // PLAYER_H_INCLUDED
