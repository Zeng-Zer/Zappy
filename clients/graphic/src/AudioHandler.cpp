#include "Error.hpp"
#include "AudioHandler.hpp"

std::unique_ptr<AudioHandler> AudioHandler::_instance(nullptr);

AudioHandler::AudioHandler() {}

AudioHandler&		AudioHandler::getInstance() {
  return *_instance;
}

void			AudioHandler::initAudioHandler()
{
  _instance.reset(new AudioHandler());
  // if (!_sounds[MUSIC].loadFromFile("./media/sounds/music.wav"))
  //   throw(Error());
}

void			AudioHandler::destroyAudioHandler()
{
  _instance.reset(nullptr);
}

sf::SoundBuffer		AudioHandler::getSound(Sound s) {return (_sounds[s]);}
