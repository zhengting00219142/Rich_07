//
//  StartLayer.cpp
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#include "StartLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* StartLayer::createScene()
{
    initWinSiz();
    auto scene = Scene::create();
    auto layer = StartLayer::create();
    scene->addChild(layer);
    return scene;
}

StartLayer *StartLayer::create()
{
    StartLayer *ret = new (std::nothrow) StartLayer();
    
    auto rootNode = CSLoader::createNode("StartScene.csb");
    ret->addChild(rootNode, 1);
    
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

StartLayer::StartLayer(){}
StartLayer::~StartLayer(){}
