//
//  OverLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#include "OverLayer.h"
#include "StartLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* OverLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = OverLayer::create();
    scene->addChild(layer, 3);
    return scene;
}

OverLayer *OverLayer::create()
{
    OverLayer *ret = new (std::nothrow) OverLayer();
    
    auto rootNode = CSLoader::createNode("GameOverLayer.csb");
    ret->addChild(rootNode);

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

OverLayer::OverLayer(){
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto touchlistener = EventListenerTouchOneByOne::create();
    touchlistener->setSwallowTouches(true);
    touchlistener->onTouchBegan = CC_CALLBACK_2(OverLayer::onTouchBegan, this);
    eventDispatcher->addEventListenerWithFixedPriority(touchlistener, 1);
}
OverLayer::~OverLayer(){}

bool OverLayer::onTouchBegan(Touch* touch, Event* event)
{
    Point touchLoc = touch->getLocation();
    if(Rect(0, 0, winSiz.width, winSiz.height).containsPoint(touchLoc)) {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        CCDirector::getInstance()->replaceScene(StartLayer::createScene());
    }
    return true;
}