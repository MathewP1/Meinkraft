//
// Created by mateusz on 12/5/21.
//
#include "sprite.h"

#include <cstring>

Sprite::Sprite(const sf::Image& image) {
    width_ = image.getSize().x;
    height_ = image.getSize().y;
    pixel_buffer_ = std::make_unique<uint32_t[]>(width_ * height_ / 8);
    auto* pixel_buffer_ptr_ = reinterpret_cast<uint8_t*>(pixel_buffer_.get());

    const auto* image_pixels = image.getPixelsPtr();

    // TODO: replace with memcpy
    for (int i = 0; i < width_ * height_; ++i) {
        pixel_buffer_ptr_[i] = (image_pixels[i] & 0xFF) / 64;
    }
}

std::unique_ptr<uint32_t[]> Sprite::getBuffer() {
    auto out_buffer = std::make_unique<uint32_t[]>(width_ * height_ / 8);

    memcpy(out_buffer.get(), pixel_buffer_.get(), width_ * height_ / 8 * sizeof(uint32_t));
    return std::move(out_buffer);
}

std::unique_ptr<Sprite> Sprite::create(const std::string& image_path) {
    sf::Image image;
    if (!image.loadFromFile(image_path)) {
        return nullptr;
    }
    return std::make_unique<Sprite>(image);
}