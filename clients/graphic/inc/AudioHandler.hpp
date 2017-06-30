#ifndef AUDIOHANDLER_HPP_
# define AUDIOHANDLER_HPP_

# include <SFML/Audio.hpp>
# include <map>
# include <memory>

namespace				zap
{
  class					AudioHandler
  {
  public:
    enum				Sound { MUSIC }; //temp

  private:
    AudioHandler();

    std::map<Sound, sf::SoundBuffer>	_sounds;
    std::unique_ptr<AudioHandler>	_instance;

  public:
    static AudioHandler			&getInstance();
    static void				initAudioHandler();
    static void				destroyAudioHandler();

    sf::SoundBuffer			getSound(Sound);
  };
}

#endif /* !AUDIOHANDLER_HPP_ */
