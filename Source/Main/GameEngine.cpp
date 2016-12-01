#include <iostream>

#include "Game.hpp"
#include "Main/Engine.hpp"
#include "Main/GameEngine.hpp"
#include "Main/EngineString.hpp"

// Default initialization
GameEngine * GameEngine::sGameEngineInstance = nullptr;

/* explicit */ GameEngine::GameEngine(void)
: m_pGame(nullptr)
, m_isInitialized(false)
{
    // Binding static instance
    sGameEngineInstance = this;
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
    // TODO
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

}

void GameEngine::OnPostUpdate(float dt)
{

}

void GameEngine::OnPreRelease(void)
{

}

void GameEngine::OnPostRelease(void)
{

}