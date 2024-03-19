#include "pathfinding.h"


Pathfinding::Pathfinding(){


}

Pathfinding::~Pathfinding(){


}

void Pathfinding::pfCreateGrid(sf::Vector2i mapSize, HitBox _hitbox){


    pfNodeRadius = 16;
    pfNodePerimeter = pfNodeRadius*2;

    pfGridSize.x = (mapSize.x/pfNodePerimeter);
    pfGridSize.y = (mapSize.y/pfNodePerimeter);

    pfVirtualNodeGrid = new int*[pfGridSize.y];
    for(int i = 0; i < pfGridSize.y; i++){
        pfVirtualNodeGrid[i] = new int[pfGridSize.x];
    }

    for(int i = 0; i < pfGridSize.y; i++){
        for(int j = 0; j < pfGridSize.x; j++){
            pfNode node;
            node.pos.x = j*32+pfNodeRadius;
            node.pos.y = i*32+pfNodeRadius;
            node.coordOnGrid.x = j;
            node.coordOnGrid.y = i;

            if(_hitbox.hCheckCollision(sf::Vector2f( j*32,i*32), sf::IntRect(0,0,pfNodePerimeter, pfNodePerimeter))){
                node.solid = true;
            }
            pfNodeGrid.push_back(node);
        }
    }
}

pfNode Pathfinding::pfGetNode(sf::Vector2f position){
    sf::Vector2i pos = sf::Vector2i(position.x/32, position.y/32);
    for(vector<pfNode>::iterator it = pfNodeGrid.begin(); it != pfNodeGrid.end(); ++it){
        if(it->coordOnGrid == pos){
            return (*it);
        }
    }
}

void Pathfinding::pfFindPath(sf::Vector2f orig, sf::Vector2f dest){
    pfNode startNode = pfGetNode(orig);
    pfNode targetNode = pfGetNode(dest);

    vector<pfNode> openSet;
    vector<pfNode> closedSet;
    openSet.push_back(startNode);

    while(!openSet.empty()){
        pfNode currentNode = openSet[0];
        for(int i = 1; i < openSet.size(); i++){
            if(openSet[i].fCost() <= currentNode.fCost()|| openSet[i].hCost < currentNode.hCost){
                currentNode = openSet[i];
            }
        }

        for(vector<pfNode>::iterator it = openSet.begin(); it != openSet.end(); it++){
            if( it->coordOnGrid == currentNode.coordOnGrid ){
                swap(*it, openSet.back());
                openSet.pop_back();
                break;
            }
        }
        closedSet.push_back(currentNode);



    }



}
