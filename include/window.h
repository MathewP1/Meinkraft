//
// Created by mateusz on 12/6/21.
//

#include <cstdint>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#ifndef MEINKRAFT_WINDOW_H
#define MEINKRAFT_WINDOW_H

class Window {
public:
    Window(int game_width, int game_height);
    void display();
    uint32_t* getBufferPtr();
    sf::RenderWindow& getWindow();

    const unsigned int height = 1024;
    const unsigned int width = 1024;
    const unsigned int color_channels = 4;
private:
    sf::RenderWindow window_;
    sf::Texture texture_;
    sf::Sprite sprite_;

    float scale_x_, scale_y_;

    std::unique_ptr<unsigned char[]> buffer_;

};

#endif //MEINKRAFT_WINDOW_H
