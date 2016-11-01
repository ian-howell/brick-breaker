#include <ncurses.h>
#include "player.h"

Player::Player(int row, int col, Color color)
{
    this->width = 11;
    this->color = color;
    this->row = row;
    this->col = (col - (this->width / 2));
}

void Player::move(Direction dir)
{
    int new_col = col;
    if (dir == LEFT)
        new_col -= 3;
    else if (dir == RIGHT)
        new_col += 3;

    make_valid(new_col);
    this->clear();
    col = new_col;
    this->draw();

    return;
}

void Player::make_valid(int& c)
{
    if (c < 0)
        c = 0;
    if (c > (COLS - width))
        c = (COLS - width);
    return;
}

void Player::draw()
{
    attron(COLOR_PAIR(color));
    for (int i = col; i < (width + col); i++)
        mvprintw(row, i, "P");
    attroff(COLOR_PAIR(color));
}

void Player::clear()
{
    attron(COLOR_PAIR(BLACK));
    for (int i = col; i < (width + col); i++)
        mvprintw(row, i, " ");
    attroff(COLOR_PAIR(BLACK));
}
