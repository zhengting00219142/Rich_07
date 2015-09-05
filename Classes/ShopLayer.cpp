//
//  ShopLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/5/15.
//
//

#include "ShopLayer.h"
#include <sstream>

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

ShopLayer *ShopLayer::create(int hold)
{
    ShopLayer *ret = new (std::nothrow) ShopLayer();
    ret->hold = hold;
    
    auto bgLayer = Layer::create();
    auto bgNode = CSLoader::createNode("BgLayer.csb");
    bgLayer->addChild(bgNode);
    ret->addChild(bgLayer, 9);
    
    auto rootNode = CSLoader::createNode("ShopLayer.csb");
    ret->addChild(rootNode, 10);
    
    ret->blockTF = dynamic_cast<TextField*>(rootNode->getChildByName("block_txt"));
    ret->bombTF = dynamic_cast<TextField*>(rootNode->getChildByName("bomb_txt"));
    ret->robotTF = dynamic_cast<TextField*>(rootNode->getChildByName("robot_txt"));
    ret->totalTicket = dynamic_cast<Text*>(rootNode->getChildByName("ticket"));
    

    ret->blockTF->addEventListenerTextField(ret, textfieldeventselector(ShopLayer::blockTFEvent));
    ret->bombTF->addEventListenerTextField(ret, textfieldeventselector(ShopLayer::bombTFEvent));
    ret->robotTF->addEventListenerTextField(ret, textfieldeventselector(ShopLayer::robotTFEvent));
    
    Button* yesBtn = dynamic_cast<Button*>(rootNode->getChildByName("makeSure"));
    yesBtn->addTouchEventListener(CC_CALLBACK_2(ShopLayer::yesCallback, ret));
    Button* noBtn = dynamic_cast<Button*>(rootNode->getChildByName("cancel"));
    noBtn->addTouchEventListener(CC_CALLBACK_2(ShopLayer::noCallback, ret));
    
    if (ret && ret->init())
    {
        ret->updateTicket();
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

ShopLayer::ShopLayer(){}
ShopLayer::~ShopLayer(){}

void ShopLayer::updateAdd() {
    add[0] = string2Int(blockTF->getString());
    add[1] = string2Int(bombTF->getString());
    add[2] = string2Int(robotTF->getString());
}
void ShopLayer::updateTicket() {
    std::stringstream stream;
    std::string totalStr;
    /*
    stream << blockTF->getString();
    stream >> tmp; stream.str("");
    total += (tmp*50);
    stream << bombTF->getString();
    stream >> tmp; stream.str("");
    total += (tmp*50);
    stream << robotTF->getString();
    stream >> tmp; stream.str("");
    total += (tmp*30);*/
    updateAdd();
    total = 0;
    total += (add[0] * 50);
    total += (add[1] * 50);
    total += (add[2] * 30);
    
    stream << total;
    stream >> totalStr;
    totalTicket->setString(totalStr);
}

void ShopLayer::blockTFEvent(cocos2d::Ref *pSender, cocos2d::ui::TextFiledEventType type) {
    switch (type)
    {
        case TextFiledEventType::TEXTFIELD_EVENT_ATTACH_WITH_IME:break;
        case TextFiledEventType::TEXTFIELD_EVENT_INSERT_TEXT:
            // TODO: only accept input when they are digits
            break;
        case TextFiledEventType::TEXTFIELD_EVENT_DETACH_WITH_IME:
            updateTicket();
            break;
        case TextFiledEventType::TEXTFIELD_EVENT_DELETE_BACKWARD:break;
        default:break;
    }
}
void ShopLayer::bombTFEvent(cocos2d::Ref *pSender, cocos2d::ui::TextFiledEventType type) {
    switch (type)
    {
        case TextFiledEventType::TEXTFIELD_EVENT_ATTACH_WITH_IME:
            updateTicket();
            break;
        case TextFiledEventType::TEXTFIELD_EVENT_INSERT_TEXT:break;
        case TextFiledEventType::TEXTFIELD_EVENT_DETACH_WITH_IME:
            updateTicket();
            break;
        case TextFiledEventType::TEXTFIELD_EVENT_DELETE_BACKWARD:break;
        default:break;
    }
}
void ShopLayer::robotTFEvent(cocos2d::Ref *pSender, cocos2d::ui::TextFiledEventType type) {
    switch (type)
    {
        case TextFiledEventType::TEXTFIELD_EVENT_ATTACH_WITH_IME:break;
        case TextFiledEventType::TEXTFIELD_EVENT_INSERT_TEXT:break;
        case TextFiledEventType::TEXTFIELD_EVENT_DETACH_WITH_IME:
            updateTicket();
            break;
        case TextFiledEventType::TEXTFIELD_EVENT_DELETE_BACKWARD:break;
        default:break;
    }
}
void ShopLayer::yesCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        updateTicket();
        if(total > hold) return;
        else {
            //NotificationCenter::getInstance()->postNotification("answer_yes");
            //Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
        }
    }
}
void ShopLayer::noCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        this->removeFromParent();
        return;
    }
}