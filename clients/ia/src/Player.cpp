#include "Player.hpp"
#include "Level.hpp"

Player::Player(int x, int y, std::string const& team)
  : _x(x), _y(y), _team(team), _alive(true), _incanting(false) {
  _data.connect_nbr = 0;
}

Player::~Player() {

}

void Player::forward() {
  Connection::getInstance().sendMsg("Forward");
  std::cout << "Forward()" << std::endl;

  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (*msg != "ok") {
    std::cerr << "Forward: bad responce" << std::endl;
  }
}

void Player::right() {
  Connection::getInstance().sendMsg("Right");
  std::cout << "Right()" << std::endl;

  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (*msg != "ok") {
    std::cerr << "Right: bad responce" << std::endl;
  }
}

void Player::left() {
  Connection::getInstance().sendMsg("Left");
  std::cout << "Left()" << std::endl;

  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (*msg != "ok") {
    std::cerr << "Left: bad responce" << std::endl;
  }
}

std::vector<std::map<Resource::Resource, int>> Player::look() {
  Connection::getInstance().sendMsg("Look");
  std::cout << "Look()" << std::endl;

  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (msg->size() < 5) {
    return {};
  }

  std::vector<std::map<Resource::Resource, int>> items;
  std::stringstream ss(msg->substr(1, msg->size() - 2));
  std::string str;
  int i = 0;
  while (std::getline(ss, str, ',')) {
    items.resize(i + 1);
    str.erase(0, 1);

    std::stringstream ssRes(str);
    std::string strRes;
    while (ssRes >> strRes) {
      std::cout << strRes << std::endl;
      Resource::Resource res = Resource::stringToResource(strRes);
      if (res != Resource::UNKNOWN) {
	++items[i][res];
      }
    }

    ++i;
  }

  return items;
}

void Player::inventory() {
  Connection::getInstance().sendMsg("Inventory");
  std::cout << "Inventory()" << std::endl;

  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (msg->size() < 5) {
    return;
  }

  std::stringstream ss(msg->substr(1, msg->size() - 2));
  std::string str;
  while (std::getline(ss, str, ',')) {
    str.erase(0, 1);

    std::stringstream ssRes(str);
    std::string strRes;
    int nb;
    ssRes >> strRes;
    ssRes >> nb;
    std::cout << strRes << std::endl;
    std::cout << nb << std::endl;
    Resource::Resource res = Resource::stringToResource(strRes);
    if (res != Resource::UNKNOWN) {
      _resource[res] = nb;
    }
  }
}

void Player::broadcast(std::string const& message) {
  Connection::getInstance().sendMsg("Broadcast " + message);
  std::cout << "Broadcast()" << std::endl;

  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (*msg != "ok") {
    std::cerr << "Broadcast: bad responce" << std::endl;
  }
}

void Player::connect_nbr() {
  RequestBuffer::getInstance().push("Connect_nbr", {&Player::connect_nbrResponce});
}

void Player::fork() {
  RequestBuffer::getInstance().push("Fork", {&Player::forkResponce});
}

void Player::eject() {
  RequestBuffer::getInstance().push("Eject", {&Player::ejectResponce});
}

void Player::take(Resource::Resource res) {
  Connection::getInstance().sendMsg("Take " + Resource::resourceToString(res));
  std::cout << "Take()" << std::endl;

  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (*msg != "ok") {
    std::cerr << "Take: bad responce" << std::endl;
  }
}

void Player::set(Resource::Resource res) {
  Connection::getInstance().sendMsg("Set " + Resource::resourceToString(res));
  std::cout << "Set()" << std::endl;

  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (*msg != "ok") {
    std::cerr << "Set: ko" << std::endl;
  } else {
    --_resource[res];
  }
}

// TODO MODIFY THIS
void Player::incantation() {
  Connection::getInstance().sendMsg("Incantation");
  std::cout << "Incantation()" << std::endl;

  _incanting = true;
  Option<std::string> msg;
  while (_incanting && !(msg = recvMsg()));
  _incanting = false;

  if (*msg == "ko") {
    std::cerr << "Incantation: ko" << std::endl;
  }
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
  Broadcast b;
  return b;
}

bool Player::signalIncantation(std::string const& msg) {
  return true;
}

Option<std::string> Player::recvMsg() {
  std::string response = Connection::getInstance().recvMsg();
  std::cout << response << std::endl;
  std::stringstream ss(response);

  std::string str;
  ss >> str;
  // broadcast
  if (str == "message") {
    int dir;
    ss >> dir;
    ss >> str;
    ss.get();
    std::getline(ss, str);
    try {
      _broadcast = { { dir, std::stoi(str) } };
    } catch (...) {
      _broadcast = {};
    }
  } else if (str == "dead") {
    exit(0);
  } else if (str == "Elevation") {
    _incanting = true;
  } else if (str == "eject:") {
    // do nothing
  } else if (str == "Current") {
    ++_level;
    std::cout << "New level: " << _level << std::endl;
    _incanting = false;
  } else {
    return {response};
  }
  return {};
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

void Player::move_sound(int k) {
  //TODO this function is like the same above but with the sound
  (void) k;
}

void Player::search(Resource::Resource res) {

}

bool Player::isAlive() const {
  return _alive;
}

void Player::update() {
  if (_incanting) {
    return;
  }
  /**
   * IA CODE
   */
  // look();
  // inventory();
  // forward();
  // right();
  // left();
  // take(Resource::FOOD);
  // inventory();
  incantation();
  // reset broadcast
  _broadcast = {};
}

bool Player::canLevelUp() {
  return _level < 8 && _resource[Resource::LINEMATE] >= Lvl::level[_level + 1][Resource::LINEMATE]
    && _resource[Resource::DERAUMERE] >= Lvl::level[_level + 1][Resource::DERAUMERE]
    && _resource[Resource::SIBUR] >= Lvl::level[_level + 1][Resource::SIBUR]
    && _resource[Resource::MENDIANE] >= Lvl::level[_level + 1][Resource::MENDIANE]
    && _resource[Resource::PHIRAS] >= Lvl::level[_level + 1][Resource::PHIRAS]
    && _resource[Resource::THYSTAME] >= Lvl::level[_level + 1][Resource::THYSTAME];
}
