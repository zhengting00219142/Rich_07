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
    // 4 selectable avatar: 0, 1, 2, 3
    Position p;
    
    int facing;
    int cash;
    int ticket;
    int status;
    int items[ITEM_KINDS];
    std::vector<LandSprite *> properties;
    
    static PlayerSprite *create(int who, int fund);
    PlayerSprite();
    
    void move2Spot(Position dst);
    void purchaseLand(LandSprite *land);
    void levelupLand(LandSprite *land);
    
    int getNetWorth();
};

#endif /* defined(__Richer__PlayerSprite__) */
