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
    
    auto toolsLayer = ToolsLayer::create();
    scene->addChild(toolsLayer, 2);
//    auto bg = ColorLayer::create();
//    scene->cocos2d::Node::addChild(bg, 1);
    
    return scene;
}

GameLayer *GameLayer::create(int pnum[4], int fund)
{
    GameLayer *ret = new (std::nothrow) GameLayer();
    
    // init players
    for(int i = 0; i < 4; i++) {
        if(pnum[i] == -1) break;
        PlayerSprite *player = PlayerSprite::create(int2Avatar(pnum[i]), fund);
//        player->p = Position(<#int x#>, <#int y#>);
        ret->playerSprites.pushBack(player);
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
