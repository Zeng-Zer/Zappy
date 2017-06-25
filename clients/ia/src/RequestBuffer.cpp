#include "RequestBuffer.hpp"

std::unique_ptr<RequestBuffer> RequestBuffer::_instance(nullptr);

RequestBuffer::RequestBuffer(void) {

}

void RequestBuffer::initRequestBuffer(int maxSize) {
  _instance.reset(new RequestBuffer());
  _instance->_maxSize = maxSize;
}

void RequestBuffer::destroyRequestBuffer(void)
{
  _instance.reset(nullptr);
}

RequestBuffer& RequestBuffer::getInstance(void) {
  return *_instance;
}

void RequestBuffer::push(std::string request, std::function<void(std::string)> responce_function) {
  if (!isFull()) {
    Connection::getInstance().sendMsg(request);
    _buffer.push(std::make_pair(request, responce_function));
  }
}

void RequestBuffer::push(std::pair<std::string, std::function<void(std::string)>> request) {
  if (!isFull()) {
    Connection::getInstance().sendMsg(request.first);
    _buffer.push(request);
  }
}

std::pair<std::string, std::function<void(std::string)>> RequestBuffer::front(void) const {
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
