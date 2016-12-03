#include "Main/Engine.hpp"

int main(void)
{
    // Instantiating a game engine
    GameEngine gameEngine;

    // Initialize the game engine
    gameEngine.Initialize();

    // Start the game engine
    // and enter the game loop
    gameEngine.Start();

    return 0;
}