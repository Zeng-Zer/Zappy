#include "Error.hpp"
#include "AudioHandler.hpp"

zap::AudioHandler::AudioHandler() {}

zap::AudioHandler::~AudioHandler()
{
  _sounds.clear();
}

void			zap::AudioHandler::load()
{
  // if (!_sounds[MUSIC].loadFromFile("./media/sounds/music.wav"))
  //   throw(zap::Error());
}

sf::SoundBuffer		zap::AudioHandler::getSound(Sound s) {return (_sounds[s]);}
