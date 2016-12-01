#pragma once
#include <SFML/Graphics.hpp>

class PhysicsComponent
{
public :
	PhysicsComponent(sf::Transformable* transformable);

private :
	sf::FloatRect getCollider() const;
	sf::Transformable* m_transformable;
};
