#include "RequestBuffer.hpp"

RequestBuffer::RequestBuffer(int maxSize) : _maxSize(maxSize), _buffer() {

}

RequestBuffer::~RequestBuffer() {

}

void RequestBuffer::push(std::tuple<std::string, std::function<void(void)>> &request) {
  _buffer.push(request);
}

bool RequestBuffer::isFull() const {
  return _buffer.size() == 10;
}

int RequestBuffer::getSize() const {
  return (_buffer.size());
}
