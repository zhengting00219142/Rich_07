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
#define LTYPE_UNOCCUPIED 0
#define LTYPE_LV1 1
#define LTYPE_LV2 2
#define LTYPE_MAXLV 3
#define LTYPE_SHOP 4
#define LTYPE_GIFT 5
#define LTYPE_MAGIC 6
#define LTYPE_HOSPITAL 7
#define LTYPE_PRISON 8
#define LTYPE_MINE 9
#define LTYPE_NOTHING 10

#define RES_SIZE 1024
// 1/4 of screen height = tile width = tile height
#define PORTION_TILE_SIZE 4
// 1/16 of screen height = map's margin
#define PORTION_MAP_MARGIN 16

#define MAP_COL 29
#define MAP_ROW 8

extern cocos2d::Size winSiz;
extern float winMidX;
extern float winMidY;
extern float tileSiz;
extern float tileScale;
extern float margin;
extern float offsetX;
extern float offsetY;
extern float mapHeight, mapWidth;

class Position {
public:
    int x, y;
    
    Position();
    Position(int x, int y);
    void setPosition(int x, int y);
    bool isEqual(Position other);
    cocos2d::Vec2 toRealPos();
};

// size: 2~4
extern std::vector<int> pnum;
extern int turn;
extern int day;

int rollDice();

void initWinSiz();
std::string int2Avatar(int i);
void resetGame();
#endif
