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

  /**
   * data updated by commands response
   */
  struct dataResponce {
    /**
     * number of team unused slots
     */
    int connect_nbr;

    /**
     * vector of cone of vision
     * vector of resource per square in the cone
     */
    std::vector<std::vector<Resource::Resource>> look;

    /**
     * map de resource et de la quantité de resource
     */
    std::map<Resource::Resource, int> inventory;
  };


public:
  Player(int x, int y, std::string const& team);
  ~Player();

  /**
   * COMMANDS
   */
  void forward() const;
  void right() const;
  void left() const;
  void look() const;
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
  bool forwardResponce(std::string&) const;
  bool rightResponce(std::string&) const;
  bool leftResponce(std::string&) const;
  bool lookResponce(std::string&);
  // TODO
  bool inventoryResponce(std::string&);
  bool broadcastResponce(std::string&) const;
  bool connect_nbrResponce(std::string&);
  bool forkResponce(std::string&) const;
  bool ejectResponce(std::string&) const;
  bool takeResponce(std::string&) const;
  bool setResponce(std::string&) const;
  // TODO
  bool incantationResponce(std::string&);

  /**
   * temporary return int value to quit loop
   */
  int update();

  void move(int x);
  bool canLevelUp();
  /**
   * TODO
   * Need details
   */
  Broadcast signalBroadcast(std::string const& msg);
  /**
   * TODO
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
  struct dataResponce _data;
  // Resource = type de resource, et int le nombre
  std::map<Resource::Resource, int> _resource;
};

#endif /* !PLAYER_HPP_ */
