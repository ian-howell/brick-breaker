#ifndef PLAYER_H
#define PLAYER_H

typedef unsigned char direction;
enum
{
    LEFT,
    RIGHT,
};

class Player
{
    private:
        int row;
        int col;
        int width;

        bool is_valid(int row);

    public:
        Player(int row, int col);
        void move(direction dir);
};
#endif
