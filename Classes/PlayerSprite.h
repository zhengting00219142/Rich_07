//
//  PlayerSprite.h
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#ifndef __Richer__PlayerSprite__
#define __Richer__PlayerSprite__

#include "Richer.h"

class PlayerSprite : public cocos2d::Sprite{
public:
    int cash;
    int ticket;
    
    static PlayerSprite *create(int fund);
};

#endif /* defined(__Richer__PlayerSprite__) */
