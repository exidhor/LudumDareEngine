#include "Game.hpp"

/// \brief  Default constructor
/* explicit */ Game::Game()
{
    // Code
}

/// \brief  Default destructor
Game::~Game(void)
{
    // Code
}

/// \brief  Called before engine initialization
void Game::OnPreInitialize(void)
{
    // Code
}

/// \brief  Called after engine initialization
void Game::OnPostInitialize(void)
{
    // Code
}

/// \brief  Called until there's no more event to poll
///         but always called before engine update
///         Used to process inputs
//
/// \param  dt The elapsed time since the last update
/// \param  event A reference on the event
void Game::OnPreUpdate(float dt, sf::Event& event)
{
    if(event.type == sf::Event::Closed)
    {
        // Shutdown the engine
        Engine::Shutdown();
    }
}

/// \brief  Called after engine update
///         Used to update the game
/// \brief  dt The elapsed time since the last update
void Game::OnPostUpdate(float dt)
{
    (void)dt;
}

/// \brief  Called before the engine release
void Game::OnPreExit(void)
{
    // Code
}

/// \Brief  Called after the engine release
void Game::OnPostExit(void)
{
    // Code
}