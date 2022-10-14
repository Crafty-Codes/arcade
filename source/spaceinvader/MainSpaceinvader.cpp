#include "MainSpaceinvader.h"
#include "../screen/Screen.h"
#include "obj/Alien.h"
#include "obj/Shuttle.h"

extern "C" {
#include "GUI_Paint.h"
#include "LCD_1in44.h"
}

void MainSpaceinvader::createAliens(void) {
  for (size_t x = 0; x < sizeof(aliens) / sizeof(aliens[0]); x++) {
    for (size_t y = 0; y < sizeof(aliens[0]) / sizeof(aliens[0][0]); y++) {
      if (y % 2) {
        aliens[x][y] = Alien((x * 20 + 20), (y * 20 + 10), 5);

      } else {
        aliens[x][y] = Alien((x * 20 + 10), (y * 20 + 10), 5);
      }
    }
  }
}

void MainSpaceinvader::handleAliens(void) {
  bool changeDirection = false;
  for (size_t x = 0; x < sizeof(aliens) / sizeof(aliens[0]); x++) {
    for (size_t y = 0; y < sizeof(aliens[0]) / sizeof(aliens[0][0]); y++) {
      if (direction == RIGHT) {
        aliens[x][y].moveX(1);
      } else {
        aliens[x][y].moveX(-1);
      }

      if (down) {
        aliens[x][y].moveY(1);
      }

      if (aliens[x][y].getX() == SCREENWIDTH - aliens[x][y].getRadius() ||
          aliens[x][y].getX() == aliens[x][y].getRadius()) {
        changeDirection = true;
      }

      Paint_DrawCircle(aliens[x][y].getX(), aliens[x][y].getY(),
                       aliens[x][y].getRadius(), BLUE, DOT_PIXEL_1X1,
                       DRAW_FILL_FULL);
    }
  }
  down = false;
  if (changeDirection) {
    if (direction == RIGHT) {
      direction = LEFT;
    } else {
      down = true;
      direction = RIGHT;
    }
  }
}

void MainSpaceinvader::autoShoot() {
  if (++timer % 30 == 0) {
    shoots[(timer / 30) - 1].setPos((shuttleX + 4), shuttleY);
    if (timer == 150) {
      timer = 29;
    }
  }

  for (auto &&i : shoots) {
    if (i.getY() == 1) {
      i.setPos(SCREENWIDTH, SCREENHEIGHT);
    } else if (i.getY() != SCREENHEIGHT) {
      i.moveUp(1);
      Paint_DrawRectangle(i.getX(), i.getY(), i.getX() + i.WIDTH,
                          i.getY() + i.HEIGHT, RED, DOT_PIXEL_1X1,
                          DRAW_FILL_FULL);
    }
  }
}

MainSpaceinvader::MainSpaceinvader() {}

void MainSpaceinvader::executeSpaceinvader() {
  createAliens();

  while (1) {
    Paint_Clear(BLACK);

    handleAliens();

    handleShuttle();

    autoShoot();

    DEV_Delay_ms(50);

    LCD_1IN44_Display(BlackImage);
  }
}
