#include "Main/Engine.hpp"
#include "Main/GameEngine.hpp"

int main(void)
{
    // Instantiating a game engine
    GameEngine gameEngine;

    // Initialize the game engine
    gameEngine.Initialize();

    // Start the game engine
    // and enter the game loop
    gameEngine.Start();


    Engine::GetTexture("");

    return 0;
}