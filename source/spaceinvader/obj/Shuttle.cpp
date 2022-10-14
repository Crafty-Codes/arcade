#include "Shuttle.h"
extern "C"{
#include "Screen.h"
#include "DEV_Config.h"
#include "GUI_Paint.h"
}

uint8_t shuttleX = SCREENWIDTH / 2;
uint8_t shuttleY = SCREENHEIGHT - 20;

void shuttleHandle()
{
    if (DEV_Digital_Read(key1) == 0)
    {
        shuttleX -= 1;
    }
    if (DEV_Digital_Read(key2) == 0)
    {
        shuttleX += 1;
    }
    if (DEV_Digital_Read(key3) == 0)
    {
    }

    Paint_DrawRectangle(shuttleX, shuttleY, shuttleX + 10, shuttleY + 10, GREEN, DOT_PIXEL_1X1, DRAW_FILL_FULL);
}