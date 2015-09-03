//
//  PauseLayer.h
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#ifndef __Richer__PauseLayer__
#define __Richer__PauseLayer__

#include "Richer.h"
#include "StartLayer.h"

class PauseLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    static PauseLayer *create();
    PauseLayer();
    ~PauseLayer();
    
    void backCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    void quitCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* defined(__Richer__PauseLayer__) */
