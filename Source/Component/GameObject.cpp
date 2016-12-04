#include "Component/GameObject.hpp"
#include "Main/Engine.hpp"

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

Vec2 GameObject::GetCenteredPosition() const
{
	return m_render.GetTranformable()->getPosition() + 
		   Vec2(m_render.GetSprite()->getGlobalBounds().width / 2,
			    m_render.GetSprite()->getGlobalBounds().height / 2);
}