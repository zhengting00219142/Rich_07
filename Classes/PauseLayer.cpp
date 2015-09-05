//
//  PauseLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#include "PauseLayer.h"
#include "StartLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

Scene* PauseLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = PauseLayer::create();
    scene->addChild(layer, 3);
    return scene;
}

PauseLayer *PauseLayer::create()
{
    PauseLayer *ret = new (std::nothrow) PauseLayer();
    
    auto rootNode = CSLoader::createNode("PauseLayer.csb");
    ret->addChild(rootNode);
    
    Button* backBtn = dynamic_cast<Button*>(rootNode->getChildByName("Button_2"));
    backBtn->addTouchEventListener(CC_CALLBACK_2(PauseLayer::backCallback, ret));
    Button* quitBtn = dynamic_cast<Button*>(rootNode->getChildByName("quit"));
    quitBtn->addTouchEventListener(CC_CALLBACK_2(PauseLayer::quitCallback, ret));
    
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

PauseLayer::PauseLayer(){}
PauseLayer::~PauseLayer(){}

void PauseLayer::backCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
        CCDirector::getInstance()->popScene();
    }
}
void PauseLayer::quitCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        CCDirector::getInstance()->replaceScene(StartLayer::createScene());
    }
}