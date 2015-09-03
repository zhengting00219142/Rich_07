//
//  LandSprite.cpp
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#include "LandSprite.h"

LandSprite* LandSprite::create(int type)
{
    LandSprite *sprite = new (std::nothrow) LandSprite();
    sprite->type = type;
    if (sprite && sprite->initWithFile(int2Img(type)))
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
    sprite->type = LTYPE_NOTHING;
    if (sprite && sprite->init())
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

std::string LandSprite::int2Img(int i) {
    switch (i) {
        case LTYPE_UNOCCUPIED: return "bomb.png";
        case LTYPE_SHOP: return "richer2.png";
        case LTYPE_GIFT: return "richer3.png";
        case LTYPE_MAGIC: return "richer4.png";
        case LTYPE_HOSPITAL: return "richer4.png";
        case LTYPE_PRISON: return "richer4.png";
        case LTYPE_MINE: return "richer4.png";
//        case LTYPE_NOTHING: return "richer4.png";
        case LTYPE_LV1: return "richer4.png";
        case LTYPE_LV2: return "richer4.png";
        case LTYPE_MAXLV: return "richer4.png";
        default: return "richer4.png";
    }
}

LandSprite::LandSprite(){}

void LandSprite::setUp(int data, int x, int y) {
    this->data = data;
    this->p = Position(x, y);
    this->setScale(tileScale);
}