//
//  PlayerSprite.cpp
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#include "PlayerSprite.h"

PlayerSprite* PlayerSprite::create(int fund)
{
    PlayerSprite* pRet = new PlayerSprite();
    pRet->cash = fund;
    
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}