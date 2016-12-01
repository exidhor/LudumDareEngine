#include "Physic/Kinematic.hpp"

Kinematic::Kinematic(sf::Transformable* transformable)
	: m_transformable(transformable)
{
	// nothing
}

void Kinematic::Update(KinematicSteeringOutput const& steering,
					   float time)
{
	m_steering = steering;

	m_transformable->move(m_steering.velocity * time);
	rotate(m_steering.rotation * time);
}

void Kinematic::GetNewOrientation()
{
	if(m_steering.velocity.length() > 0)
	{
		float angle_radiant = atan2(m_transformable->getPosition().x,
									m_transformable->getPosition().y);
	}
}

float Kinematic::getOrientationInRadiant() const
{
	return m_transformable->getRotation() * PI / 180;
}

void Kinematic::setOrientation(float angleInRadiant)
{
	m_transformable->setRotation(angleInRadiant * 180 / PI);
}

void Kinematic::rotate(float angleInRadiant)
{
	m_transformable->rotate(angleInRadiant * 180 / PI);
}