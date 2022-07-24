#include "gyms.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

Gyms::Gyms(int position, string blockName, vector<shared_ptr<Tile>> board) : Tile{blockName, true, false, position, 150, board} {}

Gyms::~Gyms() {}

void Gyms::action(std::shared_ptr<Player> player) {
    // Daniel: I fucked up and added gym logic to residence cuz mimss jym
    // else {
    //     int gymCount = 0;
    //     std::vector<std::shared_ptr<Tile>> listOfOwner = getOwner()->getTiles();
    //     if (find(listOfOwner.begin(), listOfOwner.end(), "PAC") != listOfOwner.end()) {
    //         gymCount += 1;
    //     }
    //     if (find(listOfOwner.begin(), listOfOwner.end(), "CIF") != listOfOwner.end()) {
    //         gymCount += 1;
    //     }
        
    //     cout << "This gym is owned by" << getOwner() << ". Since " << getOwner() << "has " << gymCount << " properties,  you must pay $" 
    //     << PRICEOFTHEPAYMENT << endl;
    // }
}

