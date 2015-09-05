//
//  Richer.cpp
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#include "Richer.h"

cocos2d::Size winSiz;
float winMidX;
float winMidY;
float tileSiz;
float tileScale;
float offsetX;
float offsetY;
float mapHeight, mapWidth;

std::vector<int> pnum;
int turn;
int day;

std::string pavatar[4] = {"richer1.png", "richer2.png", "richer3.png", "richer4.png"};
std::string houseImg[4][4] = {
    {"unoccupied.png", "home1_1.png", "home1_2.png", "home1_3.png"},
    {"unoccupied.png", "home2_1.png", "home2_2.png", "home2_3.png"},
    {"unoccupied.png", "home3_1.png", "home3_2.png", "home3_3.png"},
    {"unoccupied.png", "home4_1.png", "home4_2.png", "home4_3.png"}};

// issue: I want a better solution...
int string2Int(std::string str) {
    int ret;
    std::stringstream ss(str);
    ss >> ret;
    return ret;
}

int rollDice() {
    return rand() % 6 + 1;
}

void initWinSiz() {
    winSiz = cocos2d::Director::getInstance()->getWinSize();
    winMidX = winSiz.width/2;
    winMidY = winSiz.height/2;
    tileSiz = winSiz.height/PORTION_TILE_SIZE;
    tileScale = tileSiz / RES_SIZE;
    
    // position.x * tileSiz + offsetX = real position.x
    offsetX = tileSiz + tileSiz/2;
    // position.y * tileSiz + offsetY = real position.y
    offsetY = winSiz.height - tileSiz - (MAP_ROW-0.5)*tileSiz;
    
    mapWidth = MAP_COL * tileSiz + (winSiz.width/tileSiz - 1)*tileSiz;// + winSiz.width/PORTION_MAP_RIGHT_MARGIN;
    mapHeight = MAP_ROW * tileSiz + (PORTION_TILE_SIZE - 1)*tileSiz;// + winSiz.height/PORTION_MAP_BOTTOM_MARGIN;
}

Position::Position() {
    this->x = this->y = 0;
}
Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}
void Position::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}
bool Position::isEqual(Position other) {
    if(this->x == other.x && this->y == other.y)
        return true;
    else
        return false;
}
cocos2d::Vec2 Position::toRealPos() {
    return cocos2d::Vec2(x*tileSiz + offsetX, y*tileSiz + offsetY);
}

void resetGame() {
    pnum.clear();
    turn = 0;
    day = 0;
}