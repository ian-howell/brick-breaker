#include <ncurses.h>
#include "player.h"
#include "helpers.h"

int main()
{
    int rows;
    int cols;
    initscr();
    /* start_color(); */
    init_colors();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    // Get the screen dimensions
    getmaxyx(stdscr, rows, cols);

    Player* player = new Player(rows - 2, cols / 2);
    player->draw(WHITE);
    refresh();

    int c;
    bool done = false;
    while (!done)
    {
        c = wgetch(stdscr);
        switch (c)
        {
            case KEY_LEFT:
                player->move(LEFT);
                break;
            case KEY_RIGHT:
                player->move(RIGHT);
                break;
            case 'q':
                done = true;
                break;
        }
        refresh();
    }

    endwin();
    delete player;

    return 0;
}
