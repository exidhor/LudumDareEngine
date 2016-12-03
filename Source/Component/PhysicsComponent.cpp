#include "Component/PhysicsComponent.hpp"
#include "Component/GameObject.hpp"

PhysicsComponent::PhysicsComponent(sf::Transformable* transformable)
	: m_transformable(transformable)
{
	// todo
}

void PhysicsComponent::Init(GameObject* parent)
{
	m_parent = parent;

	m_transformable = m_parent->GetTransformable();
}

sf::FloatRect PhysicsComponent::getCollider() const
{
	return sf::FloatRect(); // TODO: find how to store the collider
}