#include "MainSpaceinvader.h"
#include "obj/Alien.h"
#include "obj/Shuttle.h"

extern "C"{
#include "GUI_Paint.h"
#include "LCD_1in44.h"
#include "../screen/Screen.h"
}

void mainSpaceinvader()
{
    while (1)
    {
        Paint_Clear(BLACK);

        shuttleHandle();

        LCD_1IN44_Display(BlackImage);
    }
}
