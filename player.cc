#include "player.h"

Player::Player(std::string name, char piece) : name{name}, piece{piece}, money{1500},
pos{0}, bankrupt{false}, rollUpCount{0}, isInJail{false}, inJailCounter{0} {}

void Player::move(int n) {
    pos += n;
    if (pos >= 40) {
        pos -= 40;
    }
}

void Player::getMoney() {
    return money;
}

void Player::addMoney(int n) {
    money += n;
}

void Player::subtractMoney(int n) {
    money -= n;
}

void Player::decideBankruptcy() {

}

void Player::bankruptcy() {

}

int Player::getRollUpCount() {
    return rollUpCount;
}

void Player::setRollUpCount(int count) {
    rollUpCount = count;
}

void Player::displayAssets() {

}

std::vector<tile> Player::getProperties() {

}

void Player::setProperties(tile t) {

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

}

vector<tile*> Player::getTiles() {
    
}