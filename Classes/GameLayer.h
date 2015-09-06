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
    DoubleDList<LandSprite *> landSprites;

//    Label* tmpLabel;
    
    Sprite *pauseBtn;
    Sprite *avatarBtn;
    Sprite *diceBtn;
    cocos2d::ui::Button *blockBtn;
    cocos2d::ui::Button *bombBtn;
    cocos2d::ui::Button *robotBtn;
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
    
    Point prvTouchLoc;
    bool isMoving;
public:
    static cocos2d::Scene* createScene(int fund = 10000);
    static GameLayer *create(int fund = 10000);
    GameLayer();
    ~GameLayer();
    void initWidget(cocos2d::Node *toolNode);
    void initEventListener();
    void addObserv();
    void initLandSprite(LandSprite *land, int streetVal, Position p);
    void initMap();
    bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void touchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void touchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    void gameOver(int lastLoser);
    int getTurnWithWho(int who);
    DoubleDList<LandSprite *>::DDListIte<LandSprite *> locateLand(Position p);
    void brokeProcedure(int who);
    void transfer(int src, int dst, int amout);
    void purchase();
    void purchase_levelup();
    void move(int step);
    void moveAnimCallback();
    void updateToolsLayer();
    void nextTurn();
    bool checkOut();
    void checkIn();
    
    void changePOV(Position p);
    void notifyPlayer(string info);
    void askPlayer(string info);
    int tag;
    int TAG_PURCHASE = 0;
    int TAG_LEVELUP = 1;
    
    void goShop();
    void goPause();
    void shopCallBack(cocos2d::Ref *pSender);
    void defaultCallBack(cocos2d::Ref *pSender);
};

#endif /* defined(__Richer__GameLayer__) */
