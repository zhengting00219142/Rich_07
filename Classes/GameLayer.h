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
    
    void initMap();                                                     // 初始化地图, 内含地图数据
    void initLandSprite(LandSprite *land, int streetVal, Position p);   // 地图初始化的帮助方法
    void changePOV(Position p);                                         // 更换视角
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Game Logic
    
    void transfer(int src, int dst, int amout);     // 交易, 对应规则: 交房租
    void brokeProcedure(int who);                   // 破产程序, 对应规则: 破产
    void move(int step);                            // 移动step步, 对应规则: 移动
        void moveAnimCallback();                    // 移动动画监听
    
    bool checkOut();                                // 刚轮到某玩家, 检查其状态
    void checkIn();                                 // 玩家掷完骰子, 移动结束, 查看当前位置的土地
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Game Logic Helper Methods
    
    int getTurnWithWho(int who);                                                // 根据玩家代号, 查询轮流顺序
    DoubleDList<LandSprite *>::DDListIte<LandSprite *> locateLand(Position p);  // 获得位置p上的土地
    void nextTurn();                                                            // 下一轮
    void updateToolsLayer();                                                    // 更新显示界面: 现金, 道具...
    void notifyPlayer(string info);                                             // 告知玩家
    void askPlayer(string info);                                                // 询问玩家
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Scene Change
    
    void goShop();
    void goPause();
    void gameOver(int lastLoser);
        void shopCallBack(cocos2d::Ref *pSender);
        void defaultCallBack(cocos2d::Ref *pSender);
};

#endif /* defined(__Richer__GameLayer__) */
