#ifndef PLAYER_H
#define PLAYER_H
#include "helpers.h"

class Player
{
    private:
        int width;
        int row;
        int col;
        Color color;

        bool is_valid(int row);

    public:
        Player(int row, int col, Color color);
        void move(Direction dir);
        void draw();
        void clear();
};
#endif
