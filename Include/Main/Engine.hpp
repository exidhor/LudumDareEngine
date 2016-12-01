/// \file    Engine.hpp
/// \date    01/12/2016
/// \brief   Hold all static methods
/// \author  Aredhele
/// \version 0.1.0

#ifndef __ENGINE_HPP
#define __ENGINE_HPP

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

    // On ajoute toutes nos méthodes ici
};

#endif // __ENGINE_HPP
