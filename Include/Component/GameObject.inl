#include "Main/Engine.hpp"

template <typename T>
inline T * GameObject::GetComponent(void)
{
	// Call template specialization
	return GetComponent<T>();
}

template <typename T>
inline void GameObject::AddComponent(void)
{
	// Call template specialization
	AddComponent<T>();
}

template <typename T>
inline void GameObject::RemoveComponent()
{
	// Call template specialization
	RemoveComponent<T>();
}

template <>
inline PhysicsComponent * GameObject::GetComponent<PhysicsComponent>(void)
{
	return m_physics;
}

template <>
inline AIComponent * GameObject::GetComponent<AIComponent>(void)
{
	return m_ai;
}

template <>
inline RenderComponent * GameObject::GetComponent<RenderComponent>(void)
{
	if(m_render.IsAvailable())
		return &m_render;

	return nullptr;
}

template <>
inline void GameObject::AddComponent<RenderComponent>(void)
{
    m_render.Enable();
}

template <>
inline void GameObject::AddComponent<PhysicsComponent>(void)
{
    m_physics = Engine::Allocate<PhysicsComponent>();
    m_physics->Init(this);
}

template <>
inline void GameObject::AddComponent<AIComponent>(void)
{
    m_ai = Engine::Allocate<AIComponent>();
    m_ai->Init(this);
}

template <>
inline void GameObject::RemoveComponent<PhysicsComponent>()
{
    Engine::Deallocate<PhysicsComponent>(m_physics);
	m_physics = nullptr;
}

template <>
inline void GameObject::RemoveComponent<AIComponent>()
{
    Engine::Deallocate<AIComponent>(m_ai);
	m_ai = nullptr;
}

template <>
inline void GameObject::RemoveComponent<RenderComponent>()
{
    m_render.Disable();
}