#include <iostream>

using namespace std;


const int MAX_ROWS = 19;
const int MAX_COLS = 19;

class Player {
public:
    Player(string name, char token):name_(name),token_(token){}
    char get_token(){return token_;}
    string get_name(){return name_;}
private:
    string name_;
    char token_;
};

class Game {
public:
    Game(int nRows, int nCols, string name1, char token1, string name2, char token2):
    board_(nRows, vector<char>(nCols, '.')), 
    nRows_(nRows), nCols_(nCols){
        Player player1 = Player(name1, token1);
        Player player2 = Player(name2, token2);
        players_.push_back(player1);
        players_.push_back(player2);
    }

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

    bool play(int row, int col, Player player){
        char token = player.get_token();
        board_[row][col] = token;
        history_.push_back({row, col});
        print_board();
        // win from horizontal
        {
            int length = 1;
            for (int c = col + 1; c < nCols_; ++c){
                if (board_[row][c] == token){
                    length++;
                }
                else{
                    break;
                }
            }
            for (int c = col - 1; c >= 0; --c){
                if (board_[row][c] == token){
                    length++;
                }
                else{
                    break;
                }
            }
            if (length >= 5){
                return true;
            }
        }
        // win from vertical
        {
            int length = 1;
            for (int r = row + 1; r < nRows_; ++r){
                if (board_[r][col] == token){
                    length++;
                }
                else{
                    break;
                }
            }
            for (int r = row - 1; r >= 0; --r){
                if (board_[r][col] == token){
                    length++;
                }
                else{
                    break;
                }
            }
            if (length >= 5){
                return true;
            }
        }
        // win from up right diagonal
        {
            int length = 1;
            // up right
            for (int i = 1; col + i < nCols_ && row - i >= 0; ++i){
                if (board_[row - i][col + i] == token){
                    length++;
                }
                else{
                    break;
                }
            }
            // left down
            for (int i = 1; col - i >= 0 && row + i < nRows_; ++i){
                if (board_[row + i][col - i] == token){
                    length++;
                }
                else{
                    break;
                }
            }
            if (length >= 5){
                return true;
            }
        }
        // win from right down diagonal
        {
            int length = 1;
            // up left
            for (int i = 1; row - i >= 0 && col - i >= 0; ++i){
                if (board_[row - i][col - i] == token){
                    length++;
                }
                else{
                    break;
                }
            }
            // left down
            for (int i = 1; row + i < nRows_ && col + i < nCols_; ++i){
                if (board_[row + i][col + i] == token){
                    length++;
                }
                else{
                    break;
                }
            }
            if (length >= 5){
                return true;
            }
        }
        return false;
    }

    void undo(){
        int length = history_.size();
        if (length == 0){
            return;
        }
        pair<int, int> coord = history_[length-1];
        int row = coord.first;
        int col = coord.second;
        board_[row][col] = '.';
        history_.pop_back();
    }

    void start(){
        while (true) {
            for (int i = 0; i < players_.size(); ++i){
                int row;
                int col;
                while (true){
                    cout << players_[i].get_name() << "'s turn (" << players_[i].get_token() << "):" << endl;
                    pair<int, int> coord = get_coord();
                    row = coord.first;
                    col = coord.second;
                    if (row == -1 && col == -1){
                        undo();
                        undo();
                        print_board();
                    }
                    else{
                        break;
                    }
                }
                
                if (play(row, col, players_[i])){
                    cout << "Congratulations " << players_[i].get_name() << ", you win!" << endl;
                    return;
                }
            } 
        }
    }

    // Return the index of row and column
    pair<int, int> get_coord(){
        while (true){
            int row;
            int col;
            cout << "Please input the row and column: " << endl;
            cin >> row >> col;
            // Special case for reverting a move
            if (row == -1 and col == -1){
                return {-1,-1};
            }
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
    vector<Player> players_;
    vector<pair<int, int>> history_;
};

int main(){
    // Ideally comes from user input
    int nRows = 9;
    int nCols = 9;
    string name1 = "Alice";
    char token1 = 'X';
    string name2 = "Bob";
    char token2 = 'O';
    Game game = Game(nRows, nCols, name1, token1, name2, token2);
    game.print_board();
    game.start();
}