#include <iostream>

using namespace std;


const int MAX_ROWS = 19;
const int MAX_COLS = 19;

class Player {
private:
    string name_;
    char token_;
    bool win_;
};

class Game {
public:
    Game(int nRows, int nCols):board_(nRows, vector<char>(nCols, '.')), nRows_(nRows), nCols_(nCols){}

    void print_board(){
        cout << endl;
        cout << "  ";
        for (int j = 0; j < nCols_; ++j){
            cout << j+1 << " ";
        }
        cout << endl;
        for (int i = 0; i < nRows_; ++i){
            cout << i+1 << " ";
            for (int j = 0; j < nCols_; ++j){
                cout << board_[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Return the index of row and column
    pair<int, int> get_coord(){
        while (true){
            int row;
            int col;
            cout << "Please input the row and column: " << endl;
            cin >> row >> col;
            row--;
            col--;
            if (row >= 0 && row < nRows_ && col >= 0 && col < nCols_ && board_[row][col] == '.'){
                return {row, col};
            }
            cout << "Invalid move. " << endl;
        }
    }

private:
    vector<vector<char>> board_;
    const int nRows_;
    const int nCols_;

};

int main(){
    // Ideally comes from user input
    int nRows = 9;
    int nCols = 9;
    Game game = Game(nRows, nCols);
    game.print_board();
    pair<int,int> coord = game.get_coord();
    cout << "(" << coord.first << "," << coord.second << ")" << endl;

}