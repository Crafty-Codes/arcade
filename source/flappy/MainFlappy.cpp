﻿#include "MainFlappy.h"
#include "storage/Scoreboard.h"
#include "storage/Image.h"
#include "obj/Bird.h"
#include "obj/Tube.h"
#include "obj/ObjHandler.h"

extern "C"{
#include "GUI_Paint.h"
#include "LCD_1in44.h"
#include "Screen.h"
}

void MainFlappy::executeFlappy(void)
{

  bool gameFlappy = true;

  while (gameFlappy)
  {

    double gamespeed = 100;
    while (!collisionHandler())
    {

      DEV_Delay_ms(gamespeed);

      if (gamespeed > 10)
      {
        gamespeed -= 0.1;
      }

      Paint_Clear(WHITE);

      Bird(&key1);

      Tube();

      // Grass
      Paint_DrawRectangle(0, SCREENHEIGHT - 3, SCREENWIDTH, SCREENHEIGHT, GREEN, DOT_PIXEL_1X1, DRAW_FILL_FULL);
      showScore();

      LCD_1IN44_Display(BlackImage);
    }

    Paint_DrawString_EN(13, 25, "GAME OVER", &Font16, WHITE, BLACK);
    showHighscore();
    LCD_1IN44_Display(BlackImage);

    if (DEV_Digital_Read(key2) == 0)
    {
      gameFlappy = false;
      objReset();
    }
    else if (DEV_Digital_Read(key1) == 0)
    {
      objReset();
    }
  }
}
