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
    scene->addChild(layer, 2);
    
    auto toolsLayer = ToolsLayer::create();
    scene->addChild(toolsLayer, 3);
//    auto bg = ColorLayer::create();
//    scene->cocos2d::Node::addChild(bg, 1);
    
    return scene;
}

GameLayer *GameLayer::create(int fund)
{
    GameLayer *ret = new (std::nothrow) GameLayer();
    
    // init players
    for(int i = 0; i < pnum.size(); i++) {
        PlayerSprite *player = PlayerSprite::create(int2Avatar(pnum[i]), fund);
        player->p = Position(0, MAP_ROW-1);
        ret->playerSprites.push_back(player);
        player->setPosition(player->p.toRealPos());
        ret->addChild(player, (int)pnum.size()-i);
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
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto touchlistener = EventListenerTouchOneByOne::create();
    touchlistener->setSwallowTouches(true);
    touchlistener->onTouchBegan = CC_CALLBACK_2(GameLayer::touchBegan, this);
    touchlistener->onTouchMoved = CC_CALLBACK_2(GameLayer::touchMoved, this);
    touchlistener->onTouchEnded = CC_CALLBACK_2(GameLayer::touchEnded, this);
    eventDispatcher->addEventListenerWithFixedPriority(touchlistener, 2);
    
    // init lands
    for(int i = 0, y = MAP_ROW-1; i < MAP_COL; i++) {
        LandSprite *land = NULL;
        if(i == 0) {
            land = LandSprite::create();
            land->setUp(LTYPE_NOTHING, 0, i, y);
        }
        else if(i == 14) {
            land = LandSprite::create("bomb.png");
            land->setUp(LTYPE_HOSPITAL, 0, i, y);
        }
        else if(i == MAP_COL-1) {
            land = LandSprite::create("bomb.png");
            land->setUp(LTYPE_SHOP, 0, i, y);
        }
        else {
            land = LandSprite::create("bomb.png");
            land->setUp(LTYPE_UNOCCUPIED, 200, i, y);
        }
        land->setPosition(land->p.toRealPos());
        this->addChild(land, 7);
    }
    for(int i = 0, y = 0; i < MAP_COL; i++) {
        LandSprite *land = NULL;
        if(i == 0) {
            land = LandSprite::create("bomb.png");
            land->setUp(LTYPE_MAGIC, 0, i, y);
        }
        else if(i == 14) {
            land = LandSprite::create("bomb.png");
            land->setUp(LTYPE_PRISON, 0, i, y);
        }
        else if(i == MAP_COL-1) {
            land = LandSprite::create("bomb.png");
            land->setUp(LTYPE_GIFT, 0, i, y);
        }
        else {
            land = LandSprite::create("bomb.png");
            land->setUp(LTYPE_UNOCCUPIED, 300, i, y);
        }
        land->setPosition(land->p.toRealPos());
        this->addChild(land, 7);
    }
    for(int j = 1, x = MAP_COL-1; j < MAP_ROW-1; j++) {
        LandSprite *land = LandSprite::create("bomb.png");
        land->setUp(LTYPE_MINE, 500, x, j);
        land->setPosition(land->p.toRealPos());
        this->addChild(land, 7);
    }
    int data[MAP_ROW] = {0, 20, 80, 100, 40, 80, 60, 0};
    for(int j = 1, x = 0; j < MAP_ROW-1; j++) {
        LandSprite *land = LandSprite::create("bomb.png");
        land->setUp(LTYPE_MINE, data[j], x, j);
        land->setPosition(land->p.toRealPos());
        this->addChild(land, 7);
    }
}
GameLayer::~GameLayer(){}

bool GameLayer::touchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
    Point touchLoc = touch->getLocation();
    log("x: %f, y: %f", touchLoc.x, touchLoc.y);
    prvTouchLoc = touchLoc;
    return true;
}
void GameLayer::touchMoved(cocos2d::Touch *touch, cocos2d::Event *event){
    Point touchLoc = touch->getLocation();
    log("x: %f, y: %f", touchLoc.x, touchLoc.y);
    Vec2 difference(touchLoc.x - prvTouchLoc.x, touchLoc.y - prvTouchLoc.y);
    Vec2 currentPos = this->getPosition();
    log("b***\nc(%f, %f)", currentPos.x, currentPos.y);
    log("d(%f, %f)", difference.x, difference.y);
    log("c+d(%f, %f)", currentPos.x + difference.x, currentPos.y + difference.y);
    if(currentPos.x + difference.x > 0 || currentPos.x + difference.x < winSiz.width - mapWidth)
        difference.x = 0;
    if(currentPos.y + difference.y < 0 || currentPos.y + difference.y > mapHeight - winSiz.height)
        difference.y = 0;
    log("e***\nc(%f, %f)", currentPos.x, currentPos.y);
    log("d(%f, %f)", difference.x, difference.y);
    log("c+d(%f, %f)", currentPos.x + difference.x, currentPos.y + difference.y);
    this->setPosition(currentPos + difference);
//    this->runAction(MoveBy::create(1/60.0, difference));
    prvTouchLoc = touchLoc;
}
void GameLayer::touchEnded(cocos2d::Touch *touch, cocos2d::Event *event){
    Point touchLoc = touch->getLocation();
    log("x: %f, y: %f", touchLoc.x, touchLoc.y);
}

