#include <iostream>

#include "Game.hpp"
#include "Main/Engine.hpp"
#include "Main/GameEngine.hpp"
#include "Main/EngineString.hpp"

/* explicit */ GameEngine::GameEngine(void)
: m_pGame(nullptr)
, m_isInitialized(false)
{
    // None
}

GameEngine::~GameEngine(void)
{
    // TODO
}

void GameEngine::Start(void)
{
    // Checking status
    if(!m_isInitialized)
    {
        std::cerr << EngineString::ENGINE_FAILURE_START << std::endl;
        return;
    }


    // Enter the game loop
    Run();
}

void GameEngine::Run(void)
{
    m_isRunning = true;

    sf::Clock clock;
    double lag = 0.0;
    double previous = clock.getElapsedTime().asSeconds();

    while(m_isRunning)
    {
        double current = clock.getElapsedTime().asSeconds();
        double elapsed = current - previous;
        previous = current;

        lag += elapsed;

        while(lag >= SECONDS_PER_UPDATE)
        {
            // Updating
            Update((float)SECONDS_PER_UPDATE);

            // Retrieve elapsed time
            lag -= SECONDS_PER_UPDATE;
        }
    }

    // Exiting game engine
    Exit();
}

void GameEngine::OnPreInitialize(void)
{
    // Calling callback method to warn about
    // the start of engine initialization
    m_pGame->OnPreInitialize();
}

void GameEngine::Initialize(void)
{
    // See OnPreInitialize
    OnPreInitialize();

    // Checking status
    if(m_isInitialized)
    {
        std::cerr << EngineString::ENGINE_FAILURE_INIT << std::endl;
        return;
    }

    // Setting the game engine instance
    m_isInitialized = true;
    Engine::pGameEngineInstance = this;

    // See OnPostInitialize
    OnPostInitialize();
}

void GameEngine::OnPostInitialize(void)
{
    // Calling callback method to warn about
    // the end of engine initialization
    m_pGame->OnPostInitialize();
}

void GameEngine::OnPreUpdate(float dt)
{
    // Calling callback method to permit
    // the user to process input
    m_pGame->OnPreUpdate(dt);
}

void GameEngine::Update(float dt)
{
    OnPreUpdate(dt);
    OnPostUpdate(dt);
}

void GameEngine::OnPostUpdate(float dt)
{
    // Calling callback method to permit
    // the user to update the game
    m_pGame->OnPostUpdate(dt);
}

void GameEngine::OnPreExit(void)
{
    // Calling callback method to warn about
    // the engine pre exit
    m_pGame->OnPreExit();
}

void GameEngine::Exit(void)
{
    OnPreExit();
    OnPostExit();
}

void GameEngine::OnPostExit(void)
{
    // Calling callback method to warn about
    // the engine post exit
    m_pGame->OnPostExit();
}
