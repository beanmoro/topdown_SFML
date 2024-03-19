#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED

#include "includes.h"

class Zombie {

public:

    Zombie();
    ~Zombie();

    void zCreate();
    void zUpdate();
    void zDraw();

private:

    sf::Vector2f zPosition;
    sf::IntRect zDimensions;
    float zDirection;
    float zSpeed;

    sf::Texture zTexture;
    sf::Sprite zSprite;

};

#endif // ZOMBIE_H_INCLUDED
