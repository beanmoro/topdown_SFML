#ifndef HITBOX_H_INCLUDED
#define HITBOX_H_INCLUDED

#include "includes.h"
#include "utilities.h"

class HitBox{

public:
    vector<sf::IntRect> hList;

    bool hCheckCollision(sf::Vector2f position, sf::IntRect dimensions);;
    bool hCheckSideCollision(sf::Vector2f position, sf::IntRect dimensions, int speed, SIDE _side);

};


#endif // HITBOX_H_INCLUDED
