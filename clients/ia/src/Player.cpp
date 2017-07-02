#include "Player.hpp"
#include "Level.hpp"

Player::Player(int x, int y, std::string const& team)
  : _x(x), _y(y), _level(1), _team(team), _alive(true), _incanting(false),
    _survivalFood(20), _task(STAND_BY) {
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
  // std::cout << "Inventory()" << std::endl;

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
  std::cout << "Broadcast() " << message << std::endl;

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
  std::cout << "Take() " << Resource::resourceToString(res) << std::endl;

  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (*msg != "ok") {
    std::cerr << "Take: bad responce" << std::endl;
  } else {
    ++_resource[res];
  }
}

void Player::set(Resource::Resource res) {
  Connection::getInstance().sendMsg("Set " + Resource::resourceToString(res));
  std::cout << "Set() " << Resource::resourceToString(res) << std::endl;

  Option<std::string> msg;
  while (!(msg = recvMsg()));

  if (*msg != "ok") {
    std::cerr << "Set: ko" << std::endl;
  } else {
    --_resource[res];
  }
}

void Player::incantation() {
  // broadcast("start " + std::to_string(_level));

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

  broadcast("done " + std::to_string(_level));

  if (*msg == "ko") {
    std::cerr << "Incantation: end: ko" << std::endl;
  } else {
    ++_level;
    _task = STAND_BY;
    std::cout << *msg << std::endl;
  }

  _incanting = false;
}

void Player::handleMsg(std::string const& response, std::string str,
				    std::stringstream& ss) {
  int dir;
  ss >> dir;
  ss >> str;
  std::getline(ss, str);

  if (!_incanting && _task == SBIRE &&
      str.find("done " + std::to_string(_level)) != std::string::npos) {
    _task = STAND_BY;
  }
  else {
    try {
      int level = std::stoi(str);
      if (level == _level && (_task == STAND_BY || _task == SBIRE)) {
	std::cout << "GOT: " << response << std::endl;
	std::cout << "level: " << level << std::endl;
	_task = SBIRE;
	_broadcast = { { dir, level } };
      }
      else {
	_broadcast = {};
      }
    } catch (...) {
      _broadcast = {};
    }
  }
}

Option<std::string> Player::recvMsg(int flags) {
  std::string response = Connection::getInstance().recvMsg(flags);
  // std::cout << response << std::endl;
  std::stringstream ss(response);

  std::string str;
  ss >> str;
  // broadcast
  if (str == "message") {
    handleMsg(response, str, ss);
  } else if (str == "dead") {
    std::cout << "dead" << std::endl;
    exit(0);
  } else if (!_incanting && str == "Elevation") {
    std::cout << "Elevation underway" << std::endl;
  } else if (str == "eject:") {
    // do nothing
  } else if (!_incanting && str == "Current") {
    ++_level;
    std::cout << response << std::endl;
    _task = STAND_BY;
    _broadcast = {};
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

/*
** 218
** 307
** 456
*/
void Player::moveTowardSound(int k, int lvl) {
  switch (k) {
  case 0:
    return;
  case 1:
    break;
  case 2:
    forward();
    left();
    break;
  case 3:
    left();
    break;
  case 4:
    left();
    forward();
    left();
    break;
  case 5:
    left();
    left();
    break;
  case 6:
    right();
    forward();
    right();
    break;
  case 7:
    right();
    break;
  case 8:
    forward();
    right();
    break;
  }

  auto players = look();
  if (players.size() >= 3 &&
      players[2][Resource::PLAYER] < Lvl::level[lvl + 1][Resource::PLAYER]) {
    forward();
  }
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
      return res.first;
    }
  }
  return Resource::UNKNOWN;
}

bool Player::isAlive() const {
  return _alive;
}

bool Player::isMissingPlayer(std::map<Resource::Resource, int>& items) {
  if (_level >= 8) {
    return false;
  }

  int nbPlayer = Lvl::level[_level + 1][Resource::PLAYER];
  if (items.count(Resource::PLAYER) == 0) {
    items[Resource::PLAYER] = 0;
  }

  if (items[Resource::PLAYER] > nbPlayer) {
    forward();
    return true;
  }

  if (items[Resource::PLAYER] < nbPlayer) {
    _task = LEVELER;
    broadcast(std::to_string(_level));
    return true;
  }
  std::cout << "Incatation " << _level << ", " << items[Resource::PLAYER]
	    << " here" << std::endl;
  return false;
}

void Player::setupStone(std::map<Resource::Resource, int>& items) {
  // auto itemsVec = look();
  // if (itemsVec.size() >= 3) {
  //   items = itemsVec[0];
  for (auto& res : Lvl::level[_level + 1]) {
    if (res.first == Resource::PLAYER || res.first == Resource::FOOD) {
      continue;
    }

    if (items.count(res.first) == 0) {
      items[res.first] = 0;
    }

    while (items[res.first] < res.second) {
      set(res.first);
      ++items[res.first];
    }
    while (items[res.first] > res.second) {
      take(res.first);
      --items[res.first];
    }

  }
  // }
}

void Player::update() {
  if (_task != SBIRE) {
    if (_resource[Resource::FOOD] < _survivalFood) {
      search(Resource::FOOD);
    }
    else if (_task != SBIRE) {
      Resource::Resource res = getMissingResource();

      // GET MISSING RESOURCE
      if (res != Resource::UNKNOWN) {
	search(res);
      }

      else if (_level < 8) {
	_survivalFood = 5;
	auto itemsVec = look();
	if (itemsVec.size() >= 3) {
	  auto items = itemsVec[0];
	  if (!isMissingPlayer(items)) {
	    setupStone(items);
	    incantation();
	    _survivalFood = 20;
	  }
	}

      }

    }
  }

  inventory();

  if (_task == SBIRE && _broadcast) {
    std::cout << "MOVE TOWARD: " << _broadcast->dir << std::endl;
    moveTowardSound(_broadcast->dir, _broadcast->lvl);
  }

  if (_resource[Resource::FOOD] < 5) {
    while (_resource[Resource::FOOD] < 20) {
      search(Resource::FOOD);
    }
  }

  // reset broadcast
  _broadcast = {};
}
