#include "utilities.h"

bool checkCollision(sf::Vector2f aPosition, sf::IntRect aDimensions, sf::Vector2f bPosition, sf::IntRect bDimensions){

    if( aPosition.x < bPosition.x+bDimensions.width  &&
        aPosition.x+aDimensions.width > bPosition.x  &&
        aPosition.y < bPosition.y+bDimensions.height &&
        aPosition.y+aDimensions.height > bPosition.y
    ){

        return true;
    }else{
        return false;
    }

}

bool checkSideCollision(sf::Vector2f oPosition, sf::IntRect oDimensions, sf::Vector2f dPosition, sf::IntRect dDimensions, SIDE side, int speed){

    int borde = 4;

    if(side == LEFT){

        if( oPosition.x-(oDimensions.width/2)-speed > dPosition.x &&
            oPosition.y+(oDimensions.height/2)-borde > dPosition.y &&
            oPosition.x-(oDimensions.width/2)-speed < dPosition.x+dDimensions.width &&
            oPosition.y-(oDimensions.height/2)+borde < dPosition.y+dDimensions.height
        ){

            return true;
        }else{
            return false;
        }

    }else if(side == UP){

        if( oPosition.x+(oDimensions.width/2)-borde > dPosition.x &&
            oPosition.y-(oDimensions.height/2)-speed  > dPosition.y &&
            oPosition.x-(oDimensions.width/2)+borde < dPosition.x+dDimensions.width &&
            oPosition.y-(oDimensions.height/2)-speed < dPosition.y+dDimensions.height
        ){

            return true;
        }else{
            return false;
        }


    }else if(side == RIGHT){

        if( oPosition.x+(oDimensions.width/2)+speed > dPosition.x &&
            oPosition.y+(oDimensions.height/2)-borde > dPosition.y &&
            oPosition.x+(oDimensions.width/2)+speed < dPosition.x+dDimensions.width &&
            oPosition.y-(oDimensions.height/2)+borde < dPosition.y+dDimensions.height
        ){

            return true;
        }else{
            return false;
        }

    }else if(side == DOWN){

        if( oPosition.x+(oDimensions.width/2)-borde > dPosition.x &&
            oPosition.y+(oDimensions.height/2)+speed  > dPosition.y &&
            oPosition.x-(oDimensions.width/2)+borde < dPosition.x+dDimensions.width &&
            oPosition.y+(oDimensions.height/2)+speed < dPosition.y+dDimensions.height
        ){

            return true;
        }else{
            return false;
        }

    }else if(side == LEFT_UP){

        if( oPosition.x-(oDimensions.width/2)-speed > dPosition.x &&
            oPosition.y-(oDimensions.height/2)-speed  > dPosition.y &&
            oPosition.x-(oDimensions.width/2)-speed < dPosition.x+dDimensions.width &&
            oPosition.y-(oDimensions.height/2)-speed < dPosition.y+dDimensions.height
        ){

            return true;

        }else{

            return false;
        }


    }else if(side == RIGHT_UP){

        if( oPosition.x+(oDimensions.width/2)+speed  > dPosition.x &&
            oPosition.y-(oDimensions.height/2)-speed > dPosition.y &&
            oPosition.x+(oDimensions.width/2)+speed < dPosition.x+dDimensions.width &&
            oPosition.y-(oDimensions.height/2)-speed < dPosition.y+dDimensions.height
        ){

            return true;
        }else{
            return false;
        }


    }else if(side == RIGHT_DOWN){

        if( oPosition.x+(oDimensions.width/2)+speed > dPosition.x &&
            oPosition.y+(oDimensions.height/2)+speed > dPosition.y &&
            oPosition.x+(oDimensions.width/2)+speed < dPosition.x+dDimensions.width &&
            oPosition.y+(oDimensions.height/2)+speed < dPosition.y+dDimensions.height
        ){

            return true;
        }else{
            return false;
        }


    }else if(side == LEFT_DOWN){

        if( oPosition.x-(oDimensions.width/2)-speed > dPosition.x &&
            oPosition.y+(oDimensions.height/2)+speed  > dPosition.y &&
            oPosition.x-(oDimensions.width/2)-speed < dPosition.x+dDimensions.width &&
            oPosition.y+(oDimensions.height/2)+speed < dPosition.y+dDimensions.height
        ){

            return true;

        }else{

            return false;
        }




    }

}
