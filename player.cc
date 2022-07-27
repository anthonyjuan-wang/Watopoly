#include "player.h"
#include "playerImpl.h"
#include <string>
#include <iostream>
#include <memory>
#include <iomanip>
using namespace std;

/*
Player::Player(string name, char piece, int money = 1500, int pos = 0) :
impl {new PlayerImpl{name, piece, money, pos, false, false, 0, false, 0, 0}} {}
*/

Player::Player(string name, char piece, int money , int pos, int rollup) : impl{make_shared<PlayerImpl>()}{ 
    impl->name = name;
    impl->piece = piece;
    impl->money = money;
    impl->pos = pos;
    impl->bankrupt = false;
    impl->almostBankrupt = false;
    impl->rollUpCount = rollup;
    impl->isInJail = false;
    impl->inJailCounter = 0;
    impl->moneyOwed = 0;
}

Player::~Player() {}

void Player::move(int n) {
    impl->pos += n;

    if (n < 0) {
        if (impl->pos < 0) {
            impl->pos += 40;
        }
        return;
    }

    if (impl->pos >= 40) {
        impl->pos -= 40;
    }
}

int Player::getMoney() {
    return impl->money;
}

void Player::addMoney(int n) {
    if (n < 0) {
        cout << getName() << ", you can't add a value that is less than 0. Enter a valid command." << endl;
    }
    else {
        impl->money += n;
        cout << getName() << ", you have succesfully added $" << n << " to your account. You now have $" << impl->money << endl;
    }
}

void Player::subtractMoney(int n) {
    if (impl->money >= n) {
        impl->money -= n;
        cout << getName() << ", you have successfully subtracted $" << n << " from your account. You now have $" << impl->money << endl;
    }
    else {
        impl->moneyOwed = n;
        impl->almostBankrupt = true;
        cout <<getName() << ", you do not have enough money to pay back $" << n << endl;
    }
}

void Player::declareBankruptcy() {
    cout << "I. DECLARE. BANKRUPTCYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
}

int Player::getRollUpCount() {
    return impl->rollUpCount;
}

void Player::addRollUpCount() {
    impl->rollUpCount++;
}

void Player::useRollUpCount() {
    impl->rollUpCount--;
}

void Player::displayAssets() {
    cout << "Here are " << impl->name << "'s current assets." << endl;

    cout << "Money: " << impl->money << endl;
    cout << "Tim Cups: " << impl->rollUpCount << endl;
    cout << endl
         << "Properties:" << endl;

    std::vector<shared_ptr<Tile>> myTiles = getTiles();
    int size = myTiles.size();
    for (int i = 0; i < size; i++) {
        cout << myTiles[i]->getName() << ": " << setw(5) << "$" << myTiles[i]->getPrice() << "   Improvements: " << myTiles[i]->getImprovement() << endl;
    }
}

char Player::getPiece(){
    return impl->piece;
}

string Player::getName() {
    return impl->name;
}

int Player::getPos() {
    return impl->pos;
}

void Player::setPos(int n) {
    impl->pos = n;
}

bool Player::getJailStatus() {
    return impl->isInJail;
}

void Player::setJailStatus(bool status) {
    impl->isInJail = status;
}

int Player::getJailCount() {
    return impl->inJailCounter;
}

void Player::setJailCount(int n) {
    impl->inJailCounter = n;
}

bool Player::getAlmostBankruptStatus() {
    return impl->almostBankrupt;
}

void Player::setAlmostBankruptStatus(bool status) {
    impl->almostBankrupt = status;
}

bool Player::getBankruptStatus() {
    return impl->bankrupt;
}

void Player::setBankruptStatus(bool status) {
    impl->bankrupt = status;
}

int Player::getMoneyOwed() {
    return impl->moneyOwed;
}

void Player::setMoneyOwed(int n) {
    impl->moneyOwed = n;
}

void Player::addTile(std::shared_ptr<Tile> t) {
    impl->tilesOwned.emplace_back(t);
}

std::vector<shared_ptr<Tile>> Player::getTiles() {
    return impl->tilesOwned;
}

void Player::transferProp(std::shared_ptr<Player> otherPlayer, std::shared_ptr<Tile> tile) {
    int tileIndex = -1;
    int size = impl->tilesOwned.size();
    for (int i = 0; i < size; i++) {
        if (impl->tilesOwned[i]->getName() == tile->getName()) {
            tileIndex = i;
            break;
        }
    }

    if (tileIndex == -1) {
        cout << "You do not own this property. Transferring property cancelled" << endl;
    }

    // 
    if (tile->isMortgaged()) {
        cout << tile->getName() << " is mortgaged so " << otherPlayer->getName() << " must pay 10%." << endl;
        otherPlayer->subtractMoney(0.1 * tile->getPrice());
        if (getAlmostBankruptStatus()) {
            impl->tilesOwned.erase(impl->tilesOwned.begin() + tileIndex);
            tile->setOwner(nullptr);
            setAlmostBankruptStatus(false);
            cout << "You don't have enough money to pay mortgage fee. The property will go to the bank." << endl;
            return;
        }
    }

    impl->tilesOwned.erase(impl->tilesOwned.begin() + tileIndex);
    tile->setOwner(otherPlayer);
    otherPlayer->addTile(tile);
    cout << tile->getName() << " has been transferred from " << getName() << " to " << otherPlayer->getName() << "." << endl;
}
