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

class StartLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    static StartLayer *create();
    StartLayer();
    ~StartLayer();
};

#endif /* defined(__Richer__StartLayer__) */
