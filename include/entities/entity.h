//
// Created by mateusz on 12/6/21.
//

#include "rect.h"

#ifndef MEINKRAFT_ENTITY_H
#define MEINKRAFT_ENTITY_H

class Entity {
protected:
    Rect rect;
public:
    Rect& getRect() {
        return rect;
    }
    // TODO: not sure if this base class is needed
};

#endif //MEINKRAFT_ENTITY_H
