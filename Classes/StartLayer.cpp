//
//  StartLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#include "StartLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

Scene* StartLayer::createScene()
{
    initWinSiz();
    auto scene = Scene::create();
    auto layer = StartLayer::create();
    scene->addChild(layer);
    return scene;
}

StartLayer *StartLayer::create()
{
    StartLayer *ret = new (std::nothrow) StartLayer();
    
    auto rootNode = CSLoader::createNode("StartScene.csb");
    ret->addChild(rootNode);
    
    Button* startBtn = dynamic_cast<Button*>(rootNode->getChildByName("begin"));
    startBtn->addTouchEventListener(CC_CALLBACK_2(StartLayer::startCallback, ret));
    
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
void StartLayer::startCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
//        resetGame();
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        CCDirector::getInstance()->replaceScene(InitLayer::createScene());
    }
}
StartLayer::StartLayer(){}
StartLayer::~StartLayer(){}
