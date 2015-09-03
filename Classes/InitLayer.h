//
//  InitLayer.h
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#ifndef __Richer__InitLayer__
#define __Richer__InitLayer__

#include "Richer.h"
#include "StartLayer.h"
#include "GameLayer.h"

class InitLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    static InitLayer *create();
    InitLayer();
    ~InitLayer();
    
    void playCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    void backCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* defined(__Richer__InitLayer__) */
