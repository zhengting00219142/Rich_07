//
//  QuestionLayer.h
//  Richer
//
//  Created by Macbook Air on 9/6/15.
//
//

#ifndef __Richer__QuestionLayer__
#define __Richer__QuestionLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class QuestionLayer : public cocos2d::Layer
{
public:
    static QuestionLayer *create(std::string sign, std::string info);
    QuestionLayer();
    ~QuestionLayer();
    
    std::string signiture;
    std::string info;
    
    void yesCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    void noCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* defined(__Richer__QuestionLayer__) */
