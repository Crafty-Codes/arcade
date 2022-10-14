#include "flappy/MainFlappy.h"
#include "image/Draw.h"
#include "image/StartScreen.h"
#include "screen/Screen.h"
#include "spaceinvader/MainSpaceinvader.h"
#include "spaceinvader/obj/Plasma.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

extern "C" {
#include "GUI_Paint.h"
#include "LCD_1in44.h"
#include "tusb.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

int main(void) {
  initDisplay();
  // minicom -b 115200 -o -D /dev/ttyACM0
  stdio_init_all();
  uint8_t pos = 0;
  while (1) {
    Paint_Clear(WHITE);

    DrawImage(startscreen);

    DrawSelect(pos);

    LCD_1IN44_Display(BlackImage);

    if (DEV_Digital_Read(key1) == 0) {
      Paint_Clear(BLACK);

      switch (pos) {
      case 0: {
        MainFlappy flappy;
        flappy.executeFlappy();
        break;
      }
      case 1: {
        MainSpaceinvader spaceinvader;
        spaceinvader.executeSpaceinvader();
        break;
      }
      default:
        break;
      }
    } else if (DEV_Digital_Read(key2) == 0) {
      if (pos == 16) {
        pos = 0;
      } else {
        ++pos;
      }
    }
    // DEV_Delay_ms(50);
  }

  return 0;
}
