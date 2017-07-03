#include "Error.hpp"
#include "AudioHandler.hpp"

std::unique_ptr<AudioHandler> AudioHandler::_instance(nullptr);

AudioHandler::AudioHandler() {
  if (!_musics[BACKGROUND].openFromFile("./media/sounds/music.wav"))
    throw(Error());
  if (!_musics[VICTORY].openFromFile("./media/sounds/victory.wav"))
    throw(Error());
}

AudioHandler::~AudioHandler() {}

AudioHandler&		AudioHandler::getInstance() {
  if (!_instance.get()) {
    _instance.reset(new AudioHandler());
  }
  return *_instance;
}

sf::SoundBuffer		AudioHandler::getSound(Sound s) const { return (_sounds.at(s)); }
sf::Music		&AudioHandler::getMusic(Music m) { return (_musics.at(m)); }
