/// \file    Engine.hpp
/// \date    01/12/2016
/// \brief   Hold all static methods
/// \author  Aredhele
/// \version 0.1.0

#ifndef __ENGINE_HPP
#define __ENGINE_HPP

// Forward declaration
class GameEngine;

#include <SFML/Graphics.hpp>

/// \class  Engine
/// \brief  Contains all static method to interact with the game engine
class Engine
{
public:

    /// \brief  Return a pointer on sf::Texture
    /// \param  key A const reference on the key of the texture
    /// \return A valid pointer on a texture if the key exists, else nullptr
    static sf::Texture * GetTexture(std::string const& key);

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
