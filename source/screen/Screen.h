#ifndef _SCREEN_H_
#define _SCREEN_H_
#include "stdint.h"

#define SCREENWIDTH 128
#define SCREENHEIGHT 128

extern const int key0;
extern const int key1;
extern const int key2;
extern const int key3;

extern uint16_t *BlackImage;

int initDisplay(void);

#endif