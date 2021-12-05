#include <iostream>

#include "config.h"
#include "game.h"

// TODO:
//  1. Create color palette_ DONE
//  2. Render images using color palette_ DONE
//  3. Calculate frametimes, add State and SpriteSheet, Color, Renderer (draw sprite, fillRect, light)
//  4. implement ticks, updates and renders class GameObject { virtual void Tick(), Update(), Render() }
//  5. Add GameState { virtual void Tick(), Update(), Render() }
//  6. Add character that can move up, down, left, right
//  7. Add light source to character and apply lighting with dithering

// tick - calculate how much movement, etc
// update - apply movement
// render - render to screen

// gets base 10 digi [000 - 555] representing RGB color
// returns palette index
uint32_t mapToPaletteIndex(int c) {
    if (c < 0) {
        return 0;
    }
    return ((c / 100) % 10) * 36 + ((c / 10) % 10) * 6 + (c % 10);
}

// gets c0-c3 colors of sprite, each base 10 digit [000 - 666]
// returns palette indexes coded into uint32_t
uint32_t getColor(int c0, int c1, int c2, int c3) {
    return ((mapToPaletteIndex(c3) & 0xFF) << 24) |
            ((mapToPaletteIndex(c2) & 0xFF) << 16) |
                    ((mapToPaletteIndex(c1) & 0xFF)) << 8 |
            (mapToPaletteIndex(c0) & 0xFF);
}

int main() {
    std::cout << "Version: " << PROJECT_VERSION_MAJOR << "."
        << PROJECT_VERSION_MINOR << std::endl;
    auto game = Game::create();
    game->run();
//    const unsigned int WINDOW_WIDTH = 1024;
//    const unsigned int WINDOW_HEIGHT = 1024;
//    unsigned int COLOR_CHANNELS = 4;
//    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Meinkraft");
//
//    Renderer renderer;
//
//    // pixel buffer, each entry represents rgba pixel, size equal to renderer buffer size, scaled up to display later
//    auto buffer = std::make_unique<unsigned char[]>(renderer.width_ * renderer.height_ * COLOR_CHANNELS);
//    auto buffer_ptr = reinterpret_cast<uint32_t*>(buffer.get());
//
//    // fill pixel buffer with white color
//    for (int i = 0; i < renderer.width_ * renderer.height_; ++i) {
//        buffer_ptr[i] = 0xFFFFFFFF;
//
//    }
//
//
//    // display image_buffer
////    for (int i = 0; i < image.getSize().x; ++i) {
////        for (int j = 0; j < image.getSize().y; ++j) {
////            buffer_ptr[i * renderer.width_ + j] = image_buffer[i * image.getSize().x + j];
////        }
////    }
//
////     image_pixels scaled to {0, 1, 2, 3}
//    uint32_t image_pixels[64*64/8];
//    auto image_pixels_ptr = reinterpret_cast<uint8_t*>(image_pixels);
//    for (int i = 0; i < image.getSize().x * image.getSize().y; ++i) {
//        image_pixels_ptr[i] = (image_buffer[i] & 0xFF) / 64;
//    }
//
//
//
//    sf::Texture texture;
//    texture.create(renderer.width_, renderer.height_);
//
//    int scale_factor_x = WINDOW_WIDTH / renderer.width_;
//    int scale_factor_y = WINDOW_HEIGHT / renderer.height_;
//
//    sf::Clock clock;
//    sf::Time delta_time;
//
//
//    while (window.isOpen()) {
//        delta_time = clock.restart();
//        sf::Event event{};
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//
//            if (event.type == sf::Event::KeyPressed) {
//                if (event.key.code == sf::Keyboard::Escape) {
//                    window.close();
//                }
//            }
//        }
//
//        window.clear(sf::Color::Black);
//
//        renderer.draw(buffer_ptr, delta_time);
//
//        uint32_t spriteColor = getColor(555, 505, 550, 222);
//
////        for (int i = 0; i < image.getSize().x; ++i) {
////            for (int j = 0; j < image.getSize().y; ++j) {
////                int index = i * image.getSize().x + j;
////                uint32_t image_pixel = image_pixels_ptr[index]; // pixel value in range [0-3]
////                buffer[i * renderer.width_ + j] = (spriteColor >> (image_pixel * 8)) & 0xFF; // take the correct sprite color depending on value of pixel
////                buffer[i * renderer.width_ + j] = 0xFFFFFFFF;
////            }
////        }
//
//        for (int i = 0; i < image.getSize().x; ++i) {
//            for (int j = 0; j < image.getSize().y; ++j) {
//                int pixel_value = (spriteColor >> (8 * image_pixels_ptr[i*image.getSize().x + j])) & 0xFF;
//                std::cout << pixel_value << std::endl;
//                buffer_ptr[i * renderer.width_ + j] = renderer.palette_[pixel_value];
//            }
//        }
//
//        // update buffer
//        texture.update(buffer.get());
//        sf::Sprite sprite(texture);
//        sprite.setScale(static_cast<float>(scale_factor_x), static_cast<float>(scale_factor_y));
//
//        window.draw(sprite);
//        window.display();
//    }
}
