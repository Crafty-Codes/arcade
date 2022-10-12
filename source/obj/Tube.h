#include "stdint.h"
#include "../spec/Screen.h"
#include "../lib/GUI/GUI_Paint.h"

uint8_t yTube = 100;
uint8_t xTube = WIDTH;

void Tube(void)
{
  --xTube;
  Paint_DrawRectangle(xTube - 10, yTube, xTube, HEIGHT, BLUE, DOT_PIXEL_1X1, DRAW_FILL_FULL);

  if (xTube <= 1)
  {
    xTube = WIDTH;
  }
}