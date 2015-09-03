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
    // 4 selectable person: 1, 2, 3, 4
    int code;
    Position p;
    
    int cash;
    int ticket;
    int status;
    int items[ITEM_KINDS];
    std::vector<LandSprite *> properties;
    
    static PlayerSprite *create(int code, int fund);
    static std::string int2Avatar(int i);
    PlayerSprite();
    
    void move2Spot(Position dst);
    int getNetWorth();
};

#endif /* defined(__Richer__PlayerSprite__) */
