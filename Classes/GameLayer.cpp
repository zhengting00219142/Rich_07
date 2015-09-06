//
//  GameLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#include <sstream>
#include "GameLayer.h"
#include "ShopLayer.h"
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
    layer->initWidget(toolNode);
    layer->updateToolsLayer();
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

void GameLayer::initWidget(Node *toolNode) {
    this->pauseBtn = static_cast<Sprite*>( toolNode->getChildByTag(19) );
    this->diceBtn = static_cast<Sprite*>( toolNode->getChildByTag(12) );
    this->avatarBtn = static_cast<Sprite*>( toolNode->getChildByTag(10) );
    
    this->blockBtn = dynamic_cast<ui::Button*>(toolNode->getChildByName("block"));
    this->bombBtn = dynamic_cast<ui::Button*>(toolNode->getChildByName("bomb"));
    this->robotBtn = dynamic_cast<ui::Button*>(toolNode->getChildByName("robot"));
    blockBtn->addTouchEventListener(CC_CALLBACK_2(GameLayer::blockBtnListener, this));
    bombBtn->addTouchEventListener(CC_CALLBACK_2(GameLayer::bombBtnListener, this));
    robotBtn->addTouchEventListener(CC_CALLBACK_2(GameLayer::robotBtnListener, this));
    
    this->dayTxt = dynamic_cast<ui::Text*>(toolNode->getChildByName("day"));
    this->cashTxt = dynamic_cast<ui::Text*>(toolNode->getChildByName("money"));
    this->ticketTxt = dynamic_cast<ui::Text*>(toolNode->getChildByName("ticket"));
    this->blockTxt = dynamic_cast<ui::Text*>(toolNode->getChildByName("block_txt"));
    this->bombTxt = dynamic_cast<ui::Text*>(toolNode->getChildByName("bomb_txt"));
    this->robotTxt = dynamic_cast<ui::Text*>(toolNode->getChildByName("robot_txt"));
}
void GameLayer::initEventListener() {
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto touchlistener = EventListenerTouchOneByOne::create();
    touchlistener->setSwallowTouches(true);
    touchlistener->onTouchBegan = CC_CALLBACK_2(GameLayer::touchBegan, this);
    touchlistener->onTouchMoved = CC_CALLBACK_2(GameLayer::touchMoved, this);
    touchlistener->onTouchEnded = CC_CALLBACK_2(GameLayer::touchEnded, this);
    eventDispatcher->addEventListenerWithFixedPriority(touchlistener, 1);
}
void GameLayer::addObserv() {
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GameLayer::shopCallBack), "shopCallback", NULL);
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GameLayer::pauseCallBack), "shopCallback", NULL);
}
void GameLayer::initLandSprite(LandSprite *land, int streetVal, Position p) {
    land->setUp(streetVal, p);
    this->landSprites.pushFromHead(land);
    this->addChild(land, 3);
}

void GameLayer::initMap() {
    // land type[]
    int lt[MAP_COL];
    for(int i = 0; i < MAP_COL; i++) {
        lt[i] = LTYPE_UNOCCUPIED;
    }
    lt[14]=LTYPE_HOSPITAL; lt[MAP_COL-1]=LTYPE_SHOP;
    LandSprite *_land = LandSprite::create();
    initLandSprite(_land, 0, Position(0, MAP_ROW-1));
    for(int i = 1, y = MAP_ROW-1; i < MAP_COL; i++) {
        LandSprite *land = NULL;
        land = LandSprite::create(lt[i]);
        initLandSprite(land, 200, Position(i, y));
    }
    
    for(int x = MAP_COL-1, j = MAP_ROW-2; j > 0; j--) {
        LandSprite *land = NULL;
        land = LandSprite::create(LTYPE_UNOCCUPIED);
        initLandSprite(land, 500, Position(x, j));
    }
    
    for(int i = 0; i < MAP_COL; i++) {
        lt[i] = LTYPE_UNOCCUPIED;
    }
    lt[0] = LTYPE_MAGIC; lt[14]=LTYPE_PRISON; lt[MAP_COL-1]=LTYPE_GIFT;
    for(int i = MAP_COL-1, y = 0; i > -1; i--) {
        LandSprite *land  = NULL;
        land = LandSprite::create(lt[i]);
        initLandSprite(land, 300, Position(i, y));
    }
    
    int ld[MAP_ROW] = {0, 20, 80, 100, 40, 80, 60, 0};
    for(int x = 0, j = 1; j < MAP_ROW-1; j++) {
        LandSprite *land  = NULL;
        land = LandSprite::create(LTYPE_MINE);
        initLandSprite(land, 0, Position(x, j));
        land->data = ld[j];
    }
}

GameLayer::GameLayer()
{
    initEventListener();
    addObserv();
    initMap();
    isMoving = false;
//    tmpLabel = NULL;
}
GameLayer::~GameLayer(){}

