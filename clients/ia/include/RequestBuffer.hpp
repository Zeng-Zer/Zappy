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

  /**
   * Add request in buffer
   * If there is not enough space the request is ignored
   * the request is immediately sent to the server
   */
  void push(std::string request, std::function<void(void)> responce_function);
  void push(std::pair<std::string, std::function<void(void)>> request);
  void pop();
  /**
   * return true if the buffer is full
   */
  bool isFull() const;

  int getSize() const;
  static RequestBuffer& getInstance();

private:

  RequestBuffer(int maxSize = 10);

  static std::unique_ptr<RequestBuffer> _instance;

  int _maxSize;
  std::queue<std::pair<std::string, std::function<void(void)>>> _buffer;
};

#endif /* !REQUESTBUFFER_HPP_ */
