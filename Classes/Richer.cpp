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
float margin;
float offsetX;
float offsetY;
float mapHeight, mapWidth;

std::vector<int> pnum;
int turn;
int day;

int rollDice() {
    return rand() % 6 + 1;
}

void initWinSiz() {
    winSiz = cocos2d::Director::getInstance()->getWinSize();
    winMidX = winSiz.width/2;
    winMidY = winSiz.height/2;
    tileSiz = winSiz.height/PORTION_TILE_SIZE;
    tileScale = tileSiz / RES_SIZE;
    margin = winSiz.height/PORTION_MAP_MARGIN;
    // position.x * tileSiz + offsetX = real position.x
    offsetX = margin + tileSiz/2;
    // position.y * tileSiz + offsetY = real position.y
    offsetY = winSiz.height - margin - (MAP_ROW-0.5)*tileSiz;
    
    mapWidth = MAP_COL * tileSiz + 2 * margin;
    mapHeight = MAP_ROW * tileSiz + 2 * margin;
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

std::string int2Avatar(int i) {
    switch (i) {
        case 1: return "richer1.png";
        case 2: return "richer2.png";
        case 3: return "richer3.png";
        case 4: return "richer4.png";
        default: return "richer4.png";
    }
}

void resetGame() {
    pnum.clear();
    turn = 0;
    day = 0;
}