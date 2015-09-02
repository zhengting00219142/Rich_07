//
//  PauseLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#include "PauseLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* PauseLayer::createScene()
{
    initWinSiz();
    auto scene = Scene::create();
    auto layer = PauseLayer::create();
    scene->addChild(layer, 3);
    return scene;
}

PauseLayer *PauseLayer::create()
{
    PauseLayer *ret = new (std::nothrow) PauseLayer();
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

PauseLayer::PauseLayer(){}
PauseLayer::~PauseLayer(){}
