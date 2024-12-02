#include <iostream>
#include <vector>

using namespace std;

// Function to print the game board
void printBoard(const vector<vector<char> >& board) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char> >& board, char player) {
    // Check rows, columns and diagonals
    for (int i = 0; i < 3; i++) {
        // Check row
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        // Check column
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')  // If there's any empty space, it's not a draw
                return false;
        }
    }
    return true;
}

// Function to get a valid move from the player
void getValidMove(vector<vector<char> >& board, char player) {
    int move;
    while (true) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        
        // Convert the move to a row and column
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Check if the move is valid (empty space)
        if (move < 1 || move > 9 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
        } else {
            board[row][col] = player;
            break;
        }
    }
}

// Function to play the game
void playGame() {
    vector<vector<char> > board(3, vector<char>(3, ' ')); // Create an empty 3x3 board
    char currentPlayer = 'X';  // Player 'X' starts

    while (true) {
        printBoard(board);  // Display the current board

        getValidMove(board, currentPlayer);  // Get a valid move from the current player

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            printBoard(board);  // Display the final board
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if the game is a draw
        if (checkDraw(board)) {
            printBoard(board);  // Display the final board
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();  // Restart the game
    }
}

int main() {
    playGame();  // Start the game
    return 0;
}
