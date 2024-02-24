#include <iostream>
#include <cstdlib>

// Function to display the start screen of the game
void printStartScreen() {
    std::cout << 
    "           Tic Tac Toe           \n\n" <<
    "Rules:\n" <<
    "Two players take turns marking spaces in a 3x3 grid.\n" <<
    "The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.\n" <<
    "If no player can achieve three marks in a row, the game ends in a tie.\n\n" <<
    "The game board is numbered as follows:\n" <<
    "1|2|3|\n" <<
    "4|5|6|\n" <<
    "7|8|9|\n\n" <<
    "To make a move, enter the corresponding cell number.\n\n"
    "Press any key to start the game...";
}

int main() {
    printStartScreen();

    if (std::cin.get()) {
        std::system("cls");
    } // Waiting for a keystroke before starting the game
    
    return 0;
}
