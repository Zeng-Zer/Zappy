#include "Error.hpp"
#include "AudioHandler.hpp"

std::unique_ptr<AudioHandler> AudioHandler::_instance(nullptr);

AudioHandler::AudioHandler() {
  if (!_musics[MUSIC].openFromFile("./media/sounds/music.ogg"))
    throw(Error());
  if (!_musics[VICTORY].openFromFile("./media/sounds/victory.ogg"))
    throw(Error());
  if (!_musics[POKEMON].openFromFile("./media/sounds/pokemon.ogg"))
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
