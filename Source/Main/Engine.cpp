#include <iostream>
#include "Main/Engine.hpp"
#include "Main/GameEngine.hpp"

// Initializing the static attribute
GameEngine * Engine::pGameEngineInstance = nullptr;

void Engine::SetGameEngineInstance(GameEngine * pInstance)
{
    pGameEngineInstance = pInstance;
}

sf::Texture * Engine::GetTexture(const std::string & key)
{
    std::cout << pGameEngineInstance << std::endl;
    return nullptr;
}