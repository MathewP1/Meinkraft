//
// Created by mateusz on 12/6/21.
//
#include <memory>
#include <utility>

#include "color.h"
#include "entity.h"
#include "sprite.h"

#ifndef MEINKRAFT_RENDERABLE_ENTITY_H
#define MEINKRAFT_RENDERABLE_ENTITY_H

class RenderEntity : public Entity {
public:
    /// takes encoded color (4 indices to palette)
    RenderEntity(int x, int y, int w, int h, std::shared_ptr<Sprite> sprite, uint32_t color)
     : Entity(x, y, w, h), sprite(std::move(sprite)), color(color) { }

    Sprite& getSprite() {
        return *(sprite);
    }

    uint32_t getColor() {
        return color;
    }


private:
    std::shared_ptr<Sprite> sprite;
    uint32_t color;
};

#endif //MEINKRAFT_RENDERABLE_ENTITY_H
