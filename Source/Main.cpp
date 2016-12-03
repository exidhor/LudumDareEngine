#include "Main/Engine.hpp"
#include "Main/GameEngine.hpp"
#include "Component/GameObject.hpp"

int main(void)
{
    /*GameObject go;
    go.AddComponent<std::string>();
    go.AddComponent<PhysicsComponent>();*/

    // Instantiating a game engine
    GameEngine gameEngine;

    // Initialize the game engine
    gameEngine.Initialize();

    // Start the game engine
    // and enter the game loop
    gameEngine.Start();

    return 0;
}