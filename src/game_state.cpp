//
// Created by mateusz on 12/5/21.
//
#include "config.h"
#include "game_state.h"
#include "sprite.h"

#include <iostream>

bool GameState::init() {
    const std::string resource_path = RESOURCE_PATH;
    auto sprite = Sprite::create(resource_path + "tile.png");
    if (!sprite) {
        return false;
    }

    entity_ = std::make_unique<RenderEntity>(0, 0, 16, 16, std::move(sprite), Color::getSpriteColor(000, 000, 333, 444));



    return true;
}

void GameState::update() {

}

void GameState::draw(Renderer& renderer) {
    renderer.drawSprite(entity_->getSprite(), 0, 0, entity_->getColor());
}
