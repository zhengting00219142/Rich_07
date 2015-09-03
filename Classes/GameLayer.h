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
    std::vector<PlayerSprite *> playerSprites;

    Point prvTouchLoc;
public:
    
    static cocos2d::Scene* createScene(int fund = 10000);
    static GameLayer *create(int fund = 10000);
    GameLayer();
    ~GameLayer();
    
    bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void touchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void touchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif /* defined(__Richer__GameLayer__) */
