#include "game.h"
#include <iostream>

Game::Game() : board(9, ' '), currentPlayer('X') {}

void Game::printStartScreen() const {
    std::cout << 
        "      Tic Tac Toe      \n\n" <<
        "Rules:\n" <<
        "Two players take turns marking spaces in a 3x3 grid.\n" <<
        "The player who succeeds in placing three of their marks in a horizontal,\n" <<
        "vertical, or diagonal row wins the game.\n" <<
        "If no player can achieve three marks in a row, the game ends in a tie.\n\n" <<
        "The game board is numbered as follows:\n" <<
        " 1 | 2 | 3\n" <<
        "---|---|---\n" <<
        " 4 | 5 | 6\n" <<
        "---|---|---\n" <<
        " 7 | 8 | 9\n\n" <<
        "To make a move, enter the corresponding cell number.\n\n"
        "Press Enter to start the game...";
}

void Game::printBoard() const {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}

bool Game::updateBoard(const int& cellNumber) {
    if (cellNumber >= 1 && cellNumber <= 9 && board[cellNumber - 1] == ' ') {
        board[cellNumber - 1] = currentPlayer;
        return true;
    } else {
        std::cout << "Invalid move. Please choose an empty cell (1-9).\n";
        return false;
    }
}

bool Game::hasEmptyCells() const {
    for (char cell : board) {
        if (cell == ' ') {
            return true;
        }
    }
    return false;
}

bool Game::isWin(const char& symbol) const {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[i * 3] == symbol && board[i * 3 + 1] == symbol && board[i * 3 + 2] == symbol) {
            return true;
        }
    }

    // Check diagonals
    if (board[0] == symbol && board[4] == symbol && board[8] == symbol) {
        return true;
    }

    if (board[2] == symbol && board[4] == symbol && board[6] == symbol) {
        return true;
    }

    return false;
}

char Game::getCurrentPlayerSymbol() const {
    return currentPlayer;
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
