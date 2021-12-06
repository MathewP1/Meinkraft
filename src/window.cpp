//
// Created by mateusz on 12/6/21.
//

#include "window.h"

Window::Window(int game_width, int game_height) {
    buffer_ = std::make_unique<uint32_t[]>(game_width * game_height);
    scale_x_ = width / game_width;
    scale_y_ = height / game_height;

    window_.create(sf::VideoMode(width, height), "Can't see");
    texture_.create(game_width, game_height);
}

uint32_t* Window::getBuffer() {
    return buffer_.get();
}

sf::RenderWindow& Window::getWindow() {
    return window_;
}

void Window::display(Renderer& renderer) {
    // update buffer with pixels from renderer
    renderer.fillBuffer(buffer_.get());
    auto* buffer_ptr = reinterpret_cast<unsigned char*>(buffer_.get());
    texture_.update(buffer_ptr);
    sprite_.setTexture(texture_);
    sprite_.setScale(scale_x_, scale_y_);
    window_.draw(sprite_);
    window_.display();
}