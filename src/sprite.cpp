//
// Created by mateusz on 12/5/21.
//
#include "sprite.h"

#include <cstring>
#include <iostream>

Sprite::Sprite(const sf::Image& image) {
    width_ = image.getSize().x;
    height_ = image.getSize().y;

    // TODO: make_unique does value init, maybe use std::unique_ptr<>(new...)
    pixel_buffer_ = std::make_unique<int[]>(width_ * height_);

    const auto* image_pixels = image.getPixelsPtr();

    for (int i = 0; i < width_ * height_; ++i) {
        // don't allow any alpha except 100%, r,g,b should be the same so only r is used
        auto pixel_r = image_pixels[i*4];
        auto pixel_a = image_pixels[i*4 + 3];
        pixel_buffer_[i] = (pixel_a != 0xFF) ? -1 : pixel_r / 64;
    }
}

std::unique_ptr<Sprite> Sprite::clone() {
    auto out_sprite = std::make_unique<Sprite>();
    out_sprite->width_ = width_;
    out_sprite->height_ = height_;
    out_sprite->pixel_buffer_ = std::make_unique<int[]>(width_ * height_);
    memcpy(out_sprite->pixel_buffer_.get(), pixel_buffer_.get(), width_ * height_ * sizeof(uint32_t));
    return std::move(out_sprite);
}

int* Sprite::getBuffer() {
    return pixel_buffer_.get();
}

std::unique_ptr<Sprite> Sprite::create(const std::string& image_path) {
    sf::Image image;
    if (!image.loadFromFile(image_path)) {
        return nullptr;
    }
    return std::make_unique<Sprite>(image);
}