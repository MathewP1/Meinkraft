//
// Created by mateusz on 12/5/21.
//

#include "sprite_sheet.h"

SpriteSheet::SpriteSheet(const sf::Image &image, int sprite_size) {
    sprite_size_ = sprite_size;
    width_ = image.getSize().x;
    height_ = image.getSize().y;
    rows_ = height_ / sprite_size_;
    columns_ = width_ / sprite_size_;
    pixel_buffer_ = std::make_unique<uint32_t[]>(width_ * height_);
    // TODO: fix, this returns unsigned char* not uint32_t...
    const auto* image_pixels = image.getPixelsPtr();

    // TODO: replace with memcpy
    for (int i = 0; i < width_ * height_; ++i) {
        pixel_buffer_[i] = (image_pixels[i] & 0xFF) / 64;
    }
}

// TODO: maybe don't need to copy this?
// (since when colored uint8_t[] can be used to hold buffer, it will only hold palette indices)
std::unique_ptr<uint32_t[]> SpriteSheet::getBuffer(int sprite_index) {
    int pos_x = sprite_index % columns_;
    int pos_y = (sprite_index - pos_x) / rows_;

    auto out_buffer = std::make_unique<uint32_t[]>(sprite_size_ * sprite_size_);
    int out_i = 0;
    for (int i = pos_x * sprite_size_; i < (pos_x + 1) * sprite_size_; ++i) {
        for (int j = pos_y * sprite_size_; j < (pos_y + 1) * sprite_size_; ++j) {
            out_buffer[out_i++] = pixel_buffer_[i * width_ + j];
        }
    }

    return std::move(out_buffer);
}

std::unique_ptr<SpriteSheet> SpriteSheet::create(const std::string& image_path, int sprite_size) {
    sf::Image image;
    if (!image.loadFromFile(image_path) || sprite_size <= 0) {
        return nullptr;
    }
    return std::make_unique<SpriteSheet>(image, sprite_size);
}