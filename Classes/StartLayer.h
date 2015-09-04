//
//  StartLayer.h
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#ifndef __Richer__StartLayer__
#define __Richer__StartLayer__

#include "Richer.h"
#include "InitLayer.h"
#include "AboutLayer.h"

class StartLayer : public cocos2d::Layer
{
//    Button *
public:
    static cocos2d::Scene* createScene();
    static StartLayer *create();
    StartLayer();
    ~StartLayer();
    
    void startCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    void aboutCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* defined(__Richer__StartLayer__) */
