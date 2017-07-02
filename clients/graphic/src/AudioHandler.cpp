#include "Error.hpp"
#include "AudioHandler.hpp"

std::unique_ptr<AudioHandler> AudioHandler::_instance(nullptr);

AudioHandler::AudioHandler() {}

AudioHandler::~AudioHandler() {}

AudioHandler&		AudioHandler::getInstance() {
  return *_instance;
}

void			AudioHandler::initAudioHandler()
{
  _instance.reset(new AudioHandler());
  // if (!_sounds[MUSIC].loadFromFile("./media/sounds/music.wav"))
  //   throw(Error());
}

sf::SoundBuffer		AudioHandler::getSound(Sound s) const {return (_sounds.at(s));}
