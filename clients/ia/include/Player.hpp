#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <vector>
# include <string>
# include <map>
# include "Resource.hpp"

class Player {
public:
  Player(int x, int y, std::string const& team);
  ~Player();

  void left();
  void right();
  void forward();
  /*
  ** vector du cone de vision
  ** vector de ressource par cas dans le cone
  */
  std::vector<std::vector<Resource>> look();
  /*
  ** map de resource et de la quantité de resource
  */
  std::map<Resource, int> inventory();
  void broadcast(std::string const& msg);
  void fork();
  void eject();
  void take(Resource res);
  void set(Resource res);
  void incantation();

  void update();
  void move(int x, int y);

private:
  int _x;
  int _y;
  int _level;
  int _destx;
  int _desty;
  std::string _team;
  // Resource = type de resource, et int le nombre
  std::map<Resource, int> _resource;
};

#endif /* !PLAYER_HPP_ */
