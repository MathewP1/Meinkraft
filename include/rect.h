//
// Created by mateusz on 12/6/21.
//

#include <cstdint>

#ifndef MEINKRAFT_RECT_H
#define MEINKRAFT_RECT_H

class Rect {
public:
    Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
    uint32_t x, y, w, h;
};

#endif //MEINKRAFT_RECT_H
