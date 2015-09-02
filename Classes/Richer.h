//
//  Richer.h
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#ifndef Richer_Richer_h
#define Richer_Richer_h

#include <stdio.h>
#include <vector>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "Position.h"

// player status
#define STATUS_BROKE -1
#define STATUS_NORM 0
#define STATUS_INJURED 10
#define STATUS_INPRISON 100
#define STATUS_MONEYGOD 1000

// items
#define ITEM_BLOCK 0
#define ITEM_BOMB 1
#define ITEM_ROBOT 2
// 3 kinds of item
#define ITEM_KINDS 3

// land type
#define UNOCCUPIED 0
#define LV1 1
#define LV2 2
#define MAXLV 3
#define SHOP 4
#define GIFT 5
#define MAGIC 6
#define HOSPITAL 7
#define PRISON 8
#define MINE 9

#define TILE_SIZE 4

#define MAP_COL 28
#define MAP_ROW 8

extern cocos2d::Size winSiz;
extern float winMidX;
extern float winMidY;
extern float tileSiz;

extern int turn;
extern int day;

int rollDice();

void initWinSiz();
std::string int2Avatar(int i);
#endif
