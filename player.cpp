#include <ncurses.h>
#include "player.h"

Player::Player(int row, int col)
{
    this->row = row;
    this->col = col;
    this->width = 5;
}

void Player::move(direction dir)
{
    int new_row = row;
    if (dir == LEFT)
        new_row--;
    else if (dir == RIGHT)
        new_row++;

    if (is_valid(new_row))
        row = new_row;

    return;
}

bool is_valid(int row)
{
    return (row >= 0 && row < COLS);
}
