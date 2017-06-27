#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <vector>
# include <string>
# include <sstream>
# include <map>
# include "Connection.hpp"
# include "RequestBuffer.hpp"
# include "Resource.hpp"
# include "Level.hpp"

struct Broadcast {
  int x;
  int y;
  int lvl;
};

class Player {
public:
  Player(int x, int y, std::string const& team);
  ~Player();

  /**
   * COMMANDS
   */
  void forward() const;
  void right() const;
  void left() const;
  /**
   * vector du cone de vision
   * vector de ressource par cas dans le cone
   */
  // std::vector<std::vector<Resource> > look();
  void look() const;
  /**
   * map de resource et de la quantité de resource
   */
  // std::map<Resource, int> inventory();
  void inventory() const;
  void broadcast(std::string const& msg) const;
  void connect_nbr() const;
  void fork() const;
  void eject() const;
  void take(Resource res);
  void set(Resource res);
  void incantation();

  /**
   * RESPONCES
   */
  static void moveResponce(std::string&);
  static void broadcastResponce(std::string&);
  static void forkResponce(std::string&);
  static void ejectResponce(std::string&);

  /**
   * temporary return int value to quit loop
   */
  int update();

  void move(int x, int y);
  bool canLevelUp();
  Broadcast signalBroadcast(std::string const& msg);
  /**
   * temporary prototype, writed to compile but does nothing
   */
  void signalEject(std::string const& msg);

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
