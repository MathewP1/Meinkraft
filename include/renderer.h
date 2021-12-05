//
// Created by mateusz on 12/5/21.
//

#ifndef MEINKRAFT_RENDERER_H
#define MEINKRAFT_RENDERER_H

#include <memory>

class Renderer {
public:
    const unsigned int width = 256;
    const unsigned int height = 128;

    // game screen buffer, each entry is an index to the palette array (0 - 216)
    std::unique_ptr<unsigned char[]> pixels;
    uint32_t palette[256];

    Renderer() {
        pixels = std::make_unique<unsigned char[]>(width * height);

        // set pixels to specific color
        // red, green, blue [0, 6]

        int red = 6;
        int green = 6;
        int blue = 6;
        for (int i = 0; i < width * height; ++i) {
            pixels[i] = red * green * blue;
        }
        generatePalette();
    }

private:
    void generatePalette() {
        int i = 0;

        for (int r = 0; r < 6; r++) {
            for (int g = 0; g < 6; g++) {
                for (int b = 0; b < 6; b++) {
                    int rr = (r * 255) / 5,
                            gg = (g * 255) / 5,
                            bb = (b * 255) / 5,
                            m = (rr * 30 + gg * 59 + bb * 11) / 100;

                    palette[i++] = ((((rr + m) / 2) * 230 / 255 + 10) << 16) |
                                   ((((gg + m) / 2) * 230 / 255 + 10) << 8) |
                                   ((((bb + m) / 2) * 230 / 255 + 10) << 0);
                }
            }
        }
    }
};


#endif //MEINKRAFT_RENDERER_H
