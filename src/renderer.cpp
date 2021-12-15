//
// Created by mateusz on 12/6/21.
//

#include "config.h"
#include "renderer.h"

Renderer::Renderer(unsigned int width, unsigned int height) {
    pixels_ = std::make_unique<uint8_t[]>(width * height);
    width_ = width;
    height_ = height;

    generatePalette();
}

void Renderer::fillBuffer(uint32_t *buffer) {
    for (int i = 0; i < width_ * height_; ++i) {
        buffer[i] = palette_[pixels_[i]];
    }
}

void Renderer::fillRect(int x, int y, int w, int h, Color c) {
    // TODO: temp solution - fill whole screen

    for (int i = 0; i < width_ * height_; ++i) {
        pixels_[i] = c.asPaletteIndex().palette_index;
    }
}

void Renderer::drawSprite(Sprite& sprite, int x, int y, uint32_t color) {

  auto* sprite_buffer = sprite.getBuffer();

  // TODO: when implementing camera, check if entirely offscreen

  int dx = (x + SPRITE_SIZE < width_) ? x + SPRITE_SIZE : width_;
  int dy = (y + SPRITE_SIZE < height_) ? y + SPRITE_SIZE : height_;

  for (int sprite_i = 0, image_i = x; image_i < dx; ++sprite_i, ++image_i) {
    for (int sprite_j = 0, image_j = y; image_j < dy; ++sprite_j, ++image_j) {
      int sprite_pixel = sprite_buffer[sprite_i * SPRITE_SIZE + sprite_j];
      if (sprite_pixel) {
        pixels_[image_i * width_ + image_j] = (color >> (sprite_pixel*8)) & 0xFF;
      }
    }
  }
}

// TODO: tweak color palette
void Renderer::generatePalette() {
    int i = 0;
    int coeff = 255 / 6;
    for (int r = 0; r < 6; r++) {
        for (int g = 0; g < 6; g++) {
            for (int b = 0; b < 6; b++) {
                int rr = coeff * r;
                int gg = coeff * g;
                int bb = coeff * b;
                palette_[i++] = (0xFF << 24) | (bb << 16) | (gg << 8) | rr << 0;
            }
        }
    }
}