//
// Created by mateusz on 12/6/21.
//

#include <cstdint>
#include <iostream>

#ifndef MEINKRAFT_COLOR_H
#define MEINKRAFT_COLOR_H

class Color {
 public:
  Color();
  enum class ColorFormat { ABGR, RGBA, LIMITED_PALETTE, PALETTE_INDEX };
  ColorFormat format;

  union {
    uint32_t abgr;
    uint32_t rgba;
    uint16_t limited_palette;
    uint8_t palette_index;
  };

  // constructors
  static Color fromLimitedPalette(int c);  // coded as 3 decimal digits
  static Color fromLimitedPalette(int r, int g, int b);

  static Color fromRGBA(uint32_t c);
  static Color fromRGBA(int r, int g, int b, int a);

  static Color fromABGR(uint32_t c);
  static Color fromABGR(int a, int b, int g, int r);

  static Color fromPaletteIndex(int i);

  // converters
  Color& asRGBA() { return *this; }
  Color& asABGR() { return *this; }
  Color& asLimitedPalette() { return *this; }
  Color& asPaletteIndex();

  // util
  static uint32_t getSpriteColor(int c0, int c1, int c2, int c3) {
    return ((fromLimitedPalette(c0).asPaletteIndex().palette_index & 0xFF)
            << 24) |
           ((fromLimitedPalette(c1).asPaletteIndex().palette_index & 0xFF)
            << 16) |
           ((fromLimitedPalette(c2).asPaletteIndex().palette_index & 0xFF)
            << 8) |
           (fromLimitedPalette(c3).asPaletteIndex().palette_index & 0xFF);
  }
};

#endif  // MEINKRAFT_COLOR_H
