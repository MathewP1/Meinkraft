//
// Created by mateusz on 12/6/21.
//

#include "color.h"

Color::Color() {
    format = ColorFormat::ABGR;
    abgr = 0xFFFFFFFF; // default value
}

Color Color::fromLimitedPalette(int c) {
    Color color;
    color.format = ColorFormat::LIMITED_PALETTE;
    color.limited_palette = static_cast<uint16_t>(c);
    return color;
}

Color Color::fromLimitedPalette(int r, int g, int b) {
    int c = r*100 + g*10 + b;
    return fromLimitedPalette(c);
}

Color Color::fromRGBA(uint32_t c) {
    Color color;
    color.format = ColorFormat::RGBA;
    color.rgba = c;
    return color;
}

Color Color::fromRGBA(int r, int g, int b, int a) {
    uint32_t color = ((r & 0xFF) << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | (a & 0xFF);
    return fromRGBA(color);
}

Color Color::fromABGR(uint32_t c) {
    Color color;
    color.format = ColorFormat::ABGR;
    color.abgr = c;
    return color;
}

Color Color::fromABGR(int a, int b, int g, int r) {
    uint32_t color = ((a & 0xFF) << 24) | ((b & 0xFF) << 16) | ((g & 0xFF) << 8) | (r & 0xFF);
    return fromABGR(color);
}

Color Color::fromPaletteIndex(int i) {
    Color color;
    color.format = ColorFormat::PALETTE_INDEX;
    color.palette_index = i;
    return color;
}

Color& Color::asPaletteIndex() {
    if (format == ColorFormat::LIMITED_PALETTE) {
        int c = limited_palette;
        palette_index = ((c / 100) % 10) * 36 + ((c / 10) % 10) * 6 + (c % 10);
        format = ColorFormat::PALETTE_INDEX;
    }

    return *this;
}