#include "player.h"
using namespace std;

Player::Player(std::string name, char piece, int money = 1500, int pos = 0) : name{name}, piece{piece}, money{money},
pos{pos}, bankrupt{false}, rollUpCount{0}, isInJail{false}, inJailCounter{0}, tilesOwned{} {}

void Player::move(int n) {
    pos += n;
    if (pos >= 40) {
        pos -= 40;
        // if tile is not dcTimsLine, collect $200 from OSAP (maybe could check this in play tho)
    }
}

void Player::getMoney() {
    return money;
}

void Player::addMoney(int n) {
    if (n < 0) {
        cout << "You can't add a value that is less than 0. Enter a valid command." << endl;
    } else {
        money += n;
        cout << "You have succesfully added $" << n << " to your account. You now have $" << money << endl;
    }
}

void Player::subtractMoney(int n, vector<shared_ptr<Player*>> players) {
    if (n >= money) {
        money -= n;
        cout << "You have successfully subtracted $" << n << " fron your account. You now have $" << money << endl;
    } else {
        bankruptcy(n - money, players);
    }
}

void Player::declareBankruptcy() {

}

void Player::bankruptcy(int owed, vector<shared_ptr<Player*>> players) {
    cout << 
}

int Player::getRollUpCount() {
    return rollUpCount;
}

void Player::addRollUpCount() {
    rollUpCount++;
}

void Player::useRollUpCount() {
    rollUpCount--;
}

void Player::displayAssets() {
    cout << "Here are " << getName() << "'s current assets." << endl;

    cout << "Money: " << getMoney() << endl;
    cout << "Tim Cups: " << getRollUpCount() << end;
    cout << endl << "Properties:" << endl;

    std::vector<shared_ptr<tile*>> myTiles = getTiles();
    int size = myTiles.size();
    for (int i = 0; i < size; i++) {
        cout << myTiles[i]->getName() << ": " << myTiles[i]->getPrice() << "\t Improvements: " << myTiles[i]->getImprovementNum() << endl;
    }
}

string Player::getName() {
    return name;
}

int Player::getPos() {
    return pos;
}

void Player::setPos(int n) {
    pos = n;
}

bool Player::getJailStatus() {
    return isInJail;
}
void Player::setJailStatus(bool status) {
    isInJail = status;
}

int Player::getJailCount() {
    return inJailCounter;
}

void Player::setJailCount(int n) {
    inJailCounter = n;
}

void Player::addTile(tile t) {
    tilesOwned.emplace_back(t);
}

std::vector<shared_ptr<tile*>> Player::getTiles() {
    return tilesOwned;
}