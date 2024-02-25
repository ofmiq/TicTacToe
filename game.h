#ifndef GAME_H
#define GAME_H

#include <vector>

class Game {
public:
    Game();
    void printStartScreen() const;
    void printBoard() const;
    bool updateBoard(const int& cellNumber);
    bool hasEmptyCells() const;
    bool isWin(const char& symbol) const;
    char getCurrentPlayerSymbol() const;
    void switchPlayer();
private:
    std::vector<char> board;
    char currentPlayer;
};

#endif // GAME_H
