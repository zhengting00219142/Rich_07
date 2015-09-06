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

class InitLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    static InitLayer *create();
	static cocos2d::ui::Button* markButtons[4];
	static cocos2d::ui::TextField* fondField;
	static cocos2d::ui::Button* playButton;
    InitLayer();
    ~InitLayer();
    
    void playCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    void backCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	void richChooseCallback(Ref* sender, int i);
};

#endif /* defined(__Richer__InitLayer__) */
