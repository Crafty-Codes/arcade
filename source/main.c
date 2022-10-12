#include "GUI_Paint.h"
#include "storage/Image.h"
#include "screen/Screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "obj/ObjHandler.h"
#include "screen/Scoarboard.h"

int main(void)
{
  initDisplay();

  while (1)
  {

    while (!collisionHandler())
    {
      DEV_Delay_ms(100);
      Paint_Clear(WHITE);

      Bird(key1);

      Tube();

      // Grass
      Paint_DrawRectangle(0, HEIGHT - 3, WIDTH, HEIGHT, GREEN, DOT_PIXEL_1X1, DRAW_FILL_FULL);
      showScore();

      LCD_1IN44_Display(BlackImage);
    }

    Paint_DrawString_EN(13, 25, "GAME OVER", &Font16, WHITE, BLACK);
    showHighscore();
    LCD_1IN44_Display(BlackImage);

    if (DEV_Digital_Read(key2) == 0)
    {
      objReset();
    }
  }

  return 0;
}
