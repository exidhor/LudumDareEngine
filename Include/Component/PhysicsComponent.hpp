#pragma once
#include <SFML/Graphics.hpp>
#include "Physic/Vec2.hpp"

class GameObject;

class PhysicsComponent
{
public :
	PhysicsComponent(Vec2 const& paddingCollider);

	PhysicsComponent(sf::Transformable* transformable = nullptr);

	void Init(GameObject* parent);

	sf::FloatRect getCollider() const;

	void SetPaddingCollider(float padding_x, float padding_y);

private :
	Vec2 m_paddingCollider;

	sf::Transformable* m_transformable;

	GameObject * m_parent;
};
