#include "Player.hpp"
#include "Level.hpp"

Player::Player(int x, int y, std::string const& team) {
  this->_x = x;
  this->_y = y;
  this->_team = team;
}

Player::~Player() {

}

void Player::broadcast(std::string const& msg) {
  RequestBuffer::getInstance().push("Broadcast " + msg, std::function<void(void)>(broadcastResponce));
}

void Player::take(Resource res) {

}

void Player::set(Resource res) {

}

void Player::incantation() {

}

void Player::broadcastResponce(void) {

}

Broadcast Player::getBroadcast(std::string const& msg) {
  int i;
  i = std::stoi(msg);
}

void Player::move(int _destx, int _desty) {

}

void Player::update() {
  bool oneShot = false;
  if (!oneShot)
    broadcast("Hello");
  oneShot = true;
}

bool Player::canLevelUp() {
  if (this->_level < 8 && this->_resource[LINEMATE] >= Lvl::level[this->_level + 1][LINEMATE]
      && this->_resource[DERAUMERE] >= Lvl::level[this->_level + 1][DERAUMERE]
      && this->_resource[SIBUR] >= Lvl::level[this->_level + 1][SIBUR]
      && this->_resource[MENDIANE] >= Lvl::level[this->_level + 1][MENDIANE]
      && this->_resource[PHIRAS] >= Lvl::level[this->_level + 1][PHIRAS]
      && this->_resource[THYSTAME] >= Lvl::level[this->_level + 1][THYSTAME])
    return true;
  else
    return false;
}
