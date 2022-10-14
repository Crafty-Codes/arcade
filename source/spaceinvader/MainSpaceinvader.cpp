#include "MainSpaceinvader.h"
#include "../screen/Screen.h"
#include "obj/Alien.h"
#include "obj/Shuttle.h"

extern "C" {
#include "GUI_Paint.h"
#include "LCD_1in44.h"
}

void MainSpaceinvader::createAliens(void) {
  for (size_t x = 0; x < sizeof(arr) / sizeof(arr[0]); x++) {
    for (size_t y = 0; y < sizeof(arr[0]) / sizeof(arr[0][0]); y++) {
      if (y % 2) {
        arr[x][y] = Alien((x * 20 + 20), (y * 20 + 10), 5);

      } else {
        arr[x][y] = Alien((x * 20 + 10), (y * 20 + 10), 5);
      }
    }
  }
}

void MainSpaceinvader::handleAliens(void) {
  bool changeDirection = false;
  for (size_t x = 0; x < sizeof(arr) / sizeof(arr[0]); x++) {
    for (size_t y = 0; y < sizeof(arr[0]) / sizeof(arr[0][0]); y++) {
      if (direction == RIGHT) {
        arr[x][y].moveX(1);
      } else {
        arr[x][y].moveX(-1);
      }

      if (arr[x][y].getX() == SCREENWIDTH - arr[x][y].getRadius() ||
          arr[x][y].getX() == arr[x][y].getRadius()) {
        changeDirection = true;
      }

      Paint_DrawCircle(arr[x][y].getX(), arr[x][y].getY(),
                       arr[x][y].getRadius(), BLUE, DOT_PIXEL_1X1,
                       DRAW_FILL_FULL);
    }
  }
  if (changeDirection) {
    if (direction == RIGHT) {
      direction = LEFT;
    } else {
      direction = RIGHT;
    }
  }
}

void MainSpaceinvader::autoShoot() {
  for (auto &i : shoots) {
    i->moveUp(1);
    Paint_DrawRectangle(i->getX(), i->getY(), i->getX() + 10, i->getY() + 10,
                        RED, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    if (i->getY() == 0) {
      shoots.pop_front();
    }
  }
}

MainSpaceinvader::MainSpaceinvader() {}

void MainSpaceinvader::executeSpaceinvader() {
  createAliens();
  shoots.emplace_back(new Plasma(shuttleX + 4, shuttleY, 5, 2));

  while (1) {
    Paint_Clear(BLACK);

    handleAliens();

    handleShuttle();

    autoShoot();

    DEV_Delay_ms(100);

    LCD_1IN44_Display(BlackImage);
  }
}
