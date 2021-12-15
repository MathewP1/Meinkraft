//
// Created by mateusz on 12/5/21.
//
#include "game_state.h"

#include <iostream>

#include "config.h"
#include "sprite.h"

bool GameState::init() {
  const std::string resource_path = RESOURCE_PATH;
  auto sprite = Sprite::create(resource_path + "tile.png");
  if (!sprite) {
    return false;
  }

  entities_.push_back(std::make_unique<RenderEntity>(
      0, 0, 16, 16, std::move(sprite),
      Color::getSpriteColor(444, 444, 444, 444)));

  return true;
}

void GameState::update() {}

void GameState::draw(Renderer& renderer) {
  for (auto& e : entities_) {
    renderer.drawSprite(e->getSprite(), 40, 40, e->getColor());
  }
}
