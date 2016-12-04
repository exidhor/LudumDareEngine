#include <iostream>
#include "Game.hpp"
#include "Main/World.hpp"

/* explicit */ GameEngine::GameEngine(void)
: m_pGame(nullptr)
, m_isRunning(false)
, m_isInitialized(false)
, m_pWorld(nullptr)
, m_pWindow(nullptr)
{
    // None
}

GameEngine::~GameEngine(void)
{
    if(m_pGame != nullptr) delete m_pGame;
    if(m_pWorld != nullptr) delete m_pWorld;
    if(m_pWindow != nullptr) delete m_pWindow;
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

        OnPreUpdate((float)elapsed);

        while(lag >= SECONDS_PER_UPDATE)
        {
            // Updating
            Update((float)SECONDS_PER_UPDATE);

            // Retrieve elapsed time
            lag -= SECONDS_PER_UPDATE;

            // Rendering
            Render();
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
    // World
    // Allocating engine object
    m_pWorld = new World(ENGINE_DEFAULT_WORLD_OBJECT_COUNT);

    // Window
    m_pWindow = new sf::RenderWindow(
            sf::VideoMode(ENGINE_DEFAULT_WINDOW_SIZE_X,
                          ENGINE_DEFAULT_WINDOW_SIZE_Y),
                          ENGINE_DEFAULT_WINDOW_NAME);

    // Game class
    m_pGame = new Game();

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

    // Initializing pool allocators
    InitializeMemory();

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
    sf::Event event;
    while (m_pWindow->pollEvent(event))
        m_pGame->OnPollEvent(dt, event);
}

void GameEngine::Update(float dt)
{
    OnPostUpdate(dt);
}

void GameEngine::OnPostUpdate(float dt)
{
    // Calling callback method to permit
    // the user to update the game
    m_pGame->OnPostUpdate(dt);
}

void GameEngine::Render(void)
{
    // Clear the buffer
    m_pWindow->clear(sf::Color::Black);

    // Getting renderer and draw them
    m_renderers_cache.clear();
    m_pWorld->GetRenders(m_renderers_cache);

    for(const auto& it : m_renderers_cache)
        m_pWindow->draw(*it->GetComponent<RenderComponent>());

    // Swap the buffer
    m_pWindow->display();
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

void GameEngine::InitializeMemory(void)
{
    m_spriteAllocator.Init(ENGINE_DEFAULT_POOL_SIZE);
    m_gameObjectAllocator.Init(ENGINE_DEFAULT_POOL_SIZE);
    m_aiComponentAllocator.Init(ENGINE_DEFAULT_POOL_SIZE);
    m_renderComponentAllocator.Init(ENGINE_DEFAULT_POOL_SIZE);
    m_physicComponentAllocator.Init(ENGINE_DEFAULT_POOL_SIZE);
}
