#include "config.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <memory>

#include "renderer.h"

// TODO:
//  1. Create color palette
//  2. Render images using color palette
//  3. Add character that can move up, down, left, right
//  4. Add light source to character and apply lighting with dithering


int color_to_palette(int r, int g, int b) {
    return r * g * b;
}

int main() {
    std::cout << "Version: " << PROJECT_VERSION_MAJOR << "."
        << PROJECT_VERSION_MINOR << std::endl;

    uint32_t WINDOW_WIDTH = 1024;
    uint32_t WINDOW_HEIGHT = 512;
    unsigned int COLOR_CHANNELS = 4;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Meinkraft");

    Renderer renderer;

    // pixel buffer, each entry represents rgba pixel, size equal to renderer buffer size, scaled up to display later
    auto buffer = std::make_unique<unsigned char[]>(renderer.width * renderer.height * COLOR_CHANNELS);
    auto buffer_ptr = reinterpret_cast<uint32_t*>(buffer.get());

    // fill pixel buffer with white color
    for (int i = 0; i < renderer.width*renderer.height; ++i) {
        buffer_ptr[i] = 0xFFFFFFFF;
    }




    // fill every row with palette
//    for (int row = 0; row < renderer.height; ++row) {
//        for (int i = 0; i < 256; ++i) {
//            renderer.renderer_pixels_ptr[row*renderer.width + i] = (renderer.palette[i] << 8) | 0xFF;
//        }
//    }

    sf::Texture texture;
    texture.create(renderer.width, renderer.height);

    int scale_factor_x = WINDOW_WIDTH / renderer.width;
    int scale_factor_y = WINDOW_HEIGHT / renderer.height;

    // colors in [0-5]
    int red = 0;
    int green = 0;
    int blue = 5;
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        for (int i = 0; i < renderer.width * renderer.height; ++i) {
//        buffer_ptr[i] = (renderer.palette[renderer.pixels[i]] << 8) | 0xFF;
//            int color_decimal = red * 100 + green * 10 + blue;
            int palette_index = red * 36 + green * 6 + blue;
//            buffer_ptr[i] = renderer.palette[palette_index] | 0xFF000000;
            buffer_ptr[i] = 0xFFFF0000; // TODO: THIS IS NOT RGBA OR ARGB IT"S ABGR!!!!
        }



        for (int row = 0; row < renderer.height/2; ++row) {
            for (int i = 0; i < 256; ++i) {
                buffer_ptr[row*renderer.width + i] = renderer.palette[i] |  0xFF000000;
            }
        }


        window.clear(sf::Color::Black);

        // copy renderer pixels to image buffer through palette
//        for (int i = 0; i < renderer.width * renderer.height; ++i) {
//            buffer_ptr[i] = (renderer.palette[renderer.pixels[i]] << 8) | 0xFF;
//        }

        // update buffer
        texture.update(buffer.get());
        sf::Sprite sprite(texture);
        sprite.setScale(static_cast<float>(scale_factor_x), static_cast<float>(scale_factor_y));
        window.draw(sprite);
        window.display();
    }
}
