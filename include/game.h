//
// Created by mateusz on 12/5/21.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "config.h"
#include "renderer.h"

#ifndef MEINKRAFT_GAME_H
#define MEINKRAFT_GAME_H

class Game{
public:
    Game();
    static std::unique_ptr<Game> create();
    void run();

private:
    int width_;
    int height_;
};

#endif //MEINKRAFT_GAME_H
