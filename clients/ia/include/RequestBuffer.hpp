#ifndef REQUESTBUFFER_HPP_
# define REQUESTBUFFER_HPP_

#include <functional>
#include <queue>
#include <utility>

class RequestBuffer
{
public:
  RequestBuffer(int maxSize = 10);
  ~RequestBuffer();

  /**
   * Add request in buffer
   * If there is not enough space the request is ignored
   */
  void push(std::tuple<std::string, std::function<void(void)>> &request);
  void pop();
  /**
   * return true if the buffer is full
   */
  bool isFull() const;

  int getSize() const;

private:
  int _maxSize;
  std::queue < std::tuple < std::string, std::function<void(void) > > > _buffer;
};

#endif /* !REQUESTBUFFER_HPP_ */
