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

#define FACING_CLK 1
#define FACING_CCLK 0

// items
#define ITEM_BLOCK 0
#define ITEM_BOMB 1
#define ITEM_ROBOT 2
// 3 kinds of item
#define ITEM_KINDS 3
#define PLANT_DIST 10
// costs
extern int itemCost[ITEM_KINDS];

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

#define MAP_COL 29
#define MAP_ROW 8

extern cocos2d::Size winSiz;
extern float winMidX;
extern float winMidY;
extern float tileSiz;
extern float tileScale;
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
    cocos2d::Vec2 toRealPos();      // 转换成cocos2d坐标系坐标
    cocos2d::Vec2 toRealPosAbove(); // 转换成cocos2d坐标系坐标, 再往上一点...
};

// globals for game logic
extern std::vector<int> pnum;   // holds players' color and in the order of picks, size: 2~4
extern int turn;                // in the order of picks, turn changes from the first player to the second and son forth.
extern int day;                 // once every player ended his turn, day++
extern int add[ITEM_KINDS];     // used to pass on the choices in shop layer

extern std::string pavatar[4];
extern std::string houseImg[4][4];
extern std::string itemImg[ITEM_KINDS];

int string2Int(std::string str);
int rollDice();

void clearAdd();
void initWinSiz();
void resetGame();
#endif
