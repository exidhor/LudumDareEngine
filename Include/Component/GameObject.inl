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
	if(m_render->IsAvailable())
		return m_render;

	return nullptr;
}

template <>
inline void GameObject::AddComponent<PhysicsComponent>(void)
{
	std::cout << "Add physic component" << std::endl;
}

template <>
inline void GameObject::AddComponent<AIComponent>(void)
{
	std::cout << "Add ai component" << std::endl;
}

template <>
inline void GameObject::RemoveComponent<PhysicsComponent>()
{
	m_physics = nullptr;
}

template <>
inline void GameObject::RemoveComponent<AIComponent>()
{
	m_ai = nullptr;
}