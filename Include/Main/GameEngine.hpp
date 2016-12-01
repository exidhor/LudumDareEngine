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

/// \class  GameEngine
/// \brief  Main class of the engine
class GameEngine : public Singleton<GameEngine>
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

    Game * m_pGame;         ///< The game user class
    bool   m_isInitialized; ///< The status of the game engine

    /// \brief  Contains the game loop
    void Run(void);

    /// \brief  Called before engine initialization
    void OnPreInitialize(void);

    /// \brief  Called after engine initialization
    void OnPostInitialize(void);

    /// \brief  Called before engine update
    void OnPreUpdate(float dt);

    /// \brief  Called after engine update
    /// \brief  dt The elapsed time since the last update
    void OnPostUpdate(float dt);

    /// \brief  Called before the engine release
    void OnPreRelease(void);

    /// \Brief  Called after the engine release
    void OnPostRelease(void);
};

#endif // __GAME_ENGINE_HPP