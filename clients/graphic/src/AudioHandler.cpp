#include "Error.hpp"
#include "AudioHandler.hpp"

AudioHandler AudioHandler::_instance;

AudioHandler::AudioHandler() {
  // if (!_sounds[MUSIC].loadFromFile("./media/sounds/music.wav"))
  //   throw(Error());
}

AudioHandler::~AudioHandler() {}

AudioHandler&		AudioHandler::getInstance() {
  return _instance;
}

sf::SoundBuffer		AudioHandler::getSound(Sound s) const {return (_sounds.at(s));}
