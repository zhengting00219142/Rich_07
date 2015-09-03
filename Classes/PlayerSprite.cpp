//
//  PlayerSprite.cpp
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#include "PlayerSprite.h"

PlayerSprite* PlayerSprite::create(const std::string& filename, int fund)
{
    PlayerSprite *sprite = new (std::nothrow) PlayerSprite();
    // init fund
    sprite->cash = fund;
    sprite->ticket = 0;
    sprite->status = STATUS_NORM;
    // init items
    for(int i = 0; i < ITEM_KINDS; i++) {
        sprite->items[i] = 0;
    }
    sprite->setScale(tileScale);
    
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

PlayerSprite::PlayerSprite(){}