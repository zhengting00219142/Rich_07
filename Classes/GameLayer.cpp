//
//  GameLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#include "GameLayer.h"
#include "PauseLayer.h"
#include "OverLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameLayer::createScene(int fund)
{
    auto scene = Scene::create();
    
    auto bgLayer = Layer::create();
    auto bgNode = CSLoader::createNode("BgLayer.csb");
    bgLayer->addChild(bgNode);
    scene->addChild(bgLayer, 1);
    
    auto toolsLayer = Layer::create();
    auto toolNode = CSLoader::createNode("ToolsLayer.csb");
    toolsLayer->addChild(toolNode);
    scene->addChild(toolsLayer, 3);
    
    auto layer = GameLayer::create(fund);
    layer->pauseBtn = static_cast<Sprite*>( toolNode->getChildByTag(19) );
    layer->diceBtn = static_cast<Sprite*>( toolNode->getChildByTag(12) );
    layer->avatarBtn = static_cast<Sprite*>( toolNode->getChildByTag(10) );
    scene->addChild(layer, 2);
    
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
    eventDispatcher->addEventListenerWithFixedPriority(touchlistener, 1);
}
void GameLayer::initLandSprite(LandSprite *land, int streetVal, Position p) {
    land->setUp(streetVal, p);
    this->LandSprites.insertBefore(0, land);
    this->addChild(land, 3);
}

void GameLayer::initMap() {
    // land type[]
    int lt[MAP_COL];
    for(int i = 0; i < MAP_COL; i++) {
        lt[i] = LTYPE_UNOCCUPIED;
    }
    lt[14]=LTYPE_HOSPITAL; lt[MAP_COL-1]=LTYPE_SHOP;
    LandSprite *land = LandSprite::create();
    initLandSprite(land, 0, Position(0, MAP_ROW-1));
    for(int i = 1, y = MAP_ROW-1; i < MAP_COL; i++) {
        LandSprite *land = LandSprite::create(lt[i]);
        initLandSprite(land, 200, Position(i, y));
    }
    
    for(int x = MAP_COL-1, j = MAP_ROW-2; j > 0; j--) {
        LandSprite *land = LandSprite::create(LTYPE_UNOCCUPIED);
        initLandSprite(land, 500, Position(x, j));
    }
    
    for(int i = 0; i < MAP_COL; i++) {
        lt[i] = LTYPE_UNOCCUPIED;
    }
    lt[0] = LTYPE_MAGIC; lt[14]=LTYPE_PRISON; lt[MAP_COL-1]=LTYPE_GIFT;
    for(int i = MAP_COL-1, y = 0; i > -1; i--) {
        LandSprite *land = LandSprite::create(lt[i]);
        initLandSprite(land, 300, Position(i, y));
    }
    
    int ld[MAP_ROW] = {0, 20, 80, 100, 40, 80, 60, 0};
    for(int x = 0, j = 1; j < MAP_ROW-1; j++) {
        LandSprite *land = LandSprite::create(LTYPE_MINE);
        land->data = ld[j];
        initLandSprite(land, 0, Position(x, j));
    }
}

GameLayer::GameLayer()
{
    initTouchListener();
    initMap();
}
GameLayer::~GameLayer(){}

DoubleDList<LandSprite *>::DDListIte<LandSprite *> GameLayer::locateLand(Position p) {
    DoubleDList<LandSprite *>::DDListIte<LandSprite *> iter = LandSprites.headIte();
    while(iter.hasNextForUp()) {
        if(p.isEqual(iter.getCurrent()->p))
            return iter;
        iter.moveFront();
    }
    return NULL;
}

void GameLayer::move(int step) {
    // issue: after all the construction... landSprites seems to change into a big list of NULL...
    DoubleDList<LandSprite *>::DDListIte<LandSprite *> cIter = locateLand(playerSprites[turn]->p);
    for(int i = 0; i < step; i++) {
        cIter.moveFront();
        playerSprites[turn]->runAction(MoveTo::create(1/6.0, cIter.getCurrent()->p.toRealPos()));
    }
}

void GameLayer::changePOV(Position p) {
    // TODO
}
// touch methods, help create a moveable map
bool GameLayer::touchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
    Point touchLoc = touch->getLocation();
    Rect pauseBtnRec = pauseBtn->getBoundingBox();
    if(pauseBtnRec.containsPoint(touchLoc)) {
        CCDirector::getInstance()->pushScene(PauseLayer::createScene());
        return true;
    }
    Rect diceBtnRec = diceBtn->getBoundingBox();
    if(diceBtnRec.containsPoint(touchLoc)) {
        move(rollDice());
        // roll dice...
    }
    Rect avatarBtnRec = avatarBtn->getBoundingBox();
    if(avatarBtnRec.containsPoint(touchLoc)) {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        CCDirector::getInstance()->replaceScene(OverLayer::createScene());
        return true;
    }
    prvTouchLoc = touchLoc;
    return true;
}
// TODO: make compatible with changePOV
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

