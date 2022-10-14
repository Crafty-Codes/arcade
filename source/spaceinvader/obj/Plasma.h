#pragma once
#include <stdint.h>

class Plasma {
private:
  uint8_t x;
  uint8_t y;

public:
  const uint8_t HEIGHT;
  const uint8_t WIDTH;
  Plasma();
  Plasma(uint8_t _x, uint8_t _y, uint8_t _height, uint8_t _width);

  void setPos(uint8_t _x, uint8_t _y);
  const uint8_t& getX();
  const uint8_t& getY();

  void moveUp(uint8_t _move);
};
