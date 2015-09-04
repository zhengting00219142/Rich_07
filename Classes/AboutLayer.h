//
//  AboutLayer.h
//  Richer
//
//  Created by Macbook Air on 9/4/15.
//
//

#ifndef __Richer__AboutLayer__
#define __Richer__AboutLayer__

#include "Richer.h"
#include "StartLayer.h"

class AboutLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    static AboutLayer *create();
    AboutLayer();
    ~AboutLayer();

    void backCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* defined(__Richer__AboutLayer__) */
