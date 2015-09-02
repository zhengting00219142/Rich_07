//
//  OverLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#include "OverLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* OverLayer::createScene()
{
    initWinSiz();
    auto scene = Scene::create();
    auto layer = OverLayer::create();
    scene->addChild(layer, 3);
    return scene;
}

OverLayer *OverLayer::create()
{
    OverLayer *ret = new (std::nothrow) OverLayer();
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

OverLayer::OverLayer(){}
OverLayer::~OverLayer(){}
