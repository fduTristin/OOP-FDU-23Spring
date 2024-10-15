#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <random>
#include <ctime>

using std::cout;
using std::endl;
using std::string;

class Board
{
private:
    struct Net
    {
        string row = "|-----|-----|-----|-----|";
        int number[4][4];
    } net;
    long long score;

public:
    Board();
    long long get_score() const { return score; }
    void print() const;
    void put_number_();
    void put_number();
    void move();
    void move(char c);
    void move_back(char c);
    void combine(char c);
    bool isFull() const;
    bool isOver() const;
    
    /*turn the net to finish the "move""finish"
    function on other sides.*/
    void up_turn();
    void down_turn();
    void right_turn();
};

Board::Board() : score(0)
{
    for (int i = 0; i != 4; ++i)
        for (int j = 0; j != 4; ++j)
            net.number[i][j] = 0;
    put_number_();
    return;
}

string::size_type size(int n)
{
    string::size_type sz = 0;
    while (n != 0)
    {
        sz++;
        n = n / 10;
    }
    return sz;
}

void Board::print() const
{

    for (int i = 0; i != 4; ++i)
    {
        cout << net.row << endl;
        ;
        for (int j = 0; j != 4; ++j)
        {
            if (net.number[i][j])
                cout << "|" << string(2 - size(net.number[i][j]) / 2, ' ') << net.number[i][j] << string(3 + size(net.number[i][j]) / 2 - size(net.number[i][j]), ' ');
            else
                cout << "|     ";
        }
        cout << '|' << endl;
    }
    cout << net.row << endl;
    cout << "Your score: " << get_score() << endl;
    std::cout << "(↑:u) (↓:d) (←:l) (→:r) (quit:q): ";
}

void Board::put_number_()
{

    if (!isFull())
    {
        while (1)
        {
            int a = rand() % 4;
            int b = rand() % 4;
            if (!net.number[a][b])
            {
                net.number[a][b] = 2;
                break;
            }
        }

        while (1)
        {
            int a = rand() % 4;
            int b = rand() % 4;
            if (!net.number[a][b])
            {
                net.number[a][b] = 2;
                break;
            }
        }
    }
}

void Board::put_number()
{

    if (!isFull())
    {
        while (1)
        {
            int a = rand() % 4;
            int b = rand() % 4;
            int n = rand() % 5 == 0 ? 4 : 2;
            if (!net.number[a][b])
            {
                net.number[a][b] = n;
                break;
            }
        }
    }
}

void Board::move()
{
    for (int i = 0; i != 4; ++i)
    {
        for (int n = 0; n != 3; ++n)
        {
            for (int j = 0; j != 3; ++j)
            {
                if (!net.number[i][j])
                {
                    for (int k = j; k != 3; ++k)
                        net.number[i][k] = net.number[i][k + 1];
                    net.number[i][3] = 0;
                }
            }
        }
    }
}

void Board::move(char c)
{
    if (c == 'l')
    {
        move();
    }

    if (c == 'r')
    {
        right_turn();
        move();
    }

    if (c == 'u')
    {
        up_turn();
        move();
    }

    if (c == 'd')
    {
        down_turn();
        move();
    }
}

void Board::move_back(char c)
{
    if (c == 'l')
    {
        move();
    }

    if (c == 'r')
    {
        move();
        right_turn();
    }

    if (c == 'u')
    {
        move();
        up_turn();
    }

    if (c == 'd')
    {
        move();
        right_turn();
        up_turn();
    }
}

void Board::combine(char c)
{
    move(c);
    for (int i = 0; i != 4; ++i)
    {
        for (int j = 0; j != 3; ++j)
        {
            if (net.number[i][j] == net.number[i][j + 1] && net.number[i][j])
            {
                
                net.number[i][j] *= 2;
                score += net.number[i][j];
                net.number[i][j + 1] = 0;
            }
        }
    }
    move_back(c);
}

bool Board::isFull() const
{
    bool flg = 1;
    for (int i = 0; i != 4; ++i)
    {
        for (int j = 0; j != 4; ++j)
        {
            if (!net.number[i][j])
                flg = 0;
        }
    }
    return flg;
}

bool Board::isOver() const
{
    if (!isFull())
        return false;
    else
    {
        bool flg = 1;
        for (int i = 0; i != 4; ++i)
        {
            for (int j = 0; j != 3; ++j)
            {
                if (net.number[i][j] == net.number[i][j + 1] || net.number[j][i] == net.number[j + 1][i])
                {
                    flg = 0;
                }
            }
        }
        return flg;
    }
}

void Board::right_turn()
{
    for (int i = 0; i != 4; ++i)
    {
        int temp;
        temp = net.number[i][0];
        net.number[i][0] = net.number[i][3];
        net.number[i][3] = temp;

        temp = net.number[i][1];
        net.number[i][1] = net.number[i][2];
        net.number[i][2] = temp;
    }
}

void Board::up_turn()
{
    for (int i = 1; i != 6; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j >= 0 && j <= 3 && (i - j) >= 0 && (i - j) <= 3 && j < (i - j))
            {
                int temp = net.number[j][i - j];
                net.number[j][i - j] = net.number[i - j][j];
                net.number[i - j][j] = temp;
            }
        }
    }
}

void Board::down_turn()
{
    up_turn();
    right_turn();
}

#endif