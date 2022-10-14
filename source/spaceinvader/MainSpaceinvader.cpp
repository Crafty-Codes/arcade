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
  bool allDead = true;
  bool changeDirection = false;
  for (size_t x = 0; x < sizeof(aliens) / sizeof(aliens[0]); x++) {
    for (size_t y = 0; y < sizeof(aliens[0]) / sizeof(aliens[0][0]); y++) {
      if (aliens[x][y].life == ALIFE) {
        allDead = false;

        if (aliens[x][y].getY() + aliens[x][y].getRadius() >= shuttleY) {
          status = LOST;
        }

        if (direction == RIGHT) {
          aliens[x][y].moveX(1);
        } else {
          aliens[x][y].moveX(-1);
        }

        if (down) {
          aliens[x][y].moveY(1);
        }

        for (auto &&i : shoots) {
          // X check
          if (i.getX() + i.WIDTH >=
                  aliens[x][y].getX() - aliens[x][y].getRadius() &&
              i.getX() <= aliens[x][y].getX() + aliens[x][y].getRadius()) {
            // Y check
            if (i.getY() <= aliens[x][y].getY() + aliens[x][y].getRadius() &&
                i.getY() + i.HEIGHT >=
                    aliens[x][y].getY() - aliens[x][y].getRadius()) {
              aliens[x][y].life = DEAD;
            }
          }
        }

        if (aliens[x][y].getX() + aliens[x][y].getRadius() >= SCREENWIDTH ||
            aliens[x][y].getX() - aliens[x][y].getRadius() <= 0) {
          changeDirection = true;
        }

        Paint_DrawCircle(aliens[x][y].getX(), aliens[x][y].getY(),
                         aliens[x][y].getRadius(), BLUE, DOT_PIXEL_1X1,
                         DRAW_FILL_FULL);
      }
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

  if (allDead) {
    status = WON;
  }
}

void MainSpaceinvader::autoShoot() {
  timer += 1;
  if (timer % 30 == 0) {
    uint16_t tmp = timer;
    shoots[timer / 30 - 1].setPos((shuttleX + 4), shuttleY);

    if (tmp == 150) {
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
  bool exit = false;
  status = PLAYING;
  for (auto &&i : shoots) {
    i.setPos(SCREENWIDTH, SCREENHEIGHT);
  }
  while (!exit) {
    while (status == PLAYING) {
      Paint_Clear(BLACK);

      handleShuttle();

      autoShoot();

      handleAliens();

      DEV_Delay_ms(50);

      LCD_1IN44_Display(BlackImage);
    }
    if (status == WON) {
      Paint_DrawString_EN(13, 25, "You WON!", &Font16, BLACK, WHITE);
    } else {
      Paint_DrawString_EN(13, 25, "You lost", &Font16, BLACK, WHITE);
    }

    LCD_1IN44_Display(BlackImage);

    if (DEV_Digital_Read(key2) == 0) {
      exit = true;
    } else if (DEV_Digital_Read(key1) == 0) {
      status = PLAYING;
      createAliens();
      for (auto &&i : shoots) {
        i.setPos(SCREENWIDTH, SCREENHEIGHT);
      }
    }
  }
}
