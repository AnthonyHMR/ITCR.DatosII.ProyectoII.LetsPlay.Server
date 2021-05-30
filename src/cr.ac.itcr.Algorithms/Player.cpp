//
// Created by juanpr on 29/5/21.
//

#include "Player.h"

int Player::getId() const {
    return ID;
}

void Player::setId(int id) {
    ID = id;
}

int Player::getTeam() const {
    return team;
}

void Player::setTeam(int team) {
    Player::team = team;
}

int Player::getPosX() const {
    return posX;
}

void Player::setPosX(int posX) {
    Player::posX = posX;
}

int Player::getPosY() const {
    return posY;
}

void Player::setPosY(int posY) {
    Player::posY = posY;
}
