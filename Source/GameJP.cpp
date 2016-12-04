#include "Game.hpp"
#include "Main/Engine.hpp"

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
///         Used to construct objects
void Game::OnPostInitialize(void)
{
	// Loading the texture
	Engine::LoadTexture("Flame", "Secret.png");

	go = Engine::Allocate<GameObject>();
	go->AddComponent<RenderComponent>();
	sf::Sprite * sprite = go->GetComponent<RenderComponent>()->GetSprite();
	sprite->setTexture(*Engine::GetTexture("Flame"));
	Engine::Register(go);
	std::cout << std::endl;
}

/// \brief  Called until there's no more event to poll
///         but always called before engine update
///         Used to process inputs
//
/// \param  dt The elapsed time since the last update
/// \param  event A reference on the event
void Game::OnPollEvent(float dt, sf::Event& event)
{
	if (event.type == sf::Event::Closed)
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
	go->GetTransformable()->move(100.0f * dt, 100.0f * dt);
	go->GetTransformable()->rotate(0.5f);
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