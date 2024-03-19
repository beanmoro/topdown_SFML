#include "game.h"

Game::Game() :  gScreenDimension(1280, 720),
                gState(true){


}

Game::~Game(){



}


void Game::gRun(){

    gInit();
    gLoop();


}

void Game::gInit(){

    gWindow.create(sf::VideoMode(gScreenDimension.x, gScreenDimension.y), "TOP-DOWN");
    gPlayer.pInit();
    gMap.mCreate(1280/32, 720/32);

}

void Game::gLoop(){
    sf::Event e;

    while(gState){

        gMousePosition = sf::Mouse::getPosition(gWindow);


        while(gWindow.pollEvent(e)){

            if(e.type == sf::Event::Closed){

                gState = false;
            }
        }

        gPlayer.pUpdate(gMousePosition, gMap);
        gMap.mUpdate(gMousePosition);
        gDraw();
    }
}

void Game::gDraw(){

    gWindow.clear(sf::Color::Black);

    gPlayer.pDraw(&gWindow);
    gMap.mDraw(&gWindow);
    gWindow.display();
}
