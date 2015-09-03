//
//  ToolsLayer.h
//  Richer
//
//  Created by Macbook Air on 9/3/15.
//
//

#ifndef __Richer__ToolsLayer__
#define __Richer__ToolsLayer__

#include "Richer.h"
#include "PauseLayer.h"
#include "OverLayer.h"

class ToolsLayer : public cocos2d::Layer
{
public:
    static ToolsLayer *create();
    ToolsLayer();
    ~ToolsLayer();
    
    void pauseCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    // tmp
    void overCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* defined(__Richer__ToolsLayer__) */
