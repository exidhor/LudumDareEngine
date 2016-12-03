#pragma once
#include <SFML/Graphics.hpp>

class GameObject;

class PhysicsComponent
{
public :
	PhysicsComponent(sf::Transformable* transformable = nullptr);

	void Init(GameObject* parent);

	sf::FloatRect getCollider() const;

private :
	sf::Transformable* m_transformable;

	GameObject * m_parent;
};
