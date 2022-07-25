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
    const int osapPos = 0;
    const int jailPos = 10;
    const int goToJailPos = 30;
    const int numSquares = 40;
    bool isTurnOver = false;
    int rollUpCount = 0;
    int playersCount = 0;
    std::vector<std::shared_ptr<Tile>> board;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::string> pieces = {"G: Goose", "B: GRT Bus", "D: Tim Hortons Doughnut", "P: Professor", "S: Student", "M: Money", "L: Laptop", "T: Pink Tie"};
    const std::vector<int> ownableSquares = {1, 3, 5, 6, 8, 9, 11, 12, 13, 14, 15, 16, 18, 19, 21, 
    23, 24, 25, 26, 27, 28, 29, 31, 32, 34, 35, 37, 39};
public:
    Board();
    virtual ~Board();
    void trade(std::vector<std::string> commands, int currPlayerIndex);
    std::vector<std::shared_ptr<Player>> getPlayers();
    std::vector<std::shared_ptr<Tile>> getTiles();
    void loadGame(std::string fileName);
    void saveGame(std::string fileName, int index);
    void init(int input); 
    void initTiles();
    void play();
    std::vector<int> rollDice();        // maybe virtual // maybe virtual
    void setTestingMode();
    virtual void print(); // calls board display
    bool hasMonopoly(std::shared_ptr<Tile> currTile);
    int getRollUpCount();
    void setRollUpCount(int n);
};

#endif
