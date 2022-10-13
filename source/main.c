#include "flappy/MainFlappy.h"
#include "image/Draw.h"
#include "image/StartScreen.h"
#include <stdint.h>

int main(void)
{
  initDisplay();

  uint8_t pos = 0;
  while (1)
  {
    Paint_Clear(WHITE);

    DrawImage(startscreen);

    DrawSelect(pos);

    LCD_1IN44_Display(BlackImage);

    if (DEV_Digital_Read(key1) == 0)
    {
      switch (pos)
      {
      case 0:
        mainFlappy();
        break;

      default:
        break;
      }
    }
    else if (DEV_Digital_Read(key2) == 0)
    {
      if (pos == 16)
      {
        pos = 0;
      }
      else
      {
        ++pos;
      }
    }
  }

  return 0;
}
