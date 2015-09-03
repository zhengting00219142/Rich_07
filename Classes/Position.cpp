//
//  Position.cpp
//  Richer
//
//  Created by Macbook Air on 9/2/15.
//
//

#include "Position.h"

Position::Position() {
    this->x = this->y = 0;
}

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

void Position::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Position::isEqual(Position other) {
    if(this->x == other.x && this->y == other.y)
        return true;
    else
        return false;
}