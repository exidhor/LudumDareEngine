/// \file    GameEngine.hpp
/// \date    25/11/2016
/// \brief   Contains the game engine header
/// \author  Aredhele
/// \version 0.1.0

#ifndef __GAME_ENGINE_HPP
#define __GAME_ENGINE_HPP

// Forward declaration
class Game;

#include "Main/Singleton.hpp"
#include "Memory/Container.hpp"

/// \class  GameEngine
/// \brief  Main class of the engine
class GameEngine
{
public:

    /// \brief  Default constructor
    explicit GameEngine(void);

    /// \brief  Default destructor
    virtual ~GameEngine(void);

    /// \brief  Initialize the game engine
    void Initialize(void);

    /// \brief  Start the internal engine cycle
    void Start(void);

private:

    Game * m_pGame;             ///< The game user class
    bool   m_isRunning;         ///< Tells if the game is running
    bool   m_isInitialized;     ///< The status of the game engine

    // Encapsulate class GameEngine
    friend class Engine;

    Container < sf::Font        > m_fontContainer;        ///< The font container
    Container < sf::Texture     > m_textureContainer;     ///< The texture container
    Container < sf::SoundBuffer > m_soundBufferContainer; ///< The sound container

    /// \brief   Fixed update (ups = update per second)
    ///          16.67 =  60 ups
    ///          11.11 =  90 ups
    ///           8.33 = 120 ups
    ///           4.16 = 240 ups
    const double SECONDS_PER_UPDATE = 1.0 / 120.0;

    /// \brief  Contains the game loop
    void Run(void);

    /// \brief  Called before engine initialization
    void OnPreInitialize(void);

    /// \brief  Called after engine initialization
    void OnPostInitialize(void);

    /// \brief  Called before engine update
    void OnPreUpdate(float dt);

    /// \brief  Called on engine update
    void Update(float dt);

    /// \brief  Called after engine update
    /// \brief  dt The elapsed time since the last update
    void OnPostUpdate(float dt);

    /// \brief  Called before the engine release
    void OnPreExit(void);

    /// \brief  Called on engine exit
    void Exit(void);

    /// \Brief  Called after the engine release
    void OnPostExit(void);
};

#endif // __GAME_ENGINE_HPP