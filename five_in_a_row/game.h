#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "player.h"

using namespace std;

class Game {
public:
    Game(int nRows, int nCols, string name1, char token1, string name2, char token2);

    void print_board();

    bool play(int row, int col, Player player);

    // Retract a previous move
    void undo();

    void start();

    // Return the index of row and column
    pair<int, int> get_coord();

private:
    vector<vector<char>> board_;
    const int nRows_;
    const int nCols_;
    vector<Player> players_;
    vector<pair<int, int>> history_;
};

#endif