/// \file    Game.hpp
/// \date    30/11/2016
/// \brief   Contains the main game class header
/// \author  Aredhele
/// \version 0.1.0

#ifndef __GAME_HPP
#define __GAME_HPP

/// \class  Game
/// \brief  Adapter class between engine and user
class Game
{
public:

    /// \brief  Default constructor
    explicit Game(void);

    /// \brief  Default destructor
    virtual ~Game(void);

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

#endif // __GAME_HPP
