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
  void take(Resource::Resource res) const;
  void set(Resource::Resource res) const;
  void incantation() const;

  /**
   * RESPONCES
   */
  static bool forwardResponce(std::string&);
  static bool rightResponce(std::string&);
  static bool leftResponce(std::string&);
  static bool lookResponce(std::string&);
  static bool inventoryResponce(std::string&);
  static bool broadcastResponce(std::string&);
  static bool connect_nbrResponce(std::string&);
  static bool forkResponce(std::string&);
  static bool ejectResponce(std::string&);
  static bool takeResponce(std::string&);
  static bool setResponce(std::string&);
  static bool incantationResponce(std::string&);

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
  std::map<Resource::Resource, int> _resource;
};

#endif /* !PLAYER_HPP_ */
