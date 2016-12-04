#include "Main/GameEngine.hpp"

template <typename T>
inline T * Engine::Allocate()
{
    // Generic version, wrong template argument
    return nullptr;
}

template <>
inline sf::Sprite * Engine::Allocate<sf::Sprite>()
{
    // sf::Sprite specialization
    return pGameEngineInstance->m_spriteAllocator.Allocate();
}

template <>
inline GameObject * Engine::Allocate<GameObject>()
{
    // GameObject specialization
    return pGameEngineInstance->m_gameObjectAllocator.Allocate();
}

template <>
inline AIComponent * Engine::Allocate<AIComponent>()
{
    // AIComponent specialization
    return pGameEngineInstance->m_aiComponentAllocator.Allocate();
}

template <>
inline RenderComponent * Engine::Allocate<RenderComponent>()
{
    // RenderComponent specialization
    return pGameEngineInstance->m_renderComponentAllocator.Allocate();
}

template <>
inline PhysicsComponent * Engine::Allocate<PhysicsComponent>()
{
    // PhysicsComponent specialization
    return pGameEngineInstance->m_physicComponentAllocator.Allocate();
}

template <>
inline SoundComponent * Engine::Allocate<SoundComponent>()
{
    // SoundComponent specialization
    return pGameEngineInstance->m_soundComponentAllocator.Allocate();
}

template <typename T>
inline void Engine::Deallocate(T * object)
{
    // Generic version, wrong template argument
}

template <>
inline void Engine::Deallocate<sf::Sprite>(sf::Sprite * object)
{
    // sf::Sprite specialization
    pGameEngineInstance->m_spriteAllocator.Deallocate(object);
}

template <>
inline void Engine::Deallocate<GameObject>(GameObject * object)
{
    // GameObject specialization
    pGameEngineInstance->m_gameObjectAllocator.Deallocate(object);
}

template <>
inline void Engine::Deallocate<AIComponent>(AIComponent * object)
{
    // AIComponent specialization
    pGameEngineInstance->m_aiComponentAllocator.Deallocate(object);
}

template <>
inline void Engine::Deallocate<RenderComponent>(RenderComponent * object)
{
    // RenderComponent specialization
    pGameEngineInstance->m_renderComponentAllocator.Deallocate(object);
}

template <>
inline void Engine::Deallocate<PhysicsComponent>(PhysicsComponent * object)
{
    // PhysicsComponent specialization
    pGameEngineInstance->m_physicComponentAllocator.Deallocate(object);
}

template <>
inline void Engine::Deallocate<SoundComponent>(SoundComponent * object)
{
    // SoundComponent specialization
    pGameEngineInstance->m_soundComponentAllocator.Deallocate(object);
}