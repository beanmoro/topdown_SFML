#include "map.h"

void Map::mCreate(int mapWidth, int mapHeight){

    mTileDimension = {0,0,32,32};
    mWidth = mapWidth;
    mHeight = mapHeight;

    mData = new int*[mHeight];
    for(int i = 0; i < mHeight; i++){
        mData[i] = new int[mWidth];
    }

    for(int i = 0; i < mHeight; i++){
        for(int j = 0; j < mWidth; j++){
            mData[i][j] = 0;
        }
    }
    mTexture.loadFromFile("wall.png", mTileDimension);

    mLoadMap("00.map");
    mDetectHitBox();

    mPathfinging.pfCreateGrid(sf::Vector2i(1280, 720), mHitbox);
}

void Map::mDraw(sf::RenderWindow* window){

    for(vector<sf::IntRect>::iterator it = mHitbox.hList.begin(); it != mHitbox.hList.end(); ++it){
        mSprite.setTexture(mTexture);
        mSprite.setPosition(sf::Vector2f(it->left, it->top));
        mSprite.setColor(sf::Color::White);
        window->draw(mSprite);

    }

    for(vector<pfNode>::iterator it = mPathfinging.pfNodeGrid.begin(); it != mPathfinging.pfNodeGrid.end(); ++it){
        if(it->solid){
            mSprite.setTexture(mTexture);
            mSprite.setPosition(sf::Vector2f(it->pos.x-16, it->pos.y-16));
            mSprite.setColor(sf::Color::Red);
            window->draw(mSprite);
        }

    }

}

void Map::mUpdate(sf::Vector2i mouseCoords){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        for(int i = 0; i < mHeight; i++){
            for(int j = 0; j < mWidth; j++){
                if(mouseCoords.x > j*32 && mouseCoords.y > i*32 && mouseCoords.x < (j*32)+32 && mouseCoords.y < (i*32)+32){

                    if(mData[i][j] == 0){
                        mHitbox.hList.push_back(sf::IntRect(j*32, i*32, 32,32));
                    }
                    mData[i][j] = 1;

                }
            }
        }
    }
}


void Map::mDetectHitBox(){

    for(int i = 0; i < mHeight; i++){
        for(int j = 0; j < mWidth; j++){
            if(mData[i][j] == 1){
                mHitbox.hList.push_back(sf::IntRect(j*32, i*32, 32,32));

            }
        }
    }

}

void Map::mLoadMap(string filename){

    sf::Vector2i fileSize;
    fstream file;
    file.open(filename.c_str(), ios::in);

    if(file.is_open()){
        fileSize = mLoadMapSize(filename);
        mResizeMap(fileSize);

        for(int i = 0; i < fileSize.y; i++){
            for(int j = 0; j < fileSize.x; j++){

                file >> mData[i][j];

            }
        }

    }

    file.close();
}

void Map::mSaveMap(string filename){

    ofstream file;
    file.open(filename.c_str(), ios::out);

    if(file.is_open()){
        for(int i = 0; i < mHeight; i++){
            for(int j = 0; j < mWidth; j++){
                file << mData[i][j] << " ";
            }
            file << endl;
        }

    }
    file.close();
}

sf::Vector2i Map::mLoadMapSize(string filename){

    ifstream file;
    string line;
    string element;
    file.open(filename.c_str(), ios::in);
    sf::Vector2i fileSize;

    if(file.is_open()){

        while(getline(file, line)){
            istringstream stream(line);
            fileSize.x = 0;
            while(stream >> element){
                fileSize.x++;
            }
            fileSize.y++;
        }

    }
    file.close();
    return fileSize;

}

void Map::mResizeMap(sf::Vector2i newSize){

   /* if(mData != NULL){
        for(int i = 0; i < mHeight; i++){
            delete []mData[i];
        }
        delete []mData;
    }*/

    mWidth = newSize.x;
    mHeight = newSize.y;
    /*
    mData = new int*[newSize.y];
    for(int i = mHeight; i < newSize.y; i++){
        mData[i] = new int[newSize.x];
    }*/
}
