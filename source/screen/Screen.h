#pragma once
#include "stdint.h"
#include "../GUI/GUI_Paint.h"

void LCD_1IN44_Init(uint8_t Scan_dir);
void LCD_1IN44_Clear(int Color);
void SET_Infrared_PIN(uint8_t PIN);
void *malloc(size_t __size);
void exit(int status);

static const uint8_t WIDTH = 128;
static const uint8_t HEIGHT = WIDTH;

int key0 = 15;
int key1 = 17;
int key2 = 2;
int key3 = 3;

uint16_t *BlackImage;

int initDisplay(void)
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