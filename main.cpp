#include <iostream>
#include <vector>

// Function to display the game's start screen
void printStartScreen() {
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

// Function for displaying the playing field
void printBoard(const std::vector<char>& board) {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}

// Function to update the playing field after a player's move
bool updateBoard(std::vector<char>& board, int cellNumber, char symbol) {
    if (cellNumber >= 1 && cellNumber <= 9 && board[cellNumber - 1] == ' ') {
      board[cellNumber - 1] = symbol;
      return true;
    } else {
      std::cout << "Invalid move. Please choose an empty cell (1-9).\n";
      return false;
    }
}

// Function to check for empty cells on the playing field
bool hasEmptyCells(const std::vector<char>& board) {
    for (char cell : board) {
      if (cell == ' ') {
        return true;
      }
    }
    return false;
}

// Function to check if a player has won
bool isWin(const std::vector<char>& board, char symbol) {
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

int main() {
    printStartScreen();
    std::cin.get(); // Wait for user to press Enter

    // Clear the console (platform-specific way is recommended)
    #ifdef _WIN32
      system("cls");
    #else
    // Use appropriate command for other platforms
    #endif

    std::vector<char> board(9, ' ');
    char currentPlayer = 'X';

    while (true) {

        printBoard(board);

        if (isWin(board, 'X')) {
            std::cout << "Player X wins!\n";
            break;
        }

        if (isWin(board, 'O')) {
            std::cout << "Player O wins!\n";
            break;
        }

        if (!hasEmptyCells(board)) {
            std::cout << "It's a draw!\n";
            break;
        }

        int cellNumber;
        std::cout << "Player " << currentPlayer << ", enter cell number (1-9): ";
        std::cin >> cellNumber;
        
        if (updateBoard(board, cellNumber, currentPlayer)) {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
