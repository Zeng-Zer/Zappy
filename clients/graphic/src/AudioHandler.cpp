#include "Error.hpp"
#include "AudioHandler.hpp"

std::unique_ptr<AudioHandler> AudioHandler::_instance(nullptr);

AudioHandler::AudioHandler() {
  // if (!_sounds[MUSIC].loadFromFile("./media/sounds/music.wav"))
  //   throw(Error());
}

AudioHandler::~AudioHandler() {}

AudioHandler&		AudioHandler::getInstance() {
  if (!_instance.get()) {
    _instance.reset(new AudioHandler());
  }
  return *_instance;
}

sf::SoundBuffer		AudioHandler::getSound(Sound s) const {return (_sounds.at(s));}
