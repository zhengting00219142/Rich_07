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
    Position *p;
    
    int type;
    int worth;
    
    static LandSprite *create(const std::string& filename);
    LandSprite();
};

#endif /* defined(__Richer__LandSprite__) */
