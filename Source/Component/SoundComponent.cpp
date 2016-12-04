#include <Component/SoundComponent.hpp>

SoundComponent::SoundComponent()
{
    // None
}

sf::Sound * SoundComponent::GetSound()
{
    return &m_sound;
}

void SoundComponent::SetSoundBuffer(sf::SoundBuffer *buffer)
{
    m_sound.setBuffer(*buffer);
}

void SoundComponent::Play()
{
    m_sound.play();
}

void SoundComponent::Stop()
{
    m_sound.stop();
}

void SoundComponent::Pause()
{
    m_sound.pause();
}
