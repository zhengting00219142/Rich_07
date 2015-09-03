//
//  InitLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#include "InitLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

Scene* InitLayer::createScene()
{
    initWinSiz();
    auto scene = Scene::create();
    auto layer = InitLayer::create();
    scene->addChild(layer, 3);
    return scene;
}

InitLayer *InitLayer::create()
{
    InitLayer *ret = new (std::nothrow) InitLayer();
    
    auto rootNode = CSLoader::createNode("SetScene.csb");
    ret->addChild(rootNode);
    
    Button* playBtn = dynamic_cast<Button*>(rootNode->getChildByName("next"));
    playBtn->addTouchEventListener(CC_CALLBACK_2(InitLayer::playCallback, ret));
    Button* backBtn = dynamic_cast<Button*>(rootNode->getChildByName("back"));
    backBtn->addTouchEventListener(CC_CALLBACK_2(InitLayer::backCallback, ret));
    
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

InitLayer::InitLayer(){}
InitLayer::~InitLayer(){
}

void InitLayer::playCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//        pnum.pushBack(2);pnum.pushBack(1);pnum.pushBack(4);
        CCDirector::getInstance()->replaceScene(GameLayer::createScene());
    }
}
void InitLayer::backCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        CCDirector::getInstance()->replaceScene(StartLayer::createScene());
    }
}