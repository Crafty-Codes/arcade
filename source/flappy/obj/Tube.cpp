#include "Tube.h"
#include "../screen/Screen.h"
#include "../storage/Scoreboard.h"
#include "../util/Random.h"

extern "C"{
#include "../lib/GUI/GUI_Paint.h"
}

uint8_t yTube = 100;
uint8_t xTube = 128;

void Tube(void)
{
  --xTube;
  Paint_DrawRectangle(xTube - 10, yTube, xTube, SCREENHEIGHT, BLUE, DOT_PIXEL_1X1, DRAW_FILL_FULL);

  if (xTube <= 1)
  {
    yTube = getRandom(48, 120);
    xTube = SCREENWIDTH;
    score++;
  }
}