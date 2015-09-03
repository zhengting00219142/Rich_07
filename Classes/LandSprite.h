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
    
    static LandSprite *create(const std::string& filename);
    static LandSprite *create();
    LandSprite();
    void setUp(int type, int data, int x, int y);
};

#endif /* defined(__Richer__LandSprite__) */
