//
//  ToolsLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/3/15.
//
//

#include "ToolsLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

ToolsLayer *ToolsLayer::create()
{
    ToolsLayer *ret = new (std::nothrow) ToolsLayer();
    
    auto rootNode = CSLoader::createNode("ToolsLayer.csb");
    ret->addChild(rootNode);
    
    ret->pauseBtn = static_cast<Sprite*>( rootNode->getChildByTag(19) );
    ret->diceBtn = static_cast<Sprite*>( rootNode->getChildByTag(12) );
    ret->avatarBtn = static_cast<Sprite*>( rootNode->getChildByTag(10) );
//    Button* pauseBtn = dynamic_cast<Button*>(rootNode->getChildByName("setting"));
//    pauseBtn->addTouchEventListener(CC_CALLBACK_2(ToolsLayer::pauseCallback, ret));
//    // tmp
//    Button* overBtn = dynamic_cast<Button*>(rootNode->getChildByName("richer3_1"));
//    overBtn->addTouchEventListener(CC_CALLBACK_2(ToolsLayer::overCallback, ret));
    
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

ToolsLayer::ToolsLayer(){
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto touchlistener = EventListenerTouchOneByOne::create();
    touchlistener->setSwallowTouches(true);
    touchlistener->onTouchBegan = CC_CALLBACK_2(ToolsLayer::onTouchBegan, this);
    eventDispatcher->addEventListenerWithFixedPriority(touchlistener, 1);
}
ToolsLayer::~ToolsLayer(){
}

bool ToolsLayer::onTouchBegan(Touch* touch, Event* event)
{
    Point touchLoc = touch->getLocation();
    Rect pauseBtnRec = pauseBtn->getBoundingBox();
    if(pauseBtnRec.containsPoint(touchLoc)) {
        CCDirector::getInstance()->pushScene(PauseLayer::createScene());
    }
    Rect diceBtnRec = diceBtn->getBoundingBox();
    if(diceBtnRec.containsPoint(touchLoc)) {
        // roll dice...
    }
    Rect avatarBtnRec = avatarBtn->getBoundingBox();
    if(avatarBtnRec.containsPoint(touchLoc)) {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        CCDirector::getInstance()->replaceScene(OverLayer::createScene());
    }
    return true;
}

//void ToolsLayer::pauseCallback(Ref* sender, Widget::TouchEventType type)
//{
//    if (type == Widget::TouchEventType::ENDED)
//    {
//        CCDirector::getInstance()->pushScene(PauseLayer::createScene());
//    }
//}
//void ToolsLayer::overCallback(Ref* sender, Widget::TouchEventType type)
//{
//    if (type == Widget::TouchEventType::ENDED)
//    {
//        CCDirector::getInstance()->replaceScene(OverLayer::createScene());
//    }
//}