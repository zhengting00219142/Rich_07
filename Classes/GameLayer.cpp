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
        PlayerSprite *player = PlayerSprite::create(pnum[i], fund);
        player->p = Position(0, MAP_ROW-1);
        ret->playerSprites.push_back(player);
        player->setPosition(player->p.toRealPos());
        ret->addChild(player, (int)pnum.size()-i+4);
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

void GameLayer::initTouchListener() {
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto touchlistener = EventListenerTouchOneByOne::create();
    touchlistener->setSwallowTouches(true);
    touchlistener->onTouchBegan = CC_CALLBACK_2(GameLayer::touchBegan, this);
    touchlistener->onTouchMoved = CC_CALLBACK_2(GameLayer::touchMoved, this);
    touchlistener->onTouchEnded = CC_CALLBACK_2(GameLayer::touchEnded, this);
    eventDispatcher->addEventListenerWithFixedPriority(touchlistener, 2);
}
void GameLayer::initMap() {
    // land type[]
    int lt[MAP_COL];
    for(int i = 0; i < MAP_COL; i++) {
        lt[i] = LTYPE_UNOCCUPIED;
    }
    lt[14]=LTYPE_HOSPITAL; lt[MAP_COL-1]=LTYPE_SHOP;
    
    LandSprite *land = LandSprite::create();
    land->setUp(0, 0, MAP_ROW-1);
    this->addChild(land, 3);
    
    for(int i = 1, y = MAP_ROW-1; i < MAP_COL; i++) {
        LandSprite *land = LandSprite::create(lt[i]);
        land->setUp(200, i, y);
        this->addChild(land, 3);
    }
    
    for(int i = 0; i < MAP_COL; i++) {
        lt[i] = LTYPE_UNOCCUPIED;
    }
    lt[0] = LTYPE_MAGIC; lt[14]=LTYPE_PRISON; lt[MAP_COL-1]=LTYPE_GIFT;
    for(int i = 0, y = 0; i < MAP_COL; i++) {
        LandSprite *land = LandSprite::create(lt[i]);
        land->setUp(300, i, y);
        this->addChild(land, 3);
    }
    for(int j = 1, x = MAP_COL-1; j < MAP_ROW-1; j++) {
        LandSprite *land = LandSprite::create(LTYPE_UNOCCUPIED);
        land->setUp(500, x, j);
        this->addChild(land, 3);
    }
    int ld[MAP_ROW] = {0, 20, 80, 100, 40, 80, 60, 0};
    for(int j = 1, x = 0; j < MAP_ROW-1; j++) {
        LandSprite *land = LandSprite::create(LTYPE_MINE);
        land->setUp(0, x, j);
        land->data = ld[j];
        this->addChild(land, 3);
    }

}

GameLayer::GameLayer()
{
    initTouchListener();
    initMap();
}
GameLayer::~GameLayer(){}

// touch methods, help create a moveable map
bool GameLayer::touchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
    Point touchLoc = touch->getLocation();
    prvTouchLoc = touchLoc;
    return true;
}
void GameLayer::touchMoved(cocos2d::Touch *touch, cocos2d::Event *event){
    Point touchLoc = touch->getLocation();
    Vec2 difference(touchLoc.x - prvTouchLoc.x, touchLoc.y - prvTouchLoc.y);
    Vec2 currentPos = this->getPosition();
    if(currentPos.x + difference.x > 0 || currentPos.x + difference.x < winSiz.width - mapWidth)
        difference.x = 0;
    if(currentPos.y + difference.y < 0 || currentPos.y + difference.y > mapHeight - winSiz.height)
        difference.y = 0;
    this->setPosition(currentPos + difference);
    prvTouchLoc = touchLoc;
}
void GameLayer::touchEnded(cocos2d::Touch *touch, cocos2d::Event *event){
    Point touchLoc = touch->getLocation();
    log("x: %f, y: %f", touchLoc.x, touchLoc.y);
}

