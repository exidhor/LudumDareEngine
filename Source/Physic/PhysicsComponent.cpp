#include "Physic/PhysicsComponent.hpp"

PhysicsComponent::PhysicsComponent(sf::Transformable* transformable)
	: m_transformable(transformable)
{
	// todo
}

sf::FloatRect PhysicsComponent::getCollider() const
{
	return sf::FloatRect(); // TODO: find how to store the collider
}