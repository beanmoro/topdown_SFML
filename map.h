#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "includes.h"
#include "utilities.h"
#include "hitbox.h"
#include "pathfinding.h"

struct Map{

    int **mData;
    int mWidth, mHeight;
    void mCreate(int mapWidth, int mapHeight);
    void mUpdate(sf::Vector2i mouseCoords);
    void mDraw(sf::RenderWindow* window);

    void mDetectHitBox();

    bool mCheckCollision(sf::Vector2f position, sf::IntRect dimensions);
    bool mCheckSideCollision(sf::Vector2f position, sf::IntRect dimensions, int speed, SIDE _side);

    void mLoadMap(string filename);
    void mSaveMap(string filename);
    sf::Vector2i mLoadMapSize(string filename);
    void mResizeMap(sf::Vector2i newSize);

    sf::Texture mTexture;
    sf::Sprite mSprite;

    vector<sf::Sprite> mSpriteList;
    HitBox mHitbox;
    sf::IntRect mTileDimension;

    Pathfinding mPathfinging;

};



#endif // MAP_H_INCLUDED