int GameLayer::getTurnWithWho(int who) {
    for(int i = 0; i < playerSprites.size(); i++) {
        if(pnum[i] == who)
            return i;
    }
    return 0;
}
void GameLayer::changePOV(Position p) {
    // Relative position to left bottom of the screen, (1, 2)
    this->setPosition(-tileSiz * p.x, tileSiz * (MAP_ROW - 1 - p.y));
}
DoubleDList<LandSprite *>::DDListIte<LandSprite *> GameLayer::locateLand(Position p) {
    DoubleDList<LandSprite *>::DDListIte<LandSprite *> iter = landSprites.headIte();
    LandSprite *tmp = iter.getCurrent();
    if(iter.getCurrent() == NULL) return NULL;
    do{
        if(p.isEqual(iter.getCurrent()->p))
            return iter;
        iter.moveBack();
    } while(iter.getCurrent() != tmp);
    return NULL;
}

void GameLayer::gameOver(int lastLoser) {
    int winner = playerSprites[++turn%2]->who;
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    CCDirector::getInstance()->replaceScene(OverLayer::createScene(winner));
}
void GameLayer::brokeProcedure(int who) {
    if(playerSprites.size() == 2) {
        gameOver(who);
        return;
    }
    notifyPlayer("你破产啦！！！！！房子家产自动消失！！！！！还有人！！！");
    int _turn = getTurnWithWho(who);
    PlayerSprite *player = playerSprites[_turn];
    Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("unoccupied.png");
    for(int i = 0; i < player->properties.size(); i++) {
        LandSprite *land = player->properties[i];
        land->type = LTYPE_UNOCCUPIED;
        land->data = 0;
        land->setTexture(texture);
    }
    int j = 0;
    for(std::vector<PlayerSprite *>::iterator i = playerSprites.begin();
        i != playerSprites.end(); j++) {
        if(j == _turn) {
            (*i)->removeFromParent();
            i = playerSprites.erase(i);
            break;
        }
        i++;
    }
    j = 0;
    for(std::vector<int>::iterator i = pnum.begin();
        i != pnum.end(); j++) {
        if(j == _turn) {
            i = pnum.erase(i);
            break;
        }
        i++;
    }
    updateToolsLayer();
}
void GameLayer::transfer(int src, int dst, int amout) {
    playerSprites[getTurnWithWho(src)]->cash -= amout;
    playerSprites[getTurnWithWho(dst)]->cash += amout;
    if(playerSprites[getTurnWithWho(src)]->cash < 0)
        brokeProcedure(src);
    //updateCash();
}
void GameLayer::purchase() {
    LandSprite *land = locateLand(playerSprites[turn]->p).getCurrent();
    playerSprites[turn]->cash -= land->streetVal;
    playerSprites[turn]->properties.push_back(land);
    land->levelUp(pnum[turn]);
    //updateCash();
}
void GameLayer::move(int step) {
    // issue: after all the construction... landSprites seems to change into a big list of NULL...
    DoubleDList<LandSprite *>::DDListIte<LandSprite *> cIter = locateLand(playerSprites[turn]->p);
    Vector< FiniteTimeAction * > arrayOfActions;
    if(playerSprites[turn]->facing == FACING_CLK) {
        for(int i = 0; i < step; i++) {
            cIter.moveBack();
            arrayOfActions.pushBack(MoveTo::create(1/6.0, cIter.getCurrent()->p.toRealPos()));
        }
    }
    else {
        for(int i = 0; i < step; i++) {
            cIter.moveFront();
            arrayOfActions.pushBack(MoveTo::create(1/6.0, cIter.getCurrent()->p.toRealPos()));
        }
    }
    arrayOfActions.pushBack(CallFunc::create(CC_CALLBACK_0(GameLayer::moveAnimCallback, this)));
    playerSprites[turn]->p = cIter.getCurrent()->p;
    changePOV(cIter.getCurrent()->p);
    isMoving = true;
    playerSprites[turn]->runAction(Sequence::create(arrayOfActions));
}
void GameLayer::moveAnimCallback() {
    isMoving = false;
    checkIn();
    nextTurn();
}
bool GameLayer::checkOut() {
    int status = playerSprites[turn]->status;
    bool ret = true;
    if(status == STATUS_NORM) ret = true;
    if(status / STATUS_MONEYGOD % 10) {
        playerSprites[turn]->status -= STATUS_MONEYGOD;
        ret = true;
    }
    if(status / STATUS_INJURED % 10) {
        playerSprites[turn]->status -= STATUS_INJURED;
        ret = false;
    }
    if(status / STATUS_INPRISON % 10) {
        playerSprites[turn]->status -= STATUS_INPRISON;
        ret = false;
    }
    return ret;
}
void GameLayer::checkIn() {
    ostringstream oss;
    LandSprite *land = locateLand(playerSprites[turn]->p).getCurrent();
    switch(land->type) {
        case LTYPE_UNOCCUPIED:
            if(playerSprites[turn]->cash < land->streetVal)
                return;
            // TODO: ask if buy
            purchase();
            return;
        case LTYPE_SHOP: {
            // not enough ticket
            if(playerSprites[turn]->ticket < ITEM_COST_ROBOT)
                return;
            goShop();
            return;
        }
        case LTYPE_GIFT: return;
        case LTYPE_MAGIC: return;
        case LTYPE_HOSPITAL:
        case LTYPE_PRISON: return;
        case LTYPE_MINE:
            playerSprites[turn]->ticket += land->data;
            oss << "辛苦搬砖一天一夜，获得" << land->data << "点券！";
            notifyPlayer(oss.str());
            log("%s", oss.str().c_str());
            return;
        default:
            // TODO
            if(land->owner != pnum[turn]) {
                int amout = land->data;
                if(playerSprites[turn]->status / STATUS_MONEYGOD % 10)
                    amout/=2;
                transfer(pnum[turn], land->owner, amout);
            }
            else if(land->type == LTYPE_MAXLV) return;
            else {
                if(playerSprites[turn]->cash < land->streetVal)
                    return;
                // TODO: ask if level u
                playerSprites[turn]->cash -= land->streetVal;
                land->levelUp(pnum[turn]);
                //updateCash();
            }
            return;
    }
}
void GameLayer::notifyPlayer(string info) {
    
}
void GameLayer::shopCallBack(Ref *pSender) {
    initEventListener();
    for(int i = 0; i < ITEM_KINDS; i++) {
        playerSprites[turn]->items[i] += add[i];
    }
    updateToolsLayer();
}
void GameLayer::pauseCallBack(Ref *pSender) {
    initEventListener();
}

