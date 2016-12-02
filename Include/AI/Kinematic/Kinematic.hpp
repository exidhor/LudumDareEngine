#pragma once
#include <SFML/Graphics.hpp>
#include "AI/SteeringOutput.hpp"
#include "Physic/Location.hpp"
#include "Physic/Vec2.hpp"

class Kinematic : public Location
{
public :
	Kinematic(sf::Transformable* transformable);

	Kinematic(sf::Transformable* transformable, 
			  Vec2 const& velocity, 
			  float rotation);

	void Update(float time);

	void Update(float time,
				SteeringOutput const& steering);

	void GetNewOrientation(Vec2 const& velocity);

private :
	Vec2 m_velocity;
	float m_rotation;
};
