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
  RequestBuffer::getInstance().push("Broadcast " + msg, std::function<void(std::string)>(broadcastResponce));
}

// void Player::take(Resource res) {

// }

// void Player::set(Resource res) {

// }

void Player::incantation() {

}

void Player::broadcastResponce(std::string responce) {
  if (responce != "ok") {
    std::cerr << "broadcast: bad responce" << std::endl;
  }
}

// Broadcast Player::getBroadcast(std::string const& msg) {
//   int i;
//   i = std::stoi(msg);
// }

// void Player::move(int _destx, int _desty) {

// }

int Player::update() {
  bool oneShot = false;
  if (!oneShot) {
    std::cout << "broadcast: hello" << std::endl;
    broadcast("Hello");
  }
  oneShot = true;

  std::string responce = Connection::getInstance().recvMsg();
  if (!responce.empty()) {
    RequestBuffer::getInstance().front().second(responce);
    RequestBuffer::getInstance().pop();
    return (0);
  }
  return (1);
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
