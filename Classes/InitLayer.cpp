//
//  InitLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#include "InitLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;

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
InitLayer::~InitLayer(){}
