#include "Bird.h"
#include "Tube.h"

bool collisionHandler(void)
{
  return xBird + 10 >= xTube - 10 && xBird <= xTube && yBird + 10 >= yTube;
}

void objReset(void)
{
  xBird = 59;
  yBird = 60;
  yTube = 100;
  xTube = SCREENWIDTH;
  score = 0;
}