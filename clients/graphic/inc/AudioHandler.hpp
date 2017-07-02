#ifndef AUDIOHANDLER_HPP_
# define AUDIOHANDLER_HPP_

# include <SFML/Audio.hpp>
# include <map>
# include <memory>

class					AudioHandler
{
public:
  enum					Sound { MUSIC }; //temp

private:
  AudioHandler();

  std::map<Sound, sf::SoundBuffer>	_sounds;
  static AudioHandler			_instance;

public:
  ~AudioHandler();

  static AudioHandler			&getInstance();

  sf::SoundBuffer			getSound(Sound) const;
};

#endif /* !AUDIOHANDLER_HPP_ */
