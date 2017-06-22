#include "Player.hpp"

Player::Player(int x, int y, std::string const& team) {
  this->_x = x;
  this->_y = y;
  this->_team = team;
}

void Player::broadcast(std::string const& msg) {

}

void Player::take(Resource res) {

}

void Player::set(Resource res) {

}

void Player::incantation() {

}

void Player::update() {
}

bool Player::canLevelUp() {
  if (this->_level < 8 && this->_resource[LINEMATE] >= Lvl::level[this->_level + 1][LINEMATE]
      && this->_resource >= Lvl::level[this->_level + 1][DERAUMERE]
      && this->_resource >= Lvl::level[this->_level + 1][SIBUR]
      && this->_resource >= Lvl::level[this->_level + 1][MENDIANE]
      && this->_resource >= Lvl::level[this->_level + 1][PHIRAS]
      && this->_resource >= Lvl::level[this->_level + 1][THYSTAME])
    return true;
  else
    return false;
}
