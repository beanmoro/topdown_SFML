#include "player.h"

Player::Player() :  pPosition( 10, 10),
                    pDimensions(0, 0, 32, 32),
                    pDirection(0),
                    pMovementButton({false, false, false, false}),
                    pSpeed(1),
                    pFireButton(false),
                    pFireDelay(0),
                    pFire(false)
                    {



}

Player::~Player(){



}

void Player::pInit(){



    pTexture.loadFromFile("player.png", pDimensions);
    pTexture.setSmooth(true);

    pSprite.setTexture(pTexture);
    pSprite.setOrigin(16,16);

    pFireTexture.loadFromFile("firegun.png", sf::IntRect(0,0,20,15));
    pFireTexture.setSmooth(true);

    pFireSprite.setTexture(pFireTexture);
    pFireSprite.setOrigin(0,8);

    pFireSoundFile.loadFromFile("gunshot.wav");
    pFireSound.setBuffer(pFireSoundFile);
    pFireSound.setVolume(5);

}

void Player::pUpdate(sf::Vector2i mouseCoords, Map _map){

    pDirection = 90 + -atan2(mouseCoords.x - pPosition.x, mouseCoords.y - pPosition.y) * 180/PI;


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){ pMovementButton[0] = true; }else{ pMovementButton[0] = false; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){ pMovementButton[1] = true; }else{ pMovementButton[1] = false; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){ pMovementButton[2] = true; }else{ pMovementButton[2] = false; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ pMovementButton[3] = true; }else{ pMovementButton[3] = false; }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){ pSpeed = 2; }else{ pSpeed = 1; }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){ pFireButton = true; }else{ pFireButton = false; }

    if(pMovementButton[0] && !_map.mHitbox.hCheckSideCollision(pPosition, pDimensions, pSpeed, LEFT)){ pPosition.x -= pSpeed; }
    if(pMovementButton[1] && !_map.mHitbox.hCheckSideCollision(pPosition, pDimensions, pSpeed, UP)){ pPosition.y -= pSpeed; }
    if(pMovementButton[2] && !_map.mHitbox.hCheckSideCollision(pPosition, pDimensions, pSpeed, RIGHT)){ pPosition.x += pSpeed; }
    if(pMovementButton[3] && !_map.mHitbox.hCheckSideCollision(pPosition, pDimensions, pSpeed, DOWN)){ pPosition.y += pSpeed; }
    pFireSound.setPosition(pPosition.x, pPosition.y, 0);
    pFire = false;
    if(pFireButton){
        if(pFireDelay > 10){
            Bullet tBullet;
            index++;
            if(index > 49){
                index = 0;
            }

            if(!pBullets[index].bOnUse){
                pBullets[index].bCreate(sf::Vector2f(pPosition.x+cos( pDirection * PI/180)*24, pPosition.y+sin( pDirection * PI/180)*24), pDirection+(rand() % 5 + 1), 5);
                pFireSound.play();
                pFire = true;
            }


            pFireDelay = 0;
        }
        pFireDelay++;
    }

    for(int i = 0; i < 50; i++){
        pBullets[i].bUpdate(_map);

        if(pBullets[i].bPosition.x < 0 || pBullets[i].bPosition.y < 0 || pBullets[i].bPosition.x > 1280 || pBullets[i].bPosition.y > 720){

            pBullets[i].bOnUse = false;

        }
    }


    pSprite.setRotation(pDirection);
    pFireSprite.setRotation(pDirection);
    pSprite.setPosition(pPosition);
    pFireSprite.setPosition(sf::Vector2f(pPosition.x+cos( pDirection * PI/180)*17, pPosition.y+sin( pDirection * PI/180)*17));

}

void Player::pDraw(sf::RenderWindow* window){

    window->draw(pSprite);
    for(int i = 0; i < 50; i++){
        if(pBullets[i].bOnUse){
            window->draw(pBullets[i].bSprite);
        }
    }
    if(pFire){

        window->draw(pFireSprite);
    }
}
