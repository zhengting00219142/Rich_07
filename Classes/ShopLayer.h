//
//  ShopLayer.h
//  Richer
//
//  Created by Macbook Air on 9/5/15.
//
//

#ifndef __Richer__ShopLayer__
#define __Richer__ShopLayer__

#include "Richer.h"

class ShopLayer : public cocos2d::Layer
{
    int hold;
    int total;
    cocos2d::ui::Text *totalTicket;
    cocos2d::ui::TextField *blockTF;
    cocos2d::ui::TextField *bombTF;
    cocos2d::ui::TextField *robotTF;
public:
    static cocos2d::Scene* createScene(int hold);
    static ShopLayer *create(int hold);
    ShopLayer();
    ~ShopLayer();
    
    void updateAdd();
    void updateTicket();
    void blockTFEvent(cocos2d::Ref *pSender, cocos2d::ui::TextFiledEventType tfEventType);
    void bombTFEvent(cocos2d::Ref *pSender, cocos2d::ui::TextFiledEventType tfEventType);
    void robotTFEvent(cocos2d::Ref *pSender, cocos2d::ui::TextFiledEventType tfEventType);
    void yesCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    void noCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* defined(__Richer__ShopLayer__) */
