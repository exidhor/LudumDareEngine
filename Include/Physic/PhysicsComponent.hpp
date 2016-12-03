#pragma once
#include <SFML/Graphics.hpp>

class PhysicsComponent
{
public :
	PhysicsComponent(sf::Transformable* transformable);

	sf::FloatRect getCollider() const;

private :
	sf::Transformable* m_transformable;
};
