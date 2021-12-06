//
// Created by mateusz on 12/6/21.
//
#include <memory>

#include "color.h"
#include "entity.h"
#include "sprite.h"

#ifndef MEINKRAFT_RENDERABLE_ENTITY_H
#define MEINKRAFT_RENDERABLE_ENTITY_H

class RenderableEntity : public Entity {
private:
    std::unique_ptr<Sprite> sprite;
    Color c;
};

#endif //MEINKRAFT_RENDERABLE_ENTITY_H
