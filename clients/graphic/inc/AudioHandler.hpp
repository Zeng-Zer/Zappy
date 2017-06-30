#ifndef AUDIOHANDLER_HPP_
# define AUDIOHANDLER_HPP_

# include <SFML/Audio.hpp>
# include <map>

namespace				zap
{
  class					AudioHandler
  {
  public:
    enum				Sound
      {
	MUSIC // temporary
      };

  private:
    std::map<Sound, sf::SoundBuffer>	_sounds;

  public:
    AudioHandler();
    ~AudioHandler();

    void				load();
    sf::SoundBuffer			getSound(Sound);
  };
}

#endif /* !AUDIOHANDLER_HPP_ */
