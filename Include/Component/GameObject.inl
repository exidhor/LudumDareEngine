#include "Component/GameObject.hpp"

inline /* explicit */ GameObject::GameObject(void)
{
    // None
}

inline /* virtual */ GameObject::~GameObject(void)
{
    // None
}

template <typename T>
inline T * GameObject::GetComponent(void)
{
    // Call template specialization
    return __GetComponent<T>();
}

template <typename T>
inline void GameObject::AddComponent(void)
{
    // Call template specialization
    __AddComponent<T>();
}

template <typename T>
inline T * GameObject::__GetComponent(void)
{
    std::cout << "Not a component" << std::endl;
    return nullptr;
}

template <typename T>
void GameObject::__AddComponent(void)
{
    std::cout << "Not a component" << std::endl;
}

template <>
inline PhysicsComponent * GameObject::__GetComponent<PhysicsComponent>(void)
{
    std::cout << "Physic component" << std::endl;
    return nullptr;
}

inline AIComponent * GameObject::__GetComponent<AIComponent>(void)
{
    std::cout << "AI component" << std::endl;
    return nullptr;
}

template <>
void GameObject::__AddComponent<PhysicsComponent>(void)
{
    std::cout << "Add physic component" << std::endl;
}

template <>
void GameObject::__AddComponent<AIComponent>(void)
{
    std::cout << "Add ai component" << std::endl;
}