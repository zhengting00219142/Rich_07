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
float margin;

//Vector<int *> pnum;
int turn;
int day;

int rollDice() {
    return rand() % 6 + 1;
}

void initWinSiz() {
    winSiz = cocos2d::Director::getInstance()->getWinSize();
    winMidX = winSiz.width/2;
    winMidY = winSiz.height/2;
    tileSiz = winSiz.width/TILE_SIZE;
    margin = winSiz.width/MAP_MARGIN;
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
//    pnum.clear();
    turn = 0;
    day = 0;
}