//
//  QuestionLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/6/15.
//
//

#include "QuestionLayer.h"

USING_NS_CC;

using namespace cocos2d::ui;

QuestionLayer *QuestionLayer::create(std::string sign, std::string info)
{
    QuestionLayer *ret = new (std::nothrow) QuestionLayer();
    
    ret->signiture = sign;
    ret->info = info;
//    Button* startBtn = dynamic_cast<Button*>(rootNode->getChildByName("begin"));
//    startBtn->addTouchEventListener(CC_CALLBACK_2(QuestionLayer::yesCallback, ret));
//    Button* aboutBtn = dynamic_cast<Button*>(rootNode->getChildByName("about"));
//    aboutBtn->addTouchEventListener(CC_CALLBACK_2(QuestionLayer::noCallback, ret));
    
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
QuestionLayer::QuestionLayer(){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = Label::createWithTTF(info, "fonts/Marker Felt.ttf", 40);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    // add the label as a child to this layer
    this->addChild(label, 1);
}
QuestionLayer::~QuestionLayer(){}

void QuestionLayer::yesCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        //CCDirector::getInstance()->replaceScene(InitLayer::createScene());
    }
}
void QuestionLayer::noCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        //CCDirector::getInstance()->replaceScene(AboutLayer::createScene());
    }
}