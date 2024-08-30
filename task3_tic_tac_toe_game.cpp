#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void printBoard() {
	
    cout << "Game Board       Reference Grid" << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "         1 | 2 | 3 " << endl;
    cout << "---|---|---       ---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "         4 | 5 | 6 " << endl;
    cout << "---|---|---       ---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "         7 | 8 | 9 " << endl;
}

bool isWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void makeMove(char player) {
    int move;
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> move;
    if (move < 1 || move > 9) {
        cout << "Invalid move. Try again." << endl;
        makeMove(player);
        return;
    }
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    if (board[row][col] != ' ') {
        cout << "Cell already occupied. Try again." << endl;
        makeMove(player);
        return;
    }
    board[row][col] = player;
}

int main() {
	cout << "TASK 3 - TIC-TAC-TOE GAME \n" << endl;
    char currentPlayer = 'X';
    bool playAgain;
    
    do {
        bool gameEnded = false;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = ' ';
            }
        }

        while (!gameEnded) {
            printBoard();
            makeMove(currentPlayer);
            if (isWin(currentPlayer)) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameEnded = true;
            } else if (isDraw()) {
                printBoard();
                cout << "The game is a draw!" << endl;
                gameEnded = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play again? (1 for Yes, 0 for No): ";
        cin >> playAgain;
    } while (playAgain);

    return 0;
}
