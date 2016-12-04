/// \file    SoundComponent.hpp
/// \date    04/12/2016
/// \brief   Sound component header
/// \author  Aredhele
/// \version 0.1.0

#ifndef __SOUND_COMPONENT_HPP
#define __SOUND_COMPONENT_HPP

#include <SFML/Audio.hpp>

/// \class  SoundComponent
/// \brief  Handle the sound of an object
class SoundComponent
{
public :
	SoundComponent();

    void SetSoundBuffe(sf::SoundBuffer * buffer);
    sf::Sound * GetSound();
    void Play();
    void Stop();
    void Pause();

private :
    sf::Sound m_sound;
};

#endif // __SOUND_COMPONENT_HPP
