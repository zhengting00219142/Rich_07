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
}

std::string int2Avatar(int i) {
    switch (i) {
        case 1: return "CloseSelected.png";
        case 2: return "CloseSelected.png";
        case 3: return "CloseSelected.png";
        case 4: return "CloseSelected.png";
        default: return "CloseSelected.png";
    }
}