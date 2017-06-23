#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <vector>
# include <string>
# include <map>
# include "Resource.hpp"
# include "Level.hpp"

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
  std::vector<std::vector<Resource> > look();
  /*
  ** map de resource et de la quantité de ressource
  */
  std::map<Resource, int> inventory();
  void broadcast(std::string const& msg);
  void fork();
  void eject();
  void take(Resource res);
  void set(Resource res);
  void incantation();

  void update();
  bool canLevelUp();

private:
  int _x;
  int _y;
  int _level;
  std::string _team;
  // Resouce = type de ressource, et int le nombre
  std::map<Resource, int> _resource;
};

#endif /* !PLAYER_HPP_ */
