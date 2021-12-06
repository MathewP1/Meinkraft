//
// Created by mateusz on 12/5/21.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "config.h"
#include "renderer.h"
#include "keyboard_handler.h"
#include "window.h"

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
    KeyboardHandler keyboard_handler_;

    std::unique_ptr<Window> window_;

    void handleEvents();
};

#endif //MEINKRAFT_GAME_H
