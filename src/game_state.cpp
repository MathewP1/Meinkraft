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

//    auto buffer = player_sprite_->getBuffer();
//    for (int i = 0; i < 16; ++i) {
//        for (int j = 0; j < 16; ++j) {
//            std::cout << std::setfill('0') << std::setw(8) << std::hex << buffer[i * 16 + j] << std::endl;
//        }
//    }

    return true;
}

void GameState::update() {

}

void GameState::draw() {

}
