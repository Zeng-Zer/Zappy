#ifndef AUDIOHANDLER_HPP_
# define AUDIOHANDLER_HPP_

# include <SFML/Audio.hpp>
# include <map>
# include <memory>

class					AudioHandler
{
public:
  enum					Sound {  };
  enum					Music { BACKGROUND, VICTORY };

private:
  AudioHandler();

  std::map<Sound, sf::SoundBuffer>	_sounds;
  std::map<Music, sf::Music>		_musics;
  static std::unique_ptr<AudioHandler>	_instance;

public:
  ~AudioHandler();

  static AudioHandler			&getInstance();

  sf::SoundBuffer			getSound(Sound) const;
  sf::Music				&getMusic(Music);
};

#endif /* !AUDIOHANDLER_HPP_ */
