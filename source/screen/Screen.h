#ifndef _SCREEN_H_
#define _SCREEN_H_
#include "stdint.h"

extern const uint8_t SCREENWIDTH;
extern const uint8_t SCREENHEIGHT;

extern const int key0;
extern const int key1;
extern const int key2;
extern const int key3;

extern uint16_t *BlackImage;  

int initDisplay(void);

#endif