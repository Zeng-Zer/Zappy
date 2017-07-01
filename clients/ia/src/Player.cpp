#include "Player.hpp"
#include "Level.hpp"

Player::Player(int x, int y, std::string const& team)
  : _x(x), _y(y), _team(team), _alive(true) {
  _data.connect_nbr = 0;
}

Player::~Player() {

}

void Player::forward() const {
  RequestBuffer::getInstance().push("Forward", {&Player::forwardResponce});
}

void Player::right() const {
  RequestBuffer::getInstance().push("Right", {&Player::rightResponce});
}

void Player::left() const {
  RequestBuffer::getInstance().push("Left", {&Player::leftResponce});
}

void Player::look() const {
  RequestBuffer::getInstance().push("Look", {&Player::lookResponce});
}

void Player::inventory() const {
  RequestBuffer::getInstance().push("Inventory", {&Player::inventoryResponce});
}

void Player::broadcast(std::string const& msg) const {
  RequestBuffer::getInstance().push("Broadcast " + msg, {&Player::broadcastResponce});
}

void Player::connect_nbr() const {
  RequestBuffer::getInstance().push("Connect_nbr", {&Player::connect_nbrResponce});
}

void Player::fork() const {
  RequestBuffer::getInstance().push("Fork", {&Player::forkResponce});
}

void Player::eject() const {
  RequestBuffer::getInstance().push("Eject", {&Player::ejectResponce});
}

void Player::take(Resource::Resource res) const {
  RequestBuffer::getInstance().push("Take " + Resource::resourceToString(res),
				    {&Player::takeResponce});
}

void Player::set(Resource::Resource res) const {
  RequestBuffer::getInstance().push("Set " + Resource::resourceToString(res),
				    {&Player::setResponce});
}

void Player::incantation() const {
  RequestBuffer::getInstance().push("Incantation", {&Player::incantationResponce});
}

bool Player::forwardResponce(std::string const& responce) const {
  if (responce != "ok") {
    std::cerr << "Forward: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::rightResponce(std::string const& responce) const {
  if (responce != "ok") {
    std::cerr << "Right: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::leftResponce(std::string const& responce) const {
  if (responce != "ok") {
    std::cerr << "Left: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::lookResponce(std::string const& responce) {
  std::stringstream ss(responce);
  std::string word;
  std::vector<std::vector<Resource::Resource> > vec;
  int length = 0;
  int j;

  while (!ss.fail()) {
    j = length;
    vec.resize(j + 1);
    ss >> word;
    if (std::isalpha(word.front())) {
      if (word.back() == ',') {
	word.erase(word.find(','));
	length++;
      }
      vec[j].emplace_back(Resource::stringToResource(word));
    }
  }
  _data.look = vec;
  return true;
}

bool Player::inventoryResponce(std::string const& responce) {
  std::stringstream ss(responce);
  std::string word;
  int q;
  std::map<Resource::Resource, int> map;

  while (!ss.fail()) {
    ss >> word;
    if (std::isalpha(word.front())) {
      ss >> q;
      map.insert(std::make_pair(Resource::stringToResource(word), q));
    }
  }
  _data.inventory = map;
  return true;
}

bool Player::broadcastResponce(std::string const& responce) const {
  if (responce != "ok") {
    std::cerr << "Broadcast: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::connect_nbrResponce(std::string const& responce) {
  std::string::size_type size;
  _data.connect_nbr = std::stoi(responce, &size);
  return (size != 0);
}

bool Player::forkResponce(std::string const& responce) const{
  if (responce != "ok") {
    std::cerr << "Fork: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::ejectResponce(std::string const& responce) const {
  if (responce != "ok") {
    std::cerr << "Eject: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::takeResponce(std::string const& responce) const {
  if (responce != "ok") {
    std::cerr << "Take: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::setResponce(std::string const& responce) const {
  if (responce != "ok") {
    std::cerr << "Set: bad responce" << std::endl;
    return false;
  }
  return true;
}

bool Player::incantationResponce(std::string const& responce) {
  return signalIncantation(responce);
}

Broadcast Player::signalBroadcast(std::string const& msg) {
  Broadcast b = { std::stoi(msg) };
  return b;
}

// do nothing
void Player::signalEject(std::string const& msg) {
  (void)msg;
}

bool Player::signalIncantation(std::string const& msg) {
  if (msg == "Elevation underway") {
    std::string responce = Connection::getInstance().recvMsg(MSG_DONTWAIT);
    std::stringstream ss(responce);
    std::string word;
    int lvl;

    if (responce == "ko") {
      return false;
    }
    do {
      ss >> word;
    } while (!std::isdigit(word[0]));
    lvl = std::stoi(word);
    if (lvl > 0) {
      _level = lvl;
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

Option<std::string> Player::recvMsg() {
  std::string responce = Connection::getInstance().recvMsg();
}

void Player::move(int x) {
  if (x == 0) {
    return;
  }

  int old_case = 0;
  int nb_case = 0;
  int nb_line = 0;
  while (nb_case <= x) {
    old_case = nb_case;
    nb_case += 1 + (2 * nb_line);
    nb_line++;
    if (nb_case <= x)
      forward();
  }

  int nb_case_line = nb_case - old_case;
  int ressource_case = x - old_case + 1;
  if (ressource_case > ((nb_case_line + 1) / 2)) {
    right();
  } else {
    left();
  }

  int nb_forward = std::abs(ressource_case - ((nb_case_line + 1) / 2));
  for (int i = 0; i < nb_forward; i++) {
    forward();
  }
}

void Player::move_sound(int x) {
  //TODO this function is like the same above but with the sound
  (void) x;
}

void Player::search(Resource::Resource res) {
}

bool Player::isAlive() const {
  return _alive;
}

void Player::update() {
  std::string responce = Connection::getInstance().recvMsg();
  bool retResponce = false;
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
      std::cout << "dead" << std::endl;
      _alive = false;
      return;
    }
    else if (responce == "Elevation underway") {
      signalIncantation(responce);
    }
    else {
      retResponce = RequestBuffer::getInstance().front().second(*this, responce);
      RequestBuffer::getInstance().pop();
    }
  }
  /**
   * IA CODE
   */
}

bool Player::canLevelUp() {
  return _level < 8 && _resource[Resource::LINEMATE] >= Lvl::level[_level + 1][Resource::LINEMATE]
    && _resource[Resource::DERAUMERE] >= Lvl::level[_level + 1][Resource::DERAUMERE]
    && _resource[Resource::SIBUR] >= Lvl::level[_level + 1][Resource::SIBUR]
    && _resource[Resource::MENDIANE] >= Lvl::level[_level + 1][Resource::MENDIANE]
    && _resource[Resource::PHIRAS] >= Lvl::level[_level + 1][Resource::PHIRAS]
    && _resource[Resource::THYSTAME] >= Lvl::level[_level + 1][Resource::THYSTAME];
}
