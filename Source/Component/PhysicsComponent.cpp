#include "Component/PhysicsComponent.hpp"
#include "Component/GameObject.hpp"

PhysicsComponent::PhysicsComponent(Vec2 const& paddingCollider)
	: m_transformable(nullptr),
	m_paddingCollider(paddingCollider)
{
	// nothing
}

PhysicsComponent::PhysicsComponent(sf::Transformable* transformable)
	: m_transformable(transformable),
	m_paddingCollider(1, 1)
{
	// nothing
}

void PhysicsComponent::Init(GameObject* parent)
{
	m_parent = parent;

	m_transformable = m_parent->GetTransformable();
}

sf::FloatRect PhysicsComponent::getCollider() const
{
	return sf::FloatRect(m_transformable->getPosition() - m_paddingCollider, 
						 m_paddingCollider * 2);
}

void PhysicsComponent::SetPaddingCollider(float padding_x, float padding_y)
{
	m_paddingCollider.x = padding_x;
	m_paddingCollider.y = padding_y;
}