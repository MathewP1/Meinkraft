//
// Created by mateusz on 12/5/21.
//

#include <SFML/System/Time.hpp>
#include <memory>
#include <iomanip>
#include <cstdint>
#include <iostream>
#include <cmath>

#ifndef MEINKRAFT_RENDERER_H
#define MEINKRAFT_RENDERER_H

// class responsible for rendering provided rgb arrays and lighting scene
// uses color palette_ of 64 colors, defined by r,g,b values of {0, 1, 2, 3}

// colors in renderer are stored as indexes of this color in palette_
class Renderer {
public:
    // game view size, will be scaled up to window size
    const unsigned int width_ = 256;
    const unsigned int height_ = 256;

    // game screen buffer, each entry is an index to the palette_ array [0 - 216)
    std::unique_ptr<unsigned char[]> pixels_;
    // colors are in ABGR format
    uint32_t palette_[256];

    float palette_offset = 0.0f;
    float palette_offset_speed = 100.0f;

    Renderer() {
        pixels_ = std::make_unique<unsigned char[]>(width_ * height_);

        // set pixels_ to specific color
        // red, green, blue [0, 6]
        generatePalette();
    }

    void draw(uint32_t* buffer, const sf::Time& delta_time) {
        // draw content of renderer to buffer in correct rgb/color format


        palette_offset += palette_offset_speed * delta_time.asSeconds();
//        int red = 0;
//        int green = 3;
//        int blue = 3;
//        int palette_index = (red << 4) | (green << 2) | blue;
//        std::cout << "Palette index: " << palette_index << std::endl;
//        std::cout << "Palette color: " << std::setfill('0') << std::setw(8) << std::hex << palette_[palette_index] << std::endl;
//        for (int i = 0; i < width_ * height_; ++i) {
//            buffer[i] = palette_[(i + static_cast<int>(palette_offset)) % 216];
//        }

        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < 216; ++j) {
                int index = i * width_ + j;
//                buffer[index] = palette_[j];
                buffer[index] = palette_[(j + i + static_cast<int>(palette_offset)) % 216];
            }

        }

    }

private:
    // TODO: tweak color palette
    void generatePalette() {
        int i = 0;

        int rr, gg, bb;
        int coeff = 255 / 6;
        for (int r = 0; r < 6; r++) {
            for (int g = 0; g < 6; g++) {
                for (int b = 0; b < 6; b++) {
                    rr = coeff * r;
                    gg = coeff * g;
                    bb = coeff * b;
                    palette_[i++] = (0xFF << 24) | (bb << 16) | (gg << 8) | rr << 0;
                }
            }
        }
    }

    void drawColors(uint32_t* buffer) {
        uint32_t red = 0xFF0000FF;
        uint32_t green = 0xFF00FF00;
        uint32_t blue = 0xFFFF0000;
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                int index = i * width_ + j;
                if (i < height_ / 3) {
                    buffer[index] = red;
                } else if (i < 2 * height_ / 3) {
                    buffer[index] = green;
                } else {
                    buffer[index] = blue;
                }
            }
        }
    }
};


#endif //MEINKRAFT_RENDERER_H
