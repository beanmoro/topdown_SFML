#ifndef BULLETS_H_INCLUDED
#define BULLETS_H_INCLUDED

#include "includes.h"
#include "map.h"
#include "hitbox.h"

struct Bullet{

    sf::Vector2f bPosition;
    sf::IntRect bDimensions;
    float bDirection;

    sf::Texture bTexture;
    sf::Sprite bSprite;

    int bSpeed;

    bool bOnUse;

    void bCreate(sf::Vector2f position, float direction, int speed);
    void bUpdate(Map _map);
    void bDestroy();

};




#endif // BULLETS_H_INCLUDED
