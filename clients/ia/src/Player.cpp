#include "Player.hpp"
#include "Level.hpp"

Player::Player(int x, int y, std::string const& team) {
  this->_x = x;
  this->_y = y;
  this->_team = team;
}

Player::~Player() {

}

void Player::forward() const {
  RequestBuffer::getInstance().push("Forward", std::function<void(std::string&)>(moveResponce));
}

void Player::right() const {
  RequestBuffer::getInstance().push("Right", std::function<void(std::string&)>(moveResponce));
}

void Player::left() const {
  RequestBuffer::getInstance().push("Left", std::function<void(std::string&)>(moveResponce));
}

void Player::look() const {
  RequestBuffer::getInstance().push("Look", std::function<void(std::string&)>(moveResponce));
}

void Player::inventory() const {
  RequestBuffer::getInstance().push("Inventory", std::function<void(std::string&)>(moveResponce));
}

void Player::broadcast(std::string const& msg) const {
  RequestBuffer::getInstance().push("Broadcast " + msg, std::function<void(std::string&)>(broadcastResponce));
}

void Player::connect_nbr() const {
  RequestBuffer::getInstance().push("Connect_nbr", std::function<void(std::string&)>(moveResponce));
}

void Player::fork() const {
  RequestBuffer::getInstance().push("Fork", std::function<void(std::string&)>(forkResponce));
}

void Player::eject() const{
  RequestBuffer::getInstance().push("Eject", std::function<void(std::string&)>(ejectResponce));
}

// void Player::take(Resource res) {

// }

// void Player::set(Resource res) {

// }

void Player::incantation() {

}

void Player::moveResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "Movement command: bad responce" << std::endl;
  }
}

void Player::broadcastResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "broadcast: bad responce" << std::endl;
  }
}

void Player::forkResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "fork: bad responce" << std::endl;
  }
}

void Player::ejectResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "broadcast: bad responce" << std::endl;
  }
}

Broadcast Player::signalBroadcast(std::string const& msg) {
  int i;
  i = std::stoi(msg);
}

void Player::signalEject(std::string const& msg) {
  (void) msg;
}

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
    std::stringstream ss;
    ss << responce;
    std::string firstWord;
    ss >> firstWord;
    if (firstWord == "message") {
      signalBroadcast(responce);
    }
    else if (firstWord == "eject:") {
      signalEject(responce);
    }
    else if (firstWord == "dead") {
      return 0;
    }
    else {
      RequestBuffer::getInstance().front().second(responce);
      RequestBuffer::getInstance().pop();
    }
    return 0;
  }
  return 1;
}

bool Player::canLevelUp() {
  return this->_level < 8 && this->_resource[LINEMATE] >= Lvl::level[this->_level + 1][LINEMATE]
    && this->_resource[DERAUMERE] >= Lvl::level[this->_level + 1][DERAUMERE]
    && this->_resource[SIBUR] >= Lvl::level[this->_level + 1][SIBUR]
    && this->_resource[MENDIANE] >= Lvl::level[this->_level + 1][MENDIANE]
    && this->_resource[PHIRAS] >= Lvl::level[this->_level + 1][PHIRAS]
    && this->_resource[THYSTAME] >= Lvl::level[this->_level + 1][THYSTAME];
}
