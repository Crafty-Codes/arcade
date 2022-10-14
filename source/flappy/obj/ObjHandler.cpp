#include "ObjHandler.h"
#include "Bird.h"
#include "Tube.h"
extern "C"{
#include "Screen.h"
#include "GUI_Paint.h"
#include "../storage/Scoreboard.h"
}

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