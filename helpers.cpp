#include <ncurses.h>
#include "helpers.h"
void init_colors()
{
    start_color();
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    return;
}
