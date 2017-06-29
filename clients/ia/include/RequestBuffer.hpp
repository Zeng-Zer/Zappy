#ifndef REQUESTBUFFER_HPP_
# define REQUESTBUFFER_HPP_

# include <string>
# include <functional>
# include <queue>
# include <utility>
# include "Connection.hpp"

class Player;

class RequestBuffer
{
public:

  static void initRequestBuffer(int maxSize);
  static void destroyRequestBuffer(void);
  static RequestBuffer& getInstance(void);

  /**
   * Add request in buffer
   * If there is not enough space the request is ignored
   * the request is immediately sent to the server
   */
  void push(std::string const request, std::function<bool(Player&, std::string const&)> responce_function);
  void push(std::pair<std::string const, std::function<bool(Player&, std::string const&)>> request);
  std::pair<std::string const, std::function<bool(Player&, std::string const&)>> front(void) const;
  void pop(void);
  /**
   * return true if the buffer is full
   */
  bool isFull(void) const;

  int getSize(void) const;

private:

  RequestBuffer(void);

  static std::unique_ptr<RequestBuffer> _instance;

  int _maxSize;
  std::queue<std::pair<std::string const, std::function<bool(Player&, std::string const&)>>> _buffer;
};

#endif /* !REQUESTBUFFER_HPP_ */
