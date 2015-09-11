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
    sprite->objs.clear();
    if (sprite && sprite->initWithFile(sprite->int2Img(type)))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

std::string LandSprite::int2Img(int i) {
    switch (i) {
        case LTYPE_NOTHING: return "start.png";
        case LTYPE_UNOCCUPIED: return "unoccupied.png";
        case LTYPE_SHOP: return "shop.png";
        case LTYPE_GIFT: return "gift.png";
        case LTYPE_MAGIC: return "magic.png";
        case LTYPE_HOSPITAL: return "hospital.png";
        case LTYPE_PRISON: return "prison.png";
        case LTYPE_MINE: return "mine.png";
        default: return "robot.png";
    }
}

LandSprite::LandSprite(){}

void LandSprite::setUp(int streetVal, Position p) {
    this->data = 0;
    this->streetVal = streetVal;
    this->p = p;
    this->setScale(tileScale);
    this->setPosition(this->p.toRealPos());
}

void LandSprite::levelUp(int who) {
    this->owner = who;
    this->type++;
    this->data += streetVal;
    Texture2D* texture = Director::getInstance()->getTextureCache()->addImage(houseImg[who][type]);
    this->setTexture(texture);
}

void LandSprite::putObj(int what) {
    Sprite *obj = Sprite::create(itemImg[what]);
    // #trying out user data, might cause error
    obj->setUserData(&what);
    obj->setScale(tileScale);
    this->addChild(obj);
    objs.push_back(obj);
}