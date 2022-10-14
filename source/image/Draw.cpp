#include "Draw.h"
extern "C" {
#include "GUI_Paint.h"
}

void DrawImage(const uint16_t *image) {
  int i, j, x = 0;
  for (j = 0; j < 128; j++) {
    for (i = 0; i < 128; i++) {
      Paint_SetPixel(i, j, image[x++]);
    }
  }
}

void DrawSelect(int pos) {
  uint8_t xStart, yStart;
  int x = 0;

  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {

      if (pos + 1 == x) {
        break;
      } else {
        xStart = 32 * j;
        yStart = 32 * i;
        ++x;
      }
    }
  }

  Paint_DrawRectangle(xStart, yStart, xStart + 32, yStart + 32, BLACK,
                      DOT_PIXEL_2X2, DRAW_FILL_EMPTY);
}