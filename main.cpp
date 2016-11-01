#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include "player.h"
#include "helpers.h"
#include "ball.h"

int main()
{
    int rows;
    int cols;
    initscr();
    init_colors();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);

    // Get the screen dimensions
    getmaxyx(stdscr, rows, cols);

    Player* player = new Player(rows - 2, cols / 2, WHITE);
    Ball* ball = new Ball(rows / 2, cols / 2, DOWNLEFT, WHITE);
    player->draw();
    ball->draw();
    refresh();

    int c = '\0';
    bool done = false;
    // Wait for the user to hit the spacebar
    char start_msg[] = "Press the spabebar to begin";
    mvprintw(2, (cols / 2) - strlen(start_msg) / 2, start_msg);
    refresh();
    while ((c = getchar()) != ' ');
    clear();
    player->draw();
    ball->draw();
    refresh();
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
        flushinp();
        ball->move();
        refresh();
        usleep(100000);
    }

    endwin();
    delete player;

    return 0;
}
