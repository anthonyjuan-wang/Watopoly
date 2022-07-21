#ifndef __BOARD_H__
#define __BOARD_H__
#include <string>
#include <vector>
#include <sstream>
#include <memory>

class Tile;
class Player;

class Board
{
private:
    int doubles = 0;
    int osapPos = 0;
    int jailPos = 10;
    int goToJailPos = 30;
    int playerCount;
    std::vector<std::shared_ptr<Tile>> board;
    std::vector<std::shared_ptr<Player>> players;

public:
    Board();
    virtual ~Board();
    void loadGame(std::string input);
    void saveGame(std::string input);
    void init(int input);
    void initTiles();
    void play();
    void tradeGive(Player *p, std::string s, int n);
    void tradeReceive(Player *p, std::string s, int n);
    std::vector<int> rollDice();        // maybe virtual
    std::vector<Player *> getPlayers(); // maybe virtual
    void setTestingMode();
    virtual void print() = 0; // calls board display
};

#endif
