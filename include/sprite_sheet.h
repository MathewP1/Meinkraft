//
// Created by mateusz on 12/5/21.
//

#include <SFML/Graphics/Image.hpp>
#include <memory>

#ifndef MEINKRAFT_SPRITE_SHEET_H
#define MEINKRAFT_SPRITE_SHEET_H

class SpriteSheet {
public:
    explicit SpriteSheet(const sf::Image& image, int sprite_size);
    static std::unique_ptr<SpriteSheet> create(const std::string& image_path, int sprite_size);
    std::unique_ptr<uint32_t[]> getBuffer(int sprite_index);
private:
    uint32_t width_, height_;
    uint32_t sprite_size_;
    uint32_t rows_, columns_;
    std::unique_ptr<uint32_t[]> pixel_buffer_;
    uint8_t* pixel_buffer_ptr_;
};

#endif //MEINKRAFT_SPRITE_SHEET_H
