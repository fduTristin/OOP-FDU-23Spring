#ifndef GAME_H
#define GAME_H

#include"board.h"

struct Game2048 {
    Board* board = new Board;
    Game2048();
    ~Game2048();
    char ask_direction();
    long long get_score() const {return board->get_score();}
    void print() const {board->print();}
    void put_number() {board->put_number();}
    void combine(char c) {board->combine(c);}
    bool isFull() const {return board->isFull();}
    bool isOver() const {return board->isOver();}
};

Game2048::Game2048() {
    cout<<"Welcome to the game of 2048!"<<endl;
    print();
}

Game2048::~Game2048() {
    delete board;
}

char Game2048::ask_direction()
{
    char c;
    std::cin>>c;
    return c;
}


#endif