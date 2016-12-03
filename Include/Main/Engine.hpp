/// \file    Engine.hpp
/// \date    01/12/2016
/// \brief   Hold all static methods
/// \author  Aredhele
/// \version 0.1.0

#ifndef __ENGINE_HPP
#define __ENGINE_HPP

// Forward declaration
class GameEngine;

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

/// \class  Engine
/// \brief  Contains all static method to interact with the game engine
class Engine
{
public:

    /// \brief  Return a pointer on sf::Font
    /// \param  key A const reference on the key of the font
    /// \return A valid pointer on a font if the key exists, else nullptr
    static sf::Font * GetFont(const std::string& key);

    /// \brief  Return a pointer on sf::SoundBuffer
    /// \param  key A const reference on the key of the SoundBuffer
    /// \return A valid pointer on a SoundBuffer if the key exists, else nullptr
    static sf::SoundBuffer * GetSoundBuffer(const std::string& key);

    /// \brief  Return a pointer on sf::Texture
    /// \param  key A const reference on the texture's key
    /// \return A valid pointer on a texture if the key exists, else nullptr
    static sf::Texture * GetTexture(const std::string& key);

    /// \brief  Load a font in the font manager
    /// \param  key A const reference on the key
    /// \param  path A const reference on the path to the font
    /// \return A pointer on the new font
    static sf::Font * LoadFont(const std::string& key,
                               const std::string& path);

    /// \brief  Load a SoundBuffer in the SoundBuffer manager
    /// \param  key A const reference on the key
    /// \param  path A const reference on the path to the SoundBuffer
    /// \return A pointer on the new SoundBuffer
    static sf::SoundBuffer * LoadSoundBuffer(const std::string& key,
                                             const std::string& path);

    /// \brief  Load a Texture in the Texture manager
    /// \param  key A const reference on the key
    /// \param  path A const reference on the path to the texture
    /// \return A pointer on the new Texture
    static sf::Texture * LoadTexture(const std::string& key,
                                     const std::string& path);

    /// \brief  Unload a font
    /// \param  key A const reference on the key of the font
    static void UnloadFont(const std::string& key);

    /// \brief  Unload a soundbuffer
    /// \param  key A const reference on the key of the SoundBuffer
    static void UnloadSoundBuffer(const std::string& key);

    /// \brief  Unload a texture
    /// \param  key A const reference on the key of the texture
    static void UnloadTexture(const std::string& key);

private:
    // Encapsulating Engine
    friend class GameEngine;

    /// \brief  Set the static pointer on the game engine
    /// \param  pInstance A pointer on the game engine
    static void SetGameEngineInstance(GameEngine * pInstance);

    // Pointer on the game engine
    static GameEngine * pGameEngineInstance;
};

#endif // __ENGINE_HPP
