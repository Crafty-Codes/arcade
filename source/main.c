#include "GUI_Paint.h"
#include "storage/Image.h"
#include "spec/Screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "util/Converter.h"

int key0 = 15;
int key1 = 17;
int key2 = 2;
int key3 = 3;

uint16_t *BlackImage;

void init()
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
  uint16_t Imagesize = WIDTH * HEIGHT * 2;
  if ((BlackImage = (UWORD *)malloc(Imagesize)) == NULL)
  {
    exit(0);
  }

  // /*1.Create a new image cache named IMAGE_RGB and fill it with white*/
  Paint_NewImage((uint8_t *)BlackImage, WIDTH, HEIGHT, 0, WHITE);
  Paint_SetScale(65);
  Paint_Clear(WHITE);
  Paint_SetRotate(ROTATE_270);
  Paint_Clear(WHITE);

  SET_Infrared_PIN(key0);
  SET_Infrared_PIN(key1);
  SET_Infrared_PIN(key2);
  SET_Infrared_PIN(key3);
}

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

bool collisionHandler(void)
{
  return xBird + 10 >= xTube - 10 && xBird <= xTube && yBird + 10 >= yTube;
}

int main(void)
{
  init();
  
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

      LCD_1IN44_Display(BlackImage);
    }

    Paint_DrawString_EN(13, 25, "GAME OVER", &Font16, WHITE, BLACK);
    LCD_1IN44_Display(BlackImage);

    if (DEV_Digital_Read(key2) == 0)
    {
      xBird = 59;
      yBird = 60;
      yTube = 100;
      xTube = WIDTH;
    }
  }

  return 0;
}
