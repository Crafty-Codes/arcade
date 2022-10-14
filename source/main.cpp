#include <stdlib.h>
#include <stdlib.h>
#include "flappy/MainFlappy.h"
#include "spaceinvader/MainSpaceinvader.h"
#include "screen/Screen.h"

extern "C"{
#include "image/Draw.h"
#include "image/StartScreen.h"
#include "LCD_1in44.h"
#include <stdint.h>
}

int main(void)
{
  initDisplay();

  MainFlappy flappy;
  MainSpaceinvader spaceinvader;

  uint8_t pos = 0;
  while (1)
  {
    Paint_Clear(WHITE);

    DrawImage(startscreen);

    DrawSelect(pos);

    LCD_1IN44_Display(BlackImage);

    if (DEV_Digital_Read(key1) == 0)
    {
        Paint_Clear(BLACK);

      switch (pos)
      {
      case 0:
        flappy.executeFlappy();
        break;
      case 1:
        spaceinvader.executeSpaceinvader();
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
    DEV_Delay_ms(50);
  }

  return 0;
}
