#ifndef __BOARD_H__
#define __BOARD_H__
#include <string>
#include <vector>
#include <sstream>
#include <memory>
// #include "tile.h"
// #include "player.h"
class Tile;
class Player;

class Board
{
private:
    int doubles = 0;
    int osapPos = 0;
    int jailPos = 10;
    int goToJailPos = 30;
    int numSquares = 40;
    bool isTurnOver = false;
    int rollUpCount = 0;
    std::vector<std::shared_ptr<Tile>> board;
    std::vector<std::shared_ptr<Player>> players;
public:
    Board();
    virtual ~Board();
    void trade(std::vector<std::string> commands, int currPlayerIndex);
    std::vector<std::shared_ptr<Player>> getPlayers();
    std::vector<std::shared_ptr<Tile>> getBoard();
    void loadGame(std::string input);
    void saveGame(std::string input);
    void init(int input);
    void initTiles();
    void play();
    std::vector<int> rollDice();        // maybe virtual // maybe virtual
    void setTestingMode();
    virtual void print() = 0; // calls board display
    bool hasMonopoly(std::shared_ptr<Tile> currTile);
    int getRollUpCount();
    void setRollUpCount(int n);
};

#endif
