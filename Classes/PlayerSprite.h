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
#include "LandSprite.h"

class PlayerSprite : public cocos2d::Sprite{
public:
    Position p;
    
    int cash;
    int ticket;
    int status;
    int items[ITEM_KINDS];
    Vector<LandSprite *> properties;
    
    static PlayerSprite *create(const std::string& filename, int fund);
    PlayerSprite();
    
    int getNetWorth();
};

#endif /* defined(__Richer__PlayerSprite__) */
