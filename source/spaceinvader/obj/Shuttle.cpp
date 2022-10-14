#include "Shuttle.h"
#include "Plasma.h"

extern "C" {
#include "DEV_Config.h"
#include "GUI_Paint.h"
#include "Screen.h"
}

uint8_t shuttleX = SCREENWIDTH / 2;
uint8_t shuttleY = SCREENHEIGHT - 20;

void handleShuttle() {
  if (DEV_Digital_Read(key1) == 0) {
    if (shuttleX != 0) {
      shuttleX -= 1;
    }
  }
  if (DEV_Digital_Read(key2) == 0) {
    if (shuttleX + 10 != SCREENWIDTH) {
      shuttleX += 1;
    }
  }
  if (DEV_Digital_Read(key3) == 0) {
  }

  Paint_DrawRectangle(shuttleX, shuttleY, shuttleX + 10, shuttleY + 10, GREEN,
                      DOT_PIXEL_1X1, DRAW_FILL_FULL);
}