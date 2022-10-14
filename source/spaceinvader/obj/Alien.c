#include "Alien.h"
#include <stdint.h>
#include <stdlib.h>

void Alien__init(Alien *alien, uint16_t x, uint16_t y, uint8_t width, uint8_t height)
{
    alien->x = x;
    alien->y = y;
    alien->width = width;
    alien->height = height;
}

Alien *Alien__create(uint16_t x, uint16_t y, uint8_t width, uint8_t height)
{

    Alien *result = (Alien *)malloc(sizeof(Alien));
    Alien__init(result, x, y, width, height);
    return result;
}

void Alien__destroy(Alien *alien)
{
    if (alien)
    {
        free(alien);
    }
}

uint16_t Alien__x(Alien *alien)
{
    return alien->x;
}

uint16_t Alien__y(Alien *alien)
{
    return alien->y;
}

uint8_t Alien__width(Alien *alien)
{
    return alien->width;
}

uint8_t Alien__height(Alien *alien)
{
    return alien->height;
}

void Alien__moveX(Alien *alien)
{
    alien->x = alien->x+1;
}

void Alien__moveY(Alien *alien)
{
    alien->y = alien->y+1;
}
