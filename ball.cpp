#include <ncurses.h>
#include "ball.h"

Ball::Ball(int row, int col, Direction dir, Color color)
{
    this->row = row;
    this->col = col;
    this->dir = dir;
    this->color = color;
}

void Ball::move()
{
    this->clear();
    // Naive approach to moving the ball
    // Current configuration does not account
    // for any sort of collision
    switch (dir)
    {
        case DOWNLEFT:
            row++;
            col--;
            break;
        case UPLEFT:
            row--;
            col--;
            break;
        case UPRIGHT:
            row--;
            col++;
            break;
        case DOWNRIGHT:
            row++;
            col++;
            break;
    }
    this->draw();
    return;
}

void Ball::draw()
{
    attron(COLOR_PAIR(color));
    mvprintw(row, col, "B");
    attroff(COLOR_PAIR(color));
    return;
}

void Ball::clear()
{
    attron(COLOR_PAIR(BLACK));
    mvprintw(row, col, " ");
    attroff(COLOR_PAIR(BLACK));
}
