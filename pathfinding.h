#ifndef PATHFINDING_H_INCLUDED
#define PATHFINDING_H_INCLUDED

#include "includes.h"
#include "hitbox.h"

struct pfNode{

    int gCost, hCost;
    int fCost(){return gCost+hCost;}
    sf::Vector2i coordOnGrid;
    sf::Vector2f pos;
    bool solid = false;
    pfNode* parent;



};


class Pathfinding {

public:

    Pathfinding();
    ~Pathfinding();

    void pfCreateGrid(sf::Vector2i mapSize, HitBox _hitbox);
    pfNode pfGetNode(sf::Vector2f position);
    void pfFindPath(sf::Vector2f orig, sf::Vector2f dest);



    int pfNodePerimeter;
    int pfNodeRadius;
    sf::Vector2i pfGridSize;


    vector<pfNode> pfNodeGrid;
    int** pfVirtualNodeGrid;



    private:




};


#endif // PATHFINDING_H_INCLUDED
