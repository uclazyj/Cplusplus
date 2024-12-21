#include <iostream>
#include "game.h"

using namespace std;

const int ROWS = 15;
const int COLS = 15;

int main(){
    string name1;
    cout << "Player1, please enter your name: ";
    getline(cin, name1);

    string name2;
    cout << "Player2, please enter your name: ";
    getline(cin, name2);

    char token1 = 'X';
    char token2 = 'O';
    Game game = Game(ROWS, COLS, name1, token1, name2, token2);
    game.print_board();
    game.start();
}