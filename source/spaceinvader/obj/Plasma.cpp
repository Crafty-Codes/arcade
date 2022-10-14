#include "Plasma.h"

Plasma::Plasma(uint8_t _x, uint8_t _y, uint8_t _height, uint8_t _width)
    : x(_x), y(_y), HEIGHT(_height), WIDTH(_width) {}

uint8_t Plasma::getX() { return x; }
uint8_t Plasma::getY() { return y; }

void Plasma::moveUp(uint8_t _move) { y -= _move; }