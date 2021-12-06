//
// Created by mateusz on 12/6/21.
//

#include "window.h"

Window::Window(int game_width, int game_height) {
    // TODO: fix strict aliasing issue (create uint32_t* buffer, cast to unsig char)
    buffer_ = std::make_unique<unsigned char[]>(game_width * game_height * color_channels);
    scale_x_ = width / game_width;
    scale_y_ = height / game_height;

    window_.create(sf::VideoMode(width, height), "Can't see");
    texture_.create(game_width, game_height);
}

uint32_t* Window::getBufferPtr() {
    return reinterpret_cast<uint32_t*>(buffer_.get());
}

sf::RenderWindow& Window::getWindow() {
    return window_;
}

void Window::display() {
    texture_.update(buffer_.get());
    sprite_.setTexture(texture_);
    sprite_.setScale(scale_x_, scale_y_);
    window_.draw(sprite_);
    window_.display();
}