#include "RequestBuffer.hpp"

std::unique_ptr<RequestBuffer> RequestBuffer::_instance(nullptr);

RequestBuffer::RequestBuffer(void) {
}

void RequestBuffer::initRequestBuffer(int maxSize) {
  _instance.reset(new RequestBuffer());
  _instance->_maxSize = maxSize;
}

RequestBuffer& RequestBuffer::getInstance(void) {
  return *_instance;
}

void RequestBuffer::push(std::string const request, std::function<bool(Player&, std::string const&)> responce_function) {
  if (!isFull()) {
    Connection::getInstance().sendMsg(request);
    _buffer.push(std::make_pair(request, responce_function));
  }
}

void RequestBuffer::push(std::pair<std::string const, std::function<bool(Player&, std::string const&)>> request) {
  if (!isFull()) {
    Connection::getInstance().sendMsg(request.first);
    _buffer.push(request);
  }
}

std::pair<std::string const, std::function<bool(Player&, std::string const&)>> RequestBuffer::front(void) const {
  return _buffer.front();
}

void RequestBuffer::pop(void) {
  _buffer.pop();
}

bool RequestBuffer::isFull(void) const {
  return _buffer.size() == 10;
}

int RequestBuffer::getSize(void) const {
  return (_buffer.size());
}
