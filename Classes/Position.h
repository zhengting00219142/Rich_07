//
//  Position.h
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#ifndef __Richer__Position__
#define __Richer__Position__

#include <stdio.h>

class Position {
public:
    int x, y;
    
    Position();
    Position(int x, int y);
    void setPosition(int x, int y);
    bool isEqual(Position other);
};

#endif /* defined(__Richer__Position__) */
