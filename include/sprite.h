//
// Created by mateusz on 12/5/21.
//

#ifndef MEINKRAFT_SPRITE_H
#define MEINKRAFT_SPRITE_H

#include <SFML/Graphics/Image.hpp>

#include <memory>

// hold buffer of pixels in (0 - 3) range, each value represent
// one of the 4 possible colors that can be used on sprite

// sprites have the fixed width defined by game config
class Sprite {
public:
    explicit Sprite(const sf::Image& image);
    static std::unique_ptr<Sprite> create(const std::string& image_path);
    uint32_t* getBuffer();
private:
    uint32_t width_, height_;
    std::unique_ptr<uint32_t[]> pixel_buffer_;
};

#endif //MEINKRAFT_SPRITE_H