void GameLayer::updateToolsLayer() {
    Texture2D* texture = Director::getInstance()->getTextureCache()->addImage(pavatar[pnum[turn]]);
    avatarBtn->setTexture(texture);
    ostringstream oss;
    oss << "金钱：" << playerSprites[turn]->cash;
    cashTxt->setString(oss.str());
    oss.str("");
    oss << "点数：" << playerSprites[turn]->ticket;
    ticketTxt->setString(oss.str());
    oss.str("");
    oss << "x" << playerSprites[turn]->items[ITEM_BLOCK];
    blockTxt->setString(oss.str());
    oss.str("");
    oss << "x" << playerSprites[turn]->items[ITEM_BOMB];
    bombTxt->setString(oss.str());
    oss.str("");
    oss << "x" << playerSprites[turn]->items[ITEM_ROBOT];
    robotTxt->setString(oss.str());
}
void GameLayer::nextTurn() {
    if(++turn == pnum.size()) {
        day++;
        ostringstream oss;
        oss << "第" << day << "天";
        dayTxt->setString(oss.str());
        turn = 0;
    }
    updateToolsLayer();
}

void GameLayer::blockBtnListener(cocos2d::Ref *sender, ui::Widget::TouchEventType type) {
    if(playerSprites[turn]->items[ITEM_BLOCK] == 0) return;
    
}
void GameLayer::bombBtnListener(cocos2d::Ref *sender, ui::Widget::TouchEventType type) {
    if(playerSprites[turn]->items[ITEM_BOMB] == 0) return;
}
void GameLayer::robotBtnListener(cocos2d::Ref *sender, ui::Widget::TouchEventType type) {
    if(playerSprites[turn]->items[ITEM_ROBOT] == 0) return;
}

void GameLayer::goShop() {
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    CCDirector::getInstance()->pushScene(ShopLayer::createScene(playerSprites[turn]->ticket));
}
void GameLayer::goPause() {
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    CCDirector::getInstance()->pushScene(PauseLayer::createScene());
}

// touch methods, help create a moveable map
bool GameLayer::touchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
    if(isMoving) return true;
//    if(tmpLabel != NULL) {
//        tmpLabel->removeFromParent();
//        tmpLabel = NULL;
//        return true;
//    }
    Point touchLoc = touch->getLocation();
    Rect pauseBtnRec = pauseBtn->getBoundingBox();
    if(pauseBtnRec.containsPoint(touchLoc)) {
        goPause();
        return true;
    }
    Rect diceBtnRec = diceBtn->getBoundingBox();
    if(diceBtnRec.containsPoint(touchLoc)) {
        // roll dice...
        move(rollDice());
    }
    Rect avatarBtnRec = avatarBtn->getBoundingBox();
    if(avatarBtnRec.containsPoint(touchLoc)) {
        //brokeProcedure(pnum[turn]);
        // for debug sake
        //changePOV(playerSprites[turn]->p);
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        CCDirector::getInstance()->replaceScene(OverLayer::createScene(3));
        return true;
    }
    
//    Vec2 currentPos = this->getPosition();
//    for(int i = 0; i < pnum.size(); i++) {
//        for(int j = 0; j < playerSprites[i]->properties.size(); j++) {
//            LandSprite *land = playerSprites[i]->properties[j];
//            Rect r = land->getBoundingBox();
//            Vec2 rp = land->p.toRealPos();
//            if(Rect(rp.x, rp.y, tileSiz, tileSiz).containsPoint(touchLoc)) {
//                ostringstream oss;
//                oss << "worth: " << land->data;
//                tmpLabel = Label::createWithTTF(oss.str(), "fonts/Marker Felt.ttf", 40);
//                tmpLabel->setPosition(land->p.toRealPosAbove());
//                this->addChild(tmpLabel, 10);
//                return true;
//            }
//        }
//    }
    
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
