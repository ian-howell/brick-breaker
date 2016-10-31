#ifndef BALL_H
#define BALL_H
#include "helpers.h"

class Ball
{
    private:
        int row;
        int col;
        Direction dir;
        Color color;

        bool is_valid(int row, int col);
        void clear();

    public:
        Ball(int row, int col, Direction dir, Color color);
        void move();
        void draw();
};
#endif
