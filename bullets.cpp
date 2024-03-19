#include "bullets.h"


void Bullet::bCreate(sf::Vector2f position, float direction, int speed){
    bOnUse = true;
    bPosition = position;
    bDirection =  direction;
    bSpeed = speed;
    bDimensions = {0,0,16,16};
    bTexture.loadFromFile("bullet.png", bDimensions);
    bSprite.setTexture(bTexture);
    bSprite.setOrigin(4,4);
}

void Bullet::bUpdate(Map _map){
    if(bOnUse){
        //Movimiento
        bPosition.x += bSpeed * cos( bDirection * PI/180);
        bPosition.y += bSpeed * sin( bDirection * PI/180);

        bSprite.setPosition(bPosition);


        //Colisiones

        if(_map.mHitbox.hCheckCollision(sf::Vector2f(bPosition.x-2, bPosition.y-2), sf::IntRect(0,0,bDimensions.width-2, bDimensions.height-2))){

            if( (rand() % 10 + 1) > 5){
                bDestroy();
            }else{
                bDirection += -90;

            }
        }

        bSprite.setRotation(bDirection);

    }

}

void Bullet::bDestroy(){
    bOnUse = false;
    bSpeed = 0;
}
