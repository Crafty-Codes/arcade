#pragma once
#include <stdint.h>

class Alien
{
private:
    uint8_t x;
    uint8_t y;
    uint8_t radius;
public:
    Alien();
    Alien(uint8_t _x, uint8_t _y, uint8_t _radius);

    uint8_t getX();
    uint8_t getY();
    uint8_t getRadius();

    void moveX(uint8_t _x);
    void moveY(uint8_t _y);
};