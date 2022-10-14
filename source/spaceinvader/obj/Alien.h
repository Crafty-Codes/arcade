#ifndef __ALIEN_H
#define __ALEIN_H
#include "stdint.h"

typedef struct Alien
{
    uint16_t x;
    uint16_t y;
    uint8_t width;
    uint8_t height;
}Alien;

void Alien__init(Alien* alien, uint16_t x, uint16_t y, uint8_t width, uint8_t height);

Alien* Alien__create(uint16_t x, uint16_t y, uint8_t width, uint8_t height);

void Alien__destroy(Alien* alien);

uint16_t Alien__x(Alien* alien);
uint16_t Alien__y(Alien* alien);

uint8_t Alien__width(Alien* alien);
uint8_t Alien__height(Alien* alien);

void Alien__moveX(Alien* alien);
void Alien__moveY(Alien* alien);

#endif