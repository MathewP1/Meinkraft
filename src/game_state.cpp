//
// Created by mateusz on 12/5/21.
//
#include "config.h"
#include "game_state.h"
#include "sprite.h"

#include <iostream>
#include <iomanip>

bool GameState::init() {
    const std::string resource_path = RESOURCE_PATH;
    player_sprite_ = Sprite::create(resource_path + "ai.png");
    if (!player_sprite_) {
        return false;
    }


    return true;
}

void GameState::update() {

}

void GameState::draw(Renderer& renderer) {

}
