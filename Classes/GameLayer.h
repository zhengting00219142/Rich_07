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
#include "DoubleDList.h"
#include "PlayerSprite.h"
#include "LandSprite.h"

class GameLayer : public cocos2d::Layer
{
    std::vector<PlayerSprite *> playerSprites;
    DoubleDList<LandSprite *> LandSprites;

    Sprite *pauseBtn;
    Sprite *avatarBtn;
    Sprite *diceBtn;
    Point prvTouchLoc;
public:
    static cocos2d::Scene* createScene(int fund = 10000);
    static GameLayer *create(int fund = 10000);
    GameLayer();
    ~GameLayer();
    void initTouchListener();
    void initLandSprite(LandSprite *land, int streetVal, Position p);
    void initMap();
    bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void touchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void touchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    DoubleDList<LandSprite *>::DDListIte<LandSprite *> locateLand(Position p);
    void move(int step);
    void changePOV(Position p);
};

#endif /* defined(__Richer__GameLayer__) */
