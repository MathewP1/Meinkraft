//
// Created by mateusz on 12/6/21.
//

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