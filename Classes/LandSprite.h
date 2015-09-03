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
    int data;
    int owner;
    
    static LandSprite *create(int type);
    static LandSprite *create();
    static std::string int2Img(int i);
    LandSprite();
    void setUp(int data, int x, int y);
};

#endif /* defined(__Richer__LandSprite__) */
