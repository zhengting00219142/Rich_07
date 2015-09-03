//
//  PlayerSprite.cpp
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#include "PlayerSprite.h"

PlayerSprite* PlayerSprite::create(int code, int fund)
{
    PlayerSprite *sprite = new (std::nothrow) PlayerSprite();
    sprite->code = code;
    // init fund
    sprite->cash = fund;
    sprite->ticket = 0;
    sprite->status = STATUS_NORM;
    // init items
    for(int i = 0; i < ITEM_KINDS; i++) {
        sprite->items[i] = 0;
    }
    sprite->setScale(tileScale);
    
    if (sprite && sprite->initWithFile(pavatar[code]))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

PlayerSprite::PlayerSprite(){}

void PlayerSprite::move2Spot(Position dst) {
    p = dst;
    this->runAction(MoveTo::create(1/2.0, dst.toRealPos()));
}

int PlayerSprite::getNetWorth() {
    int propertyWorth = 0;
    for(int i = 0; i < properties.size(); i++) {
        propertyWorth += properties[i]->data;
    }
    return propertyWorth + cash;
}
