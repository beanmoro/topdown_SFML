#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "includes.h"

enum SIDE {LEFT, UP, RIGHT, DOWN, LEFT_UP, RIGHT_UP, RIGHT_DOWN, LEFT_DOWN};

//Collisions
bool checkCollision(sf::Vector2f aPosition, sf::IntRect aDimensions, sf::Vector2f bPosition, sf::IntRect bDimensions);
bool checkSideCollision(sf::Vector2f oPosition, sf::IntRect oDimensions, sf::Vector2f dPosition, sf::IntRect dDimensions, SIDE side, int speed);




#endif // UTILITIES_H_INCLUDED
