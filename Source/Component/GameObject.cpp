#include "Component/GameObject.hpp"

/* explicit */ GameObject::GameObject(void)
: m_layer(-1),
m_ai(nullptr),
m_physics(nullptr),
m_render()
{
	// None
}

/* virtual */ GameObject::~GameObject(void)
{
	// None
}

void GameObject::SetLayer(int layer)
{
	m_layer = layer;
}

int GameObject::GetLayer() const
{
	return m_layer;
}

sf::Transformable* GameObject::GetTransformable()
{
	return m_render.GetTranformable();
}