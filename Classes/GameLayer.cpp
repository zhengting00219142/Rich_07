//
//  GameLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#include "GameLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameLayer::createScene(int fund)
{
    auto scene = Scene::create();
    auto layer = GameLayer::create(fund);
    scene->addChild(layer, 3);
    
    auto toolsLayer = ToolsLayer::create();
    scene->addChild(toolsLayer, 2);
//    auto bg = ColorLayer::create();
//    scene->cocos2d::Node::addChild(bg, 1);
    
    return scene;
}

GameLayer *GameLayer::create(int fund)
{
    GameLayer *ret = new (std::nothrow) GameLayer();
    
    // init players
//    for(int i = 0; i < pnum.size(); i++) {
//        PlayerSprite *player = PlayerSprite::create(int2Avatar(*pnum.at(i)), fund);
//        player->p = Position(0, MAP_ROW-1);
//        ret->playerSprites.pushBack(player);
//        ret->addChild(player, 2);
//    }
    
    if (ret && ret->init())
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

GameLayer::GameLayer()
{
    // init lands
    mapWidth = MAP_COL * tileSiz + 2 * margin;
    mapHeight = MAP_ROW * tileSiz + 2 * margin;
    for(int i = 0, y = MAP_ROW-1; i < MAP_COL; i++) {
        LandSprite *land;
        if(i == 0) {
            land = LandSprite::create();
            land->setUp(LTYPE_NOTHING, 0, i, y);
        }
        else if(i == 14) {
            land = LandSprite::create("");
            land->setUp(LTYPE_HOSPITAL, 0, i, y);
        }
        else if(i == MAP_COL-1) {
            land = LandSprite::create("");
            land->setUp(LTYPE_SHOP, 0, i, y);
        }
        else {
            land = LandSprite::create("");
            land->setUp(LTYPE_UNOCCUPIED, 200, i, y);
        }
    }
}
GameLayer::~GameLayer(){}

bool GameLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
    
}
void GameLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event){}
bool GameLayer::onTouchEnd(cocos2d::Touch *touch, cocos2d::Event *event){}

