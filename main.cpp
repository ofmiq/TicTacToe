#include "game.h"
#include <iostream>

int main() {
    Game game;
    game.printStartScreen();
    std::cin.get(); // Wait for user to press Enter

    // Clear the console (platform-specific way is recommended)
    #ifdef _WIN32
      system("cls");
    #else
    // Use appropriate command for other platforms
      std::system("clear");
    #endif

    while (true) {
        game.printBoard();

        if (game.isWin('X')) {
            std::cout << "Player X wins!\n";
            break;
        }

        if (game.isWin('O')) {
            std::cout << "Player O wins!\n";
            break;
        }

        if (!game.hasEmptyCells()) {
            std::cout << "It's a draw!\n";
            break;
        }

        int cellNumber;
        std::cout << "Player " << game.getCurrentPlayerSymbol() << ", enter cell number (1-9): ";
        std::cin >> cellNumber;
        
        if (game.updateBoard(cellNumber)) {
            game.switchPlayer();
        }
    }

    return 0;
}
