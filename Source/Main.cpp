#include "Main/GameEngine.hpp"
#include "Main/Engine.hpp"

int main(void)
{
    // Instantiating a new Game engine
    GameEngine gameEngine;

    // Initialize the game engine
    gameEngine.Initialize();

    // Start the game engine
    // and enter the game loop
    gameEngine.Start();


    Engine::GetTexture("");

    return 0;
}