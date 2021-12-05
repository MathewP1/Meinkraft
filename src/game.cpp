//
// Created by mateusz on 12/5/21.
//
#include <cstring>

#include "game.h"
#include "state.h"
#include "game_state.h"


namespace {
    const int UPDATES_PER_SECOND = 60;
    struct Window {
        const unsigned int height = 1024;
        const unsigned int width = 1024;
        const unsigned int color_channels = 4;

        sf::RenderWindow window;
        sf::Texture texture;
        sf::Sprite sprite;

        float scale_x, scale_y;

        std::unique_ptr<unsigned char[]> window_buffer; // ABGR

        void display() {
            texture.update(window_buffer.get());
            sprite.setTexture(texture);
            sprite.setScale(scale_x, scale_y);
            window.draw(sprite);
            window.display();
        }

        Window(int game_width, int game_height) {
            window_buffer = std::make_unique<unsigned char[]>(game_width * game_height * color_channels);
            window.create(sf::VideoMode(width, height), "Can't see");

            texture.create(game_width, game_height);

            scale_x = width / game_width;
            scale_y = height / game_height;
        }
    };
}

Game::Game() {
    width_ = 128;
    height_ = 128;
}

std::unique_ptr<Game> Game::create() {
    return std::make_unique<Game>();
}

void Game::handleEvents(sf::RenderWindow& game_window) {
    sf::Event event{};
    while (game_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game_window.close();
            return;
        }
        keyboard_handler_.handleInput(event);
    }
}

void Game::run() {
    Window window(width_, height_);

    auto& game_window = window.window;
    auto* game_buffer_ptr = reinterpret_cast<uint32_t*>(window.window_buffer.get()); // this is how everything gets drawn

    for (int i = 0; i < width_ * height_; ++i) {
        game_buffer_ptr[i] = 0xFFFFFFFF;
    }

    StateManager state_manager(std::make_unique<GameState>());
    state_manager.getCurrentState()->init();
    sf::Clock clock;
    sf::Time time_since_update = sf::Time::Zero;
    sf::Time update_time_step = sf::seconds(1.f / UPDATES_PER_SECOND);
    // enter game loop
    while(game_window.isOpen()) {
        // handle event regardless of the state
        handleEvents(game_window);

        // handle state change (ScheduleStateChange(nextState))

        time_since_update += clock.restart();
        while (time_since_update >= update_time_step) {
            time_since_update -= update_time_step;
            handleEvents(game_window);

            // update
            state_manager.updateState();
            state_manager.getCurrentState()->update();
        }


        // draw for current state
        state_manager.getCurrentState()->draw();


        window.display();
    }
}