#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic Tac Toe board
void displayBoard(const vector<vector<char> >& board) {
    cout << "-------------" << endl;
    for (size_t i = 0; i < board.size(); ++i) {
        cout << "| ";
        for (size_t j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char> >& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (size_t i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full
bool boardFull(const vector<vector<char> >& board) {
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to play the game
void playGame() {
    vector<vector<char> > board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    char currentPlayer = 'X';

    while (true) {
        displayBoard(board);

        // Get the row and column from the current player
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Place the player's symbol on the board
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if the board is full (tie)
        if (boardFull(board)) {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    playGame();
    return 0;
}

