#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <vector>
# include <string>
# include <map>
# include <sstream>
# include <iostream>
# include "Connection.hpp"
# include "RequestBuffer.hpp"
# include "Resource.hpp"
# include "Level.hpp"
# include "Option.hpp"

struct Broadcast {
  int dir;
  int nbPlayerRequired;
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
     * map of resource and quantity of resource
     */
    std::map<Resource::Resource, int> inventory;
  };


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

  /**
   * RESPONCES
   */
  bool forwardResponce(std::string const&) const;
  bool rightResponce(std::string const&) const;
  bool leftResponce(std::string const&) const;
  bool lookResponce(std::string const&);
  bool inventoryResponce(std::string const&);
  bool broadcastResponce(std::string const&) const;
  bool connect_nbrResponce(std::string const&);
  bool forkResponce(std::string const&) const;
  bool ejectResponce(std::string const&) const;
  bool takeResponce(std::string const&) const;
  bool setResponce(std::string const&) const;
  bool incantationResponce(std::string const&);

  /*
  **
  */
  Option<std::string> recvMsg();

  /*
  ** actual method
  */
  void update();
  bool isAlive() const;
  void move(int x);
  void move_sound(int x);
  bool canLevelUp();
  void search(Resource::Resource res);
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
  /**
   * Blocking signal
   */
  bool signalIncantation(std::string const& msg);

private:
  int _x;
  int _y;
  int _level;
  std::string _team;
  bool _alive;
  struct dataResponce _data;
  // Resource = type de resource, et int le nombre
  std::map<Resource::Resource, int> _resource;
  Option<Broadcast> _broadcast;
  bool _incanting;
};

#endif /* !PLAYER_HPP_ */
