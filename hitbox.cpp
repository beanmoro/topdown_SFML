#include "hitbox.h"

bool HitBox::hCheckCollision(sf::Vector2f position, sf::IntRect dimensions){

    for(vector<sf::IntRect>::iterator it = hList.begin(); it != hList.end(); ++it){

        if(checkCollision(position, dimensions, sf::Vector2f(it->left,it->top), sf::IntRect(0,0,it->width,it->height))){
            return true;
        }

    }

    return false;
}

bool HitBox::hCheckSideCollision(sf::Vector2f position, sf::IntRect dimensions, int speed, SIDE _side){


    for(vector<sf::IntRect>::iterator it = hList.begin(); it != hList.end(); ++it){

        if(checkSideCollision(position, dimensions, sf::Vector2f(it->left, it->top), sf::IntRect(0,0,it->width,it->height), _side, speed)){
            return true;
        }

    }
    return false;

}
