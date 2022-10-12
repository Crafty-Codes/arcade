#include "GUI_Paint.h"
#include "storage/Image.h"
#include "spec/Screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int16_t xBird = 60;
int16_t yBird = 59;

void Bird(int key)
{
  if (DEV_Digital_Read(key) == 0 && xBird - 5 >= 0)
  {
    xBird = xBird - 5;
  }
  else if (xBird + 5 <= HEIGHT - 13)
  {
    xBird = xBird + 5;
  }

  Paint_DrawRectangle(xBird, yBird, xBird + 10, yBird + 10, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
}

uint8_t yTube = 0;
uint8_t xTube = 100;

void Tube(void)
{
  ++yTube;
  Paint_DrawRectangle(xTube, yTube, HEIGHT, yTube + 10, BLUE, DOT_PIXEL_1X1, DRAW_FILL_FULL);

  if (yTube + 10 >= 128)
  {
    yTube = 0;
  }
}

bool collisionHandler(void)
{
  return yBird - 10 <= yTube && yBird > yTube && xBird + 10 >= xTube;
}

int main(void)
{
  DEV_Delay_ms(100);
  if (DEV_Module_Init() != 0)
  {
    return -1;
  }

  /* LCD Init */
  LCD_1IN44_Init(0);
  LCD_1IN44_Clear(WHITE);

  // LCD_SetBacklight(1023);
  UWORD Imagesize = WIDTH * HEIGHT * 2;
  UWORD *BlackImage;
  if ((BlackImage = (UWORD *)malloc(Imagesize)) == NULL)
  {
    exit(0);
  }

  // /*1.Create a new image cache named IMAGE_RGB and fill it with white*/
  Paint_NewImage((UBYTE *)BlackImage, WIDTH, HEIGHT, 0, WHITE);
  Paint_SetScale(65);
  Paint_Clear(WHITE);
  Paint_SetRotate(ROTATE_0);
  Paint_Clear(WHITE);

  int key0 = 15;
  int key1 = 17;
  int key2 = 2;
  int key3 = 3;

  SET_Infrared_PIN(key0);
  SET_Infrared_PIN(key1);
  SET_Infrared_PIN(key2);
  SET_Infrared_PIN(key3);

  while (!collisionHandler())
  {
    DEV_Delay_ms(100);
    Paint_Clear(WHITE);

    Bird(key1);

    Tube();

    // Grass
    Paint_DrawRectangle(HEIGHT, 0, HEIGHT - 3, WIDTH, GREEN, DOT_PIXEL_1X1, DRAW_FILL_FULL);

    LCD_1IN44_Display(BlackImage);
  }
  return 0;
}
