#include "GUI_Paint.h"
#include "storage/Image.h"

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
  UDOUBLE Imagesize = 128 * 128 * 2;
  UWORD *BlackImage;
  if ((BlackImage = (UWORD *)malloc(Imagesize)) == NULL)
  {
    exit(0);
  }

  
  // /*1.Create a new image cache named IMAGE_RGB and fill it with white*/
  Paint_NewImage((UBYTE *)BlackImage, 128, 128, 0, WHITE);
  Paint_SetScale(65);
  Paint_Clear(WHITE);
  Paint_SetRotate(ROTATE_0);
  Paint_Clear(WHITE);

  int i, j, x = 0;
  for (j = 0; j < 128; j++)
  {
    for (i = 0; i < 128; i++)
    {
      Paint_SetPixel(i, j, mario[x++]);
    }
  }

  LCD_1IN44_Display(BlackImage);

  while (true)
  {
  }

  return 0;
}
