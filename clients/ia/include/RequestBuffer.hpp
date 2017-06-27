#ifndef REQUESTBUFFER_HPP_
# define REQUESTBUFFER_HPP_

# include <string>
# include <functional>
# include <queue>
# include <utility>
# include "Connection.hpp"


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
  void push(std::string request, std::function<void(std::string&)> responce_function);
  void push(std::pair<std::string, std::function<void(std::string&)>> request);
  std::pair<std::string, std::function<void(std::string&)>> front(void) const;
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
  std::queue<std::pair<std::string, std::function<void(std::string&)>>> _buffer;
};

#endif /* !REQUESTBUFFER_HPP_ */
