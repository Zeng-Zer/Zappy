#include "Player.hpp"
#include "Level.hpp"

Player::Player(int x, int y, std::string const& team) {
  this->_x = x;
  this->_y = y;
  this->_team = team;
  _data.connect_nbr = 0;
}

Player::~Player() {

}

void Player::forward() const {
  RequestBuffer::getInstance().push("Forward",
				    std::function<bool(Player&, std::string&)>(&Player::forwardResponce));
}

void Player::right() const {
  RequestBuffer::getInstance().push("Right",
				    std::function<bool(Player&, std::string&)>(&Player::rightResponce));
}

void Player::left() const {
  RequestBuffer::getInstance().push("Left",
				    std::function<bool(Player&, std::string&)>(&Player::leftResponce));
}

void Player::look() const {
  RequestBuffer::getInstance().push("Look",
				    std::function<bool(Player&, std::string&)>(&Player::lookResponce));
}

void Player::inventory() const {
  RequestBuffer::getInstance().push("Inventory",
				    std::function<bool(Player&, std::string&)>(&Player::inventoryResponce));
}

void Player::broadcast(std::string const& msg) const {
  RequestBuffer::getInstance().push("Broadcast " + msg,
				    std::function<bool(Player&, std::string&)>(&Player::broadcastResponce));
}

void Player::connect_nbr() const {
  RequestBuffer::getInstance().push("Connect_nbr",
				    std::function<bool(Player&, std::string&)>(&Player::connect_nbrResponce));
}

void Player::fork() const {
  RequestBuffer::getInstance().push("Fork",
				    std::function<bool(Player&, std::string&)>(&Player::forkResponce));
}

void Player::eject() const{
  RequestBuffer::getInstance().push("Eject",
				    std::function<bool(Player&, std::string&)>(&Player::ejectResponce));
}

void Player::take(Resource::Resource res) const {
  RequestBuffer::getInstance().push("Take",
				    std::function<bool(Player&, std::string&)>(&Player::takeResponce));
}

void Player::set(Resource::Resource res) const {
  RequestBuffer::getInstance().push("Set",
				    std::function<bool(Player&, std::string&)>(&Player::setResponce));
}

void Player::incantation() const {
  RequestBuffer::getInstance().push("Incantation",
				    std::function<bool(Player&, std::string&)>(&Player::incantationResponce));
}

bool Player::forwardResponce(std::string& responce) const {
  if (responce != "ok") {
    std::cerr << "Forward: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::rightResponce(std::string& responce) const {
  if (responce != "ok") {
    std::cerr << "Right: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::leftResponce(std::string& responce) const{
  if (responce != "ok") {
    std::cerr << "Left: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::lookResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "Look: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::inventoryResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "Inventory: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::broadcastResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "Broadcast: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::connect_nbrResponce(std::string& responce) {
  std::string::size_type size;
  _data.connect_nbr = std::stoi(responce, &size);
  return (size != 0);
}

bool Player::forkResponce(std::string& responce) const{
  if (responce != "ok") {
    std::cerr << "Fork: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::ejectResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "Eject: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::takeResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "Take: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::setResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "Set: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::incantationResponce(std::string& responce) {
  if (responce != "ok") {
    std::cerr << "Incantation: bad responce" << std::endl;
    return false;
  }
  return true;
}

Broadcast Player::signalBroadcast(std::string const& msg) {
  int i;
  i = std::stoi(msg);
}

void Player::signalEject(std::string const& msg) {
  (void) msg;
}

/*
void Player::move(std::vector<int> x) {
  int nb_case = 0;
  int nb_line = 0;
  int line = 0;
  int ressource_case;
  int nb_forward;
  int nb_case_line;

  while (nb_case < x) {
    nb_case += 1 + (2 * nb_line);
    line++;
    nb_line++;
  }
  //TODO call nb_line times forward function
  ressource_case = x - (nb_case - (1 + 2 * (nb_line - 1)));
  if (ressource_case > ((nb_case_line - 1) / 2)) { //TODO calculate total cases for the line that contains the x
    right();
  }
  else if (ressource_case < ((nb_case_line - 1) / 2)) {
    left();
  }
  nb_forward = ressource_case - ((nb_case_line - 1) / 2); //TODO call nb_forward times forward function and manage negative numbers
}
*/

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
      RequestBuffer::getInstance().front().second(*this, responce);
      RequestBuffer::getInstance().pop();
    }
    return 0;
  }
  return 1;
}

bool Player::canLevelUp() {
  return this->_level < 8 && this->_resource[Resource::LINEMATE] >= Lvl::level[this->_level + 1][Resource::LINEMATE]
    && this->_resource[Resource::DERAUMERE] >= Lvl::level[this->_level + 1][Resource::DERAUMERE]
    && this->_resource[Resource::SIBUR] >= Lvl::level[this->_level + 1][Resource::SIBUR]
    && this->_resource[Resource::MENDIANE] >= Lvl::level[this->_level + 1][Resource::MENDIANE]
    && this->_resource[Resource::PHIRAS] >= Lvl::level[this->_level + 1][Resource::PHIRAS]
    && this->_resource[Resource::THYSTAME] >= Lvl::level[this->_level + 1][Resource::THYSTAME];
}
