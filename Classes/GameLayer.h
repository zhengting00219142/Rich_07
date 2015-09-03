//
//  GameLayer.h
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#ifndef __Richer__GameLayer__
#define __Richer__GameLayer__

#include "Richer.h"
#include "ToolsLayer.h"
#include "PlayerSprite.h"
#include "LandSprite.h"

class GameLayer : public cocos2d::Layer
{
    float mapHeight, mapWidth;
    
    std::vector<PlayerSprite *> playerSprites;
    
    
public:
    static cocos2d::Scene* createScene(int fund = 10000);
    static GameLayer *create(int fund = 10000);
    GameLayer();
    ~GameLayer();
    
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    bool onTouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif /* defined(__Richer__GameLayer__) */
