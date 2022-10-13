#include "Scoreboard.h"
#include <stdint.h>
#include "../GUI/GUI_Paint.h"

uint8_t highscore = 0;
uint8_t score = 0;

void showScore(void)
{
    char sc[255];

    sprintf(sc, "score: %d", score);

    Paint_DrawString_EN(5, 5, sc, &Font12, WHITE, BLACK);
}

void showHighscore(void)
{
    if (score > highscore)
    {
        highscore = score;
    }

    char sc[255];

    sprintf(sc, "highscore: %d", highscore);

    Paint_DrawString_EN(64-Font12.Width*7, 58, sc, &Font12, WHITE, BLACK);
}