#include "RequestBuffer.hpp"

std::unique_ptr<RequestBuffer> RequestBuffer::_instance(nullptr);

RequestBuffer::RequestBuffer() {

}

void RequestBuffer::initRequestBuffer(int maxSize) {
  _instance.reset(new RequestBuffer());
  _instance->_maxSize = maxSize;
}

void RequestBuffer::destroyRequestBuffer()
{
  _instance.reset(nullptr);
}

RequestBuffer& RequestBuffer::getInstance() {
  return *_instance;
}

void RequestBuffer::push(std::string request, std::function<void(void)> responce_function) {
  if (!isFull()) {
    Connection::getInstance().sendMsg(request);
    _buffer.push(std::make_pair(request, responce_function));
  }
}

void RequestBuffer::push(std::pair<std::string, std::function<void(void)>> request) {
  if (!isFull()) {
    Connection::getInstance().sendMsg(request.first);
    _buffer.push(request);
  }
}

bool RequestBuffer::isFull() const {
  return _buffer.size() == 10;
}

int RequestBuffer::getSize() const {
  return (_buffer.size());
}
