//
//  LandSprite.cpp
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#include "LandSprite.h"

LandSprite* LandSprite::create(const std::string& filename)
{
    LandSprite *sprite = new (std::nothrow) LandSprite();
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

LandSprite* LandSprite::create()
{
    LandSprite *sprite = new (std::nothrow) LandSprite();
    if (sprite && sprite->init())
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

LandSprite::LandSprite(){}

void LandSprite::setUp(int type, int data, int x, int y) {
    this->type = type;
    this->data = data;
    this->p = Position(x, y);
    this->setScale(tileScale);
}