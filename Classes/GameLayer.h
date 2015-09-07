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
#include <sstream>
#include "DoubleDList.h"
#include "PlayerSprite.h"
#include "LandSprite.h"

// missing function:
// selling properties
// check road for block or bomb
// use of block or bomb or robot

class GameLayer : public cocos2d::Layer
{
    std::vector<PlayerSprite *> playerSprites;
    DoubleDList<LandSprite *> landSprites;

//    Label* tmpLabel;

    Sprite *pauseBtn;
    Sprite *avatarBtn;
    Sprite *diceBtn;
    cocos2d::ui::Button *blockBtn;
    cocos2d::ui::Button *bombBtn;
    cocos2d::ui::Button *robotBtn;
        /////////////////////////////////////////////////////////////////////////////////////////////////////
        // Use of Game Item
        void blockBtnListener(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
        void bombBtnListener(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
        void robotBtnListener(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    
    cocos2d::ui::Text *dayTxt;
    cocos2d::ui::Text *cashTxt;
    cocos2d::ui::Text *ticketTxt;
    cocos2d::ui::Text *blockTxt;
    cocos2d::ui::Text *bombTxt;
    cocos2d::ui::Text *robotTxt;
    cocos2d::Layer *notice;
    cocos2d::Layer *ask;
        void yesBtnListener(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
        void noBtnListener(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    
        int tag;
        int TAG_PURCHASE = 0;
        int TAG_LEVELUP = 1;

    Point prvTouchLoc;
    ostringstream stringHelper;
    bool isMoving;
    int isPlantingWhat;
public:
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Initalization
    
    static cocos2d::Scene* createScene(int fund = 10000);               // default fund: 10,000
    static GameLayer *create(int fund = 10000);
    GameLayer();
    ~GameLayer();
    void initWidget(cocos2d::Node *toolNode);
    void initEventListener();
        /////////////////////////////////////////////////////////////////////////////////////////////////////
        // Touch Methods
        bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
        void touchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
        void touchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    void addObserv();
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Game Map
    
    void initMap();
    void initLandSprite(LandSprite *land, int streetVal, Position p);
    void changePOV(Position p);
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Game Logic
    
    void transfer(int src, int dst, int amout);
    void brokeProcedure(int who);
    void move(int step);
        void moveAnimCallback();
    bool checkOut();
    void checkIn();
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Game Logic Helper Methods
    
    int getTurnWithWho(int who);
    DoubleDList<LandSprite *>::DDListIte<LandSprite *> locateLand(Position p);
    void nextTurn();
    void updateToolsLayer();
    void notifyPlayer(string info);
    void askPlayer(string info);
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Scene Change
    
    void goShop();
    void goPause();
    void gameOver(int lastLoser);
        void shopCallBack(cocos2d::Ref *pSender);
        void defaultCallBack(cocos2d::Ref *pSender);
};

#endif /* defined(__Richer__GameLayer__) */
