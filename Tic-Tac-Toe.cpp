#include<iostream>
using namespace std;

char board[3][3];  // 3x3 grid
char currentPlayer;

void initializeBoard() {
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            board[i][j] = '1' + i*3 + j;  // fill with 1-9
}

void printBoard() {
    cout << "\n";
    for(int i = 0; i < 3; ++i) {
        cout << " ";
        for(int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        if(i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

bool placeMark(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkForWin() {
    // Rows & Columns
    for(int i = 0; i < 3; ++i) {
        if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if(board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    // Diagonals
    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool checkForDraw() {
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char playAgain;
    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        cout << "\n===========================\n";
        cout << "      TIC-TAC-TOE GAME\n";
        cout << "===========================\n";

        while(!gameOver) {
            printBoard();
            int move;
            cout << "\nPlayer " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if(move < 1 || move > 9 || !placeMark(move)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            if(checkForWin()) {
                printBoard();
                cout << "\nPLAYER " << currentPlayer << " WINS!\n";
                gameOver = true;
            }
            else if(checkForDraw()) {
                printBoard();
                cout << "\nIt's a draw!\n";
                gameOver = true;
            }
            else {
                switchPlayer();
            }
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing Tic-Tac-Toe!\n";

    return 0;
}

