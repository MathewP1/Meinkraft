#include "config.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>


int main() {
    std::cout << "Version: " << PROJECT_VERSION_MAJOR << "."
        << PROJECT_VERSION_MINOR << std::endl;

    uint32_t width = 800;
    uint32_t height = 600;
    sf::RenderWindow window(sf::VideoMode(width, height), "Meinkraft");

    unsigned char* pixel_buffer = new unsigned char[width * height * 4];
    for (int i = 0; i < width * height * 4; i += 4) {
        pixel_buffer[i] = 255;
        pixel_buffer[i+1] = 0;
        pixel_buffer[i+2] = 0;
        pixel_buffer[i+3] = 255;
    }
    uint32_t* pixels = (uint32_t *)pixel_buffer;

    unsigned char red = 0;
    unsigned char blue = 255;

    sf::Texture texture;
    texture.create(width, height);

    int frame = 0;
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
        window.clear(sf::Color::Black);

        // do something cool with our buffer here
        uint32_t rgba = (255 << 24) | (red++ << 16) | (255 << 8) | 255;
        for (int i = 0; i < width*height; ++i) {
            pixels[i] = rgba;
        }


        // update buffer
        texture.update(pixel_buffer);
        sf::Sprite sprite(texture);
        window.draw(sprite);
        window.display();

    }
}
