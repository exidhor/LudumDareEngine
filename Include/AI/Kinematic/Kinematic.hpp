#pragma once
#include <SFML/Graphics.hpp>
#include "AI/SteeringOutput.hpp" 
#include "Physic/Vec2.hpp"
#include "Physic/Location/TransformableLocation.hpp"

class Kinematic : public TransformableLocation
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

	Vec2 const& GetVelocity() const;

private :
	Vec2 m_velocity;
	float m_rotation;
};
