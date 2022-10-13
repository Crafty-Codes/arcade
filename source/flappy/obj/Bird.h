#include "stdint.h"
#include "Screen.h"
#include "GUI_Paint.h"

int16_t xBird = 59;
int16_t yBird = 60;

uint8_t speed = 5;
double jumpStrength = 2;

bool isJumping = false;

void Bird(const int *key)
{
 
  if (jumpStrength != 2 && jumpStrength > 0.25 && isJumping && yBird - speed - 2 > 0)
  {
    yBird -= speed * jumpStrength;
    jumpStrength /= 1.5;
  }
  else if (DEV_Digital_Read(*key) == 0 && !isJumping && jumpStrength > 0.25 && yBird - speed - 2 > 0)
  {
    jumpStrength = 2;
    isJumping = true;
    yBird -= speed * jumpStrength;
    jumpStrength /= 1.5;
  }
  else if (yBird <= 128 - 13)
  {
    isJumping = false;
    if (jumpStrength < 2)
    {
      jumpStrength *= 2.25;
    }
    if (speed * jumpStrength + yBird >= 128 - 13)
    {
      yBird = 128 - 13;
    }
    else
    {
      yBird += speed * jumpStrength;
    }
  }
  

  Paint_DrawRectangle(xBird, yBird, xBird + 10, yBird + 10, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
}