/// \file    Engine.hpp
/// \date    01/12/2016
/// \brief   Hold all static methods
/// \author  Aredhele
/// \version 0.1.0

#ifndef __ENGINE_HPP
#define __ENGINE_HPP

#ifdef MVS
    #define DEFAULT_TEXTURE_PATH "../LudumDare_Asset/Res/"
#else
    #define DEFAULT_TEXTURE_PATH ""
#endif

// Forward declaration
class GameEngine;
class GameObject;

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

/// \class  Engine
/// \brief  Contains all static method to interact with the game engine
class Engine
{
public:

    /// \brief  Shutdown the engine
    static void Shutdown();

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

    /// \brief  Allocate a resource of type T from game engine allocators
    /// \return A pointer on the resource, else nullptr
    template <typename T> static T * Allocate();

    /// \brief  Deallocate a resource of type T, if the pointer isn't valid,
    ///         nothing will happen
    /// \param A pointer on the resource to deallocate
    template <typename T> static void Deallocate(T * object);

    /// \brief  Return a pointer on the window
    /// \return A pointer on the window
    static sf::RenderWindow * GetWindow();

    /// \brief   Add a GameObject to the Active GameObject.
    ///          Now it can is available for all the Engine
    /// \param	gameObject : the GameObject to register
    static void Register(GameObject * gameObject);

    /// \brief	Remove a GameObject from the Active GameObject
    /// \param	gameObject : the GameObject to remove
    /// \return	True if the GameObject was removed, False otherwise
    static bool Unregister(GameObject * gameObject);

    /// \brief	Return all the GameObject which are in the same layer
    ///         from the Active GameObject.
    /// \param	layer : the layer we want
    /// \param	output : all the GameObject found are stored into this vector
    void GetLayer(int layer, std::vector<GameObject*> & output) const;

private:

    // Encapsulating Engine
    friend class GameEngine;

    /// \brief  Set the static pointer on the game engine
    /// \param  pInstance A pointer on the game engine
    static void SetGameEngineInstance(GameEngine * pInstance);

    // Pointer on the game engine
    static GameEngine * pGameEngineInstance;

    /// \brief   Return the complete path depending the compiler
    static std::string GetCompletePath(std::string const& path);
};

#include "Main/Engine.inl"

#endif // __ENGINE_HPP
