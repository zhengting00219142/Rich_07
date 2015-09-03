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
    
    Button* pauseBtn = dynamic_cast<Button*>(rootNode->getChildByName("setting"));
    pauseBtn->addTouchEventListener(CC_CALLBACK_2(ToolsLayer::pauseCallback, ret));
    // tmp
    Button* overBtn = dynamic_cast<Button*>(rootNode->getChildByName("richer3_1"));
    overBtn->addTouchEventListener(CC_CALLBACK_2(ToolsLayer::overCallback, ret));
    
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

ToolsLayer::ToolsLayer(){}
ToolsLayer::~ToolsLayer(){}

void ToolsLayer::pauseCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        CCDirector::getInstance()->pushScene(PauseLayer::createScene());
    }
}
void ToolsLayer::overCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        CCDirector::getInstance()->replaceScene(OverLayer::createScene());
    }
}