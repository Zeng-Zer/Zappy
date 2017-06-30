#include "Error.hpp"
#include "AudioHandler.hpp"

zap::AudioHandler::AudioHandler() {}

zap::AudioHandler	&zap::AudioHandler::getInstance() { return (*_instance); }

void			zap::AudioHandler::initAudioHandler()
{
  _instance.reset(new AudioHandler());
  // if (!_sounds[MUSIC].loadFromFile("./media/sounds/music.wav"))
  //   throw(zap::Error());
}

void			zap::AudioHandler::destroyAudioHandler()
{
  _sounds.clear();
  _instance.reset(nullptr);
}

sf::SoundBuffer		zap::AudioHandler::getSound(Sound s) {return (_sounds[s]);}
