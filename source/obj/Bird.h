#include "stdint.h"
#include "../screen/Screen.h"
#include "../lib/GUI/GUI_Paint.h"

int16_t xBird = 59;
int16_t yBird = 60;

void Bird(int key)
{
  if (DEV_Digital_Read(key) == 0 && yBird > 0)
  {
    yBird -= 5;
  }
  else if (yBird + 5 <= HEIGHT - 13)
  {
    yBird += 5;
  }

  Paint_DrawRectangle(xBird, yBird, xBird + 10, yBird + 10, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
}