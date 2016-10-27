#include <ncurses.h>
#include "player.h"

Player::Player(int row, int col)
{
    this->width = 11;
    this->row = row;
    this->col = (col - (this->width / 2));
}

void Player::move(Direction dir)
{
    int new_col = col;
    if (dir == LEFT)
        new_col--;
    else if (dir == RIGHT)
        new_col++;

    if (is_valid(new_col))
    {
        draw(BLACK);
        col = new_col;
        draw(WHITE);
    }

    return;
}

bool Player::is_valid(int col)
{
    return (col >= 0 && col < (COLS - width) + 1);
}

void Player::draw(Color color)
{
    attron(COLOR_PAIR(color));
    for (int i = col; i < (width + col); i++)
        mvprintw(row, i, " ");
    attroff(COLOR_PAIR(color));
}
