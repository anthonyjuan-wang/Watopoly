#include "player.h"
#include <string>
#include <iostream>
#include <memory>
using namespace std;

Player::Player(string name, char piece, int money = 1500, int pos = 0) : impl{make_shared<PlayerImpl>()}
{
    impl->name = name;
    impl->piece = piece;
    impl->money = money;
    impl->pos = pos;
    impl->bankrupt = false;
    impl->almostBankrupt = false;
    impl->rollUpCount = 0;
    impl->isInJail = false;
    impl->inJailCounter = 0;
    impl->tilesOwned{nullptr};
    impl->moneyOwed = 0;
}

void Player::move(int n)
{
    impl->pos += n;
    if (impl->pos >= 40)
    {
        impl->pos -= 40;
        // if tile is not dcTimsLine, collect $200 from OSAP (maybe could check this in play tho)
    }
}

int Player::getMoney()
{
    return impl->money;
}

void Player::addMoney(int n)
{
    if (n < 0)
    {
        cout << "You can't add a value that is less than 0. Enter a valid command." << endl;
    }
    else
    {
        impl->money += n;
        cout << "You have succesfully added $" << n << " to your account. You now have $" << impl->money << endl;
    }
}

void Player::subtractMoney(int n)
{
    if (n >= impl->money)
    {
        impl->money -= n;
        cout << "You have successfully subtracted $" << n << " fron your account. You now have $" << impl->money << endl;
    }
    else
    {
        impl->moneyOwed = n;
        impl->almostBankrupt = true;
        cout << "You do not have enough impl->money to pay back $" << n << endl;
    }
}

void Player::declareBankruptcy()
{
    cout << "I. DECLARE. BANKRUPTCYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
}

int Player::getRollUpCount()
{
    return impl->rollUpCount;
}

void Player::addRollUpCount()
{
    impl->rollUpCount++;
}

void Player::useRollUpCount()
{
    impl->rollUpCount--;
}

void Player::displayAssets()
{
    cout << "Here are " << impl->name << "'s current assets." << endl;

    cout << "Money: " << impl->money << endl;
    cout << "Tim Cups: " << impl->rollUpCount << endl;
    cout << endl
         << "Properties:" << endl;

    std::vector<shared_ptr<Tile>> myTiles = getTiles();
    int size = myTiles.size();
    for (int i = 0; i < size; i++)
    {
        cout << myTiles[i]->getName() << ": " << myTiles[i]->getPrice() << "\t Improvements: " << myTiles[i]->getImprovement() << endl;
    }
}

string Player::getName()
{
    return impl->name;
}

int Player::getPos()
{
    return impl->pos;
}

void Player::setPos(int n)
{
    impl->pos = n;
}

bool Player::getJailStatus()
{
    return impl->isInJail;
}
void Player::setJailStatus(bool status)
{
    impl->isInJail = status;
}

int Player::getJailCount()
{
    return impl->inJailCounter;
}

void Player::setJailCount(int n)
{
    impl->inJailCounter = n;
}

bool Player::getAlmostBankruptStatus() {
    return impl->almostBankrupt;
}

bool Player::getBankruptStatus() {
    return impl->bankrupt;
}

void Player::setBankruptStatus(bool status) {
    bankrupt = status;
}

void Player::addTile(std::shared_ptr<Tile> t)
{
    impl->tilesOwned.emplace_back(t);
}

std::vector<shared_ptr<Tile>> Player::getTiles()
{
    return impl->tilesOwned;
}
