//
//  InitLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#include "InitLayer.h"
#include "StartLayer.h"
#include "GameLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

cocos2d::ui::Button** InitLayer::markButtons = NULL;

Scene* InitLayer::createScene()
{
    initWinSiz();
    auto scene = Scene::create();
    auto layer = InitLayer::create();
    scene->addChild(layer, 3);
    return scene;
}

InitLayer *InitLayer::create()
{
    InitLayer *ret = new (std::nothrow) InitLayer();
    
    auto rootNode = CSLoader::createNode("SetScene.csb");
    ret->addChild(rootNode);
    
    Button* playBtn = dynamic_cast<Button*>(rootNode->getChildByName("next"));
    playBtn->addTouchEventListener(CC_CALLBACK_2(InitLayer::playCallback, ret));
    Button* backBtn = dynamic_cast<Button*>(rootNode->getChildByName("back"));
    backBtn->addTouchEventListener(CC_CALLBACK_2(InitLayer::backCallback, ret));
    
	Button* richButtons[4];
	int i = 0;
	string richs[4] = {
		"rich1" ,
		"rich2" ,
		"rich3" ,
		"rich4"
	};
	string marks[4] = {
		"richer1marked" ,
		"richer2marked" ,
		"richer3marked" ,
		"richer4marked" ,
	};
	markButtons = new Button*[4];
	while (i < 4) {
		// oss << "rich" << i;
		richButtons[i] = dynamic_cast<Button*>(rootNode->getChildByName(richs[i]));
		markButtons[i] = dynamic_cast<Button*>(rootNode->getChildByName(marks[i]));
		richButtons[i]->addClickEventListener(CC_CALLBACK_1(InitLayer::richChooseCallback, ret, i)); // add touch listener.
		i++;
	}

    if (ret && ret->init())
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

InitLayer::InitLayer(){}
InitLayer::~InitLayer(){
	if (markButtons != NULL)
		delete markButtons;
}

void InitLayer::playCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        // pnum has the correct riches

//        pnum.clear();pnum.push_back(2);pnum.push_back(0);pnum.push_back(1);

        CCDirector::getInstance()->replaceScene(GameLayer::createScene());
    }
}
void InitLayer::backCallback(Ref* sender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        CCDirector::getInstance()->replaceScene(StartLayer::createScene());
    }
}

// a callback when the rich button is pushed.
//set the richMark button visible or not according to its current status
// and then change the pnum
void InitLayer::richChooseCallback(Ref* sender, int i) {
	Button* markButton = markButtons[i];
	if (markButton->isVisible()) {
		vector<int>::iterator ite;
		for (ite = pnum.begin(); ite != pnum.end(); ite++) {
			if (*ite == i) {
				pnum.erase(ite);
				break;
			}
		}
		markButton->setVisible(false);
	}
	else {
		pnum.push_back(i);
		markButton->setVisible(true);
	}
}
