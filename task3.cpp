#include <iostream>

char board[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void displayBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << " | " << board[i][j];
        }
        std::cout << " | " << std::endl;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
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

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (isdigit(board[i][j])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int turn = 1;
    bool win = false;
    bool draw = false;
    char move;

    do {
        displayBoard();
        std::cout << "Player " << turn % 2 + 1 << ", enter your move: ";
        std::cin >> move;

        if (isdigit(move)) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == move) {
                        board[i][j] = turn % 2 == 0 ? 'X' : 'O';
                        turn++;
                        goto makeMove;
                    }
                }
            }
        }

        std::cout << "Invalid move, please try again." << std::endl;
        continue;

        makeMove:
        win = checkWin();
        draw = checkDraw();

        if (win) {
            displayBoard();
            std::cout << "Player " << turn % 2 + 1 << " wins!" << std::endl;
            break;
        }

        if (draw) {
            displayBoard();
            std::cout << "It's a draw!" << std::endl;
            break;
        }

    } while (true);

    std::cout << "Do you want to play again? (y/n): ";
    char playAgain;
    std::cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = i * 3 + j + 49;
            }
        }
        main();
    }

    return 0;
}