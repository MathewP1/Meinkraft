//
// Created by mateusz on 12/5/21.
//
#include <cstring>

#include "game.h"
#include "state.h"
#include "game_state.h"


namespace {
    const int UPDATES_PER_SECOND = 60; // TODO: maybe move this to config.h?
}

Game::Game() {
    width_ = 128;
    height_ = 128;
    window_ = std::make_unique<Window>(width_, height_);
}

std::unique_ptr<Game> Game::create() {
    return std::make_unique<Game>();
}

void Game::handleEvents() {
    sf::Event event{};
    sf::RenderWindow& window = window_->getWindow();
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window_->getWindow().close();
            return;
        }
        keyboard_handler_.handleInput(event);
    }
}

void Game::run() {

    // init state manager and set starting state
    StateManager state_manager(std::make_unique<GameState>());
    state_manager.getCurrentState()->init();

    // init Renderer
    Renderer renderer(width_, height_);

    // time measurement stuff
    sf::Clock clock;
    sf::Time time_since_update = sf::Time::Zero;
    sf::Time update_time_step = sf::seconds(1.f / UPDATES_PER_SECOND);
    renderer.fillRect(10, 10, 10, 10, Color::fromLimitedPalette(055));
    // enter game loop
    while(window_->getWindow().isOpen()) {
        // handle event regardless of the state
        handleEvents();

        // handle state change (ScheduleStateChange(nextState))

        time_since_update += clock.restart();
        while (time_since_update >= update_time_step) {
            time_since_update -= update_time_step;
            handleEvents();

            // update
            state_manager.updateState();
            state_manager.getCurrentState()->update();
        }


        // draw for current state
        state_manager.getCurrentState()->draw(renderer);


        window_->display(renderer);
    }
}