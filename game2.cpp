#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int choice;
int player = 1; // By default player 1 starts
int row, col;
char mark;

bool checkWin() {
    // Check rows, columns and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void displayBoard() {
    cout << "\nTic Tac Toe\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n\n";
}

void playerMove() {
    bool validInput = false;
    while (!validInput) {
        if (player == 1) {
            cout << "Player 1 (X), enter a number between 1 and 9: ";
        } else {
            cout << "Player 2 (O), enter a number between 1 and 9: ";
        }
        cin >> choice;

        // Determine row and column from choice
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if the chosen cell is already taken
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move. Try again.\n";
        } else {
            if (player == 1) {
                board[row][col] = 'X';
                player = 2; // Switch to player 2
            } else {
                board[row][col] = 'O';
                player = 1; // Switch to player 1
            }
            validInput = true;
        }
    }
}

int main() {
    while (true) {
        displayBoard();
        playerMove();

        // Check for a win
        if (checkWin()) {
            displayBoard();
            if (player == 2) {
                cout << "Player 1 (X) wins!\n";
            } else {
                cout << "Player 2 (O) wins!\n";
            }
            break;
        }

        // Check for a draw
        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}

