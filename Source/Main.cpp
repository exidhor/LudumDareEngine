#include "Main/Engine.hpp"
#include "Main/GameEngine.hpp"

int main(void)
{
    // Getting an instance of the Game Engine
    GameEngine * gameEngine = GameEngine::Instance();

    // Initialize the game engine
    gameEngine->Initialize();

    // Start the game engine
    // and enter the game loop
    gameEngine->Start();


    Engine::GetTexture("");

    return 0;
}