#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <vector>
# include <string>
# include <map>
# include <sstream>
# include <iostream>
# include "Connection.hpp"
# include "Resource.hpp"
# include "Level.hpp"
# include "Option.hpp"

struct Broadcast {
  int dir;
  int nbPlayerRequired;
};

class Player {
public:
  Player(int x, int y, std::string const& team);
  ~Player();

  /**
   * COMMANDS
   */
  void forward();
  void right();
  void left();
  std::vector<std::map<Resource::Resource, int>> look();
  void inventory();
  void broadcast(std::string const& msg);
  void connect_nbr();
  void fork();
  void eject();
  void take(Resource::Resource res);
  void set(Resource::Resource res);
  void incantation();

  /*
  ** recv all msg
  */
  Option<std::string> recvMsg(int flags = 0);

  /*
  ** actual method
  */
  void update();
  bool isAlive() const;
  Resource::Resource getMissingResource();
  void move(int x);
  void moveTowardSound(int x);
  void search(Resource::Resource res);
  bool isMissingPlayer(std::map<Resource::Resource, int>&);
  void setupStone(std::map<Resource::Resource, int>& items);

private:
  int _x;
  int _y;
  int _level;
  std::string _team;
  bool _alive;
  // Resource = type de resource, et int le nombre
  std::map<Resource::Resource, int> _resource;
  Option<Broadcast> _broadcast;
  bool _incanting;
  int _survivalFood;
  bool _move;
};

#endif /* !PLAYER_HPP_ */
