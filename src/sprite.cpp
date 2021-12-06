//
// Created by mateusz on 12/5/21.
//
#include "sprite.h"

#include <cstring>

Sprite::Sprite(const sf::Image& image) {
    width_ = image.getSize().x;
    height_ = image.getSize().y;

    // TODO: make_unique does value init, maybe use std::unique_ptr<>(new...)
    pixel_buffer_ = std::make_unique<uint32_t[]>(width_ * height_);

    const auto* image_pixels = image.getPixelsPtr();

    for (int i = 0; i < width_ * height_; ++i) {
        pixel_buffer_[i] = (image_pixels[i] & 0xFF) / 64;
    }
}

uint32_t* Sprite::getBuffer() {
    return pixel_buffer_.get();
}

std::unique_ptr<Sprite> Sprite::create(const std::string& image_path) {
    sf::Image image;
    if (!image.loadFromFile(image_path)) {
        return nullptr;
    }
    return std::make_unique<Sprite>(image);
}