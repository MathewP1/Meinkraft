//
// Created by mateusz on 12/6/21.
//

#include "rect.h"

#ifndef MEINKRAFT_ENTITY_H
#define MEINKRAFT_ENTITY_H

// TODO: not sure if this base class is needed
class Entity {
protected:
    Rect rect;
public:
    Entity(int x, int y, int w, int h) : rect(x, y, w, h) {}
    Rect& getRect() {
        return rect;
    }
};

#endif //MEINKRAFT_ENTITY_H
