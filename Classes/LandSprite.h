//
//  LandSprite.h
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#ifndef __Richer__LandSprite__
#define __Richer__LandSprite__

#include "Richer.h"

class LandSprite : public cocos2d::Sprite{
public:
    Position p;
    
    int type;
    int streetVal;
    int data;
    int owner;
    
    static LandSprite *create(int type);
    static LandSprite *create();
    LandSprite();
    std::string int2Img(int i);
    void setUp(int streetVal, Position p);
    
    void levelUp();
};

#endif /* defined(__Richer__LandSprite__) */
