//
//  OverLayer.h
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#ifndef __Richer__OverLayer__
#define __Richer__OverLayer__

#include "Richer.h"

class OverLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    static OverLayer *create();
    OverLayer();
    ~OverLayer();
    
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif /* defined(__Richer__OverLayer__) */
