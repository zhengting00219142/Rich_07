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

Scene* GameLayer::createScene(int pnum[4], int fund)
{
    auto scene = Scene::create();
    auto layer = GameLayer::create(pnum, fund);
    scene->addChild(layer, 3);
    
//    auto bg = ColorLayer::create();
//    scene->cocos2d::Node::addChild(bg, 1);
    
    return scene;
}

GameLayer *GameLayer::create(int pnum[4], int fund)
{
    GameLayer *ret = new (std::nothrow) GameLayer();
    
    // init players
    for(int i = 0; i < 4 || pnum[i] != -1; i++) {
        ret->playerSprites.pushBack(PlayerSprite::create(int2Avatar(pnum[i]), fund));
    }
    
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
    for(int i = 0; i < MAP_COL; i++) {
        
    }
}
GameLayer::~GameLayer(){}

void GameLayer::update(float dt)
{
    
}
