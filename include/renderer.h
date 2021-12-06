//
// Created by mateusz on 12/5/21.
//

#include <SFML/System/Time.hpp>
#include <memory>
#include <iomanip>
#include <cstdint>
#include <iostream>
#include <cmath>

#include "color.h"
#include "sprite.h"

#ifndef MEINKRAFT_RENDERER_H
#define MEINKRAFT_RENDERER_H

// class responsible for rendering provided rgb arrays and lighting scene
// uses color palette_ of 64 colors, defined by r,g,b values of {0, 1, 2, 3}

// it fills buffers with color index from palette (later has to be dereferenced in color palette for full color)

class Renderer {
public:
    Renderer(unsigned int width, unsigned int height);

    // returns screen buffer of INDICES to colors in color palette
    void fillBuffer(uint32_t* buffer);

    // drawing methods
    void fillRect(int x, int y, int w, int h, Color c); // for drawing simple rects
    void drawSprite(Sprite& sprite, int x, int y, uint32_t c);  // for drawing (whole) sprites
    void drawPart(int x, int y, int w, int h, int sx, int sy) {}  // for use when needing to draw part of some buffer
    void drawPart(int x, int y, int w, int h, int sx, int sy, Color c) {} // for use with spritesheets

private:
    unsigned int width_, height_;
    // game screen buffer, each entry is an index to the palette_ array [0 - 216)
    std::unique_ptr<unsigned char[]> pixels_;
    // colors are in ABGR format, valid palette indices [0, 215]
    uint32_t palette_[256];
    void generatePalette();
};


#endif //MEINKRAFT_RENDERER_H
