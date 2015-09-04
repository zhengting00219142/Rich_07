//
//  AboutLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/4/15.
//
//

#include "AboutLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

Scene* AboutLayer::createScene()
{
    initWinSiz();
    auto scene = Scene::create();
    auto layer = AboutLayer::create();
    scene->addChild(layer, 3);
    return scene;
}

AboutLayer *AboutLayer::create()
{
    AboutLayer *ret = new (std::nothrow) AboutLayer();
    
    auto rootNode = CSLoader::createNode("AboutScene.csb");
    ret->addChild(rootNode);
    
    Button* backBtn = dynamic_cast<Button*>(rootNode->getChildByName("back"));
    backBtn->addTouchEventListener(CC_CALLBACK_2(AboutLayer::backCallback, ret));
    
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

AboutLayer::AboutLayer(){}
AboutLayer::~AboutLayer(){
}

void AboutLayer::backCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        CCDirector::getInstance()->replaceScene(StartLayer::createScene());
    }
}