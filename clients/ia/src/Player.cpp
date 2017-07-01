#include "Player.hpp"
#include "Level.hpp"

Player::Player(int x, int y, std::string const& team)
  : _x(x), _y(y), _level(1), _team(team), _alive(true), _incanting(false) {
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
      // std::cout << strRes << std::endl;
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
    // std::cout << strRes << std::endl;
    // std::cout << nb << std::endl;
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
}

void Player::fork() {
}

void Player::eject() {
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

void Player::incantation() {
  Connection::getInstance().sendMsg("Incantation");
  std::cout << "Incantation()" << std::endl;

  _incanting = true;
  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (*msg == "ko") {
    std::cerr << "Incantation: first check: ko" << std::endl;
  } else {
    std::cout << "Incantation underway ! " << std::endl;
  }
  while (!(msg = recvMsg()));

  if (*msg == "ko") {
    std::cerr << "Incantation: end: ko" << std::endl;
  } else {
    ++_level;
    std::cout << "Incantation success: new level: " << _level << std::endl;
  }

  _incanting = false;
}

Option<std::string> Player::recvMsg(int flags) {
  std::string response = Connection::getInstance().recvMsg(flags);
  // std::cout << response << std::endl;
  std::stringstream ss(response);

  std::string str;
  ss >> str;
  // broadcast
  if (str == "message") {
    std::cout << response << std::endl;
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
  } else if (!_incanting && str == "Elevation") {
    _noAction = true;
  } else if (str == "eject:") {
    // do nothing
  } else if (!_incanting && str == "Current") {
    ++_level;
    std::cout << "New level: " << _level << std::endl;
    _noAction = false;
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
  bool hasRes = false;

  while (!hasRes) {
    auto items = look();
    int i = 0;
    for (auto const& map : items) {
      if (map.count(res) > 0) {
	hasRes = true;
	break;
      }
      ++i;
    }

    if (hasRes) {
      move(i);
      take(res);
    } else {
      if (rand() % 2) {
	right();
      }
      forward();
    }
    inventory();
  }
}

Resource::Resource Player::getMissingResource() {
  if (_level >= 8) {
    return Resource::UNKNOWN;
  }

  auto missingMap = Lvl::level[_level + 1];
  for (auto const& res : missingMap) {
    if (res.first == Resource::PLAYER) {
      continue;
    }

    if (res.second > _resource[res.first]) {
      return (res.first);
    }
  }
  return (Resource::UNKNOWN);
}

bool Player::isAlive() const {
  return _alive;
}

bool Player::isMissingPlayer(std::map<Resource::Resource, int>& items) {
  if (_level >= 8) {
    return false;
  }

  int nbPlayer = Lvl::level[_level + 1][Resource::PLAYER];
  if (items[Resource::PLAYER] != nbPlayer) {
    broadcast(std::to_string(nbPlayer - items[Resource::PLAYER]));
    return true;
  }
  return false;
}

void Player::takeUselessStone(std::map<Resource::Resource, int>& items) {
  for (auto const& res : items) {
    if (res.first == Resource::PLAYER || res.first == Resource::FOOD) {
      continue;
    }

    for (int i = 0; i < res.second; ++i) {
      take(res.first);
    }

  }
}

void Player::setStone() {
  for (auto const& res : Lvl::level[_level + 1]) {
    if (res.first == Resource::PLAYER || res.first == Resource::FOOD) {
      continue;
    }

    for (int i = 0; i < res.second; ++i) {
      set(res.first);
    }
  }
}

void Player::update() {
  if (_noAction) {
    return;
  }

  if (_resource[Resource::FOOD] < 15) {
    search(Resource::FOOD);
  }
  else {
    Resource::Resource res = getMissingResource();

    // GET MISSING RESOURCE
    if (res != Resource::UNKNOWN) {
      search(res);
    }

    else {
      // TODO MAYBE SEARCH FOR MORE FOOD
      auto items = look()[0];
      if (!isMissingPlayer(items)) {
	takeUselessStone(items);
	setStone();
	incantation();
      }

      inventory();
    }

  }

  // reset broadcast
  _broadcast = {};
}

bool Player::canLevelUp() {
  return _level < 8
    && _resource[Resource::LINEMATE] >= Lvl::level[_level + 1][Resource::LINEMATE]
    && _resource[Resource::DERAUMERE] >= Lvl::level[_level + 1][Resource::DERAUMERE]
    && _resource[Resource::SIBUR] >= Lvl::level[_level + 1][Resource::SIBUR]
    && _resource[Resource::MENDIANE] >= Lvl::level[_level + 1][Resource::MENDIANE]
    && _resource[Resource::PHIRAS] >= Lvl::level[_level + 1][Resource::PHIRAS]
    && _resource[Resource::THYSTAME] >= Lvl::level[_level + 1][Resource::THYSTAME];
}
