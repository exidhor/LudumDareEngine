#include "AI/Kinematic/Kinematic.hpp"

Kinematic::Kinematic(sf::Transformable* transformable)
	: Kinematic(transformable, Vec2(), 0)
{
	// nothing
}

Kinematic::Kinematic(sf::Transformable* transformable,
					 Vec2 const& velocity,
					 float rotation)
	: TransformableLocation(transformable),
	m_velocity(velocity),
	m_rotation(rotation)
{
	// nothing
}

void Kinematic::Update(float time)
{
	TransformableLocation::Integrate(time, m_velocity, m_rotation);
}

void Kinematic::Update(float time,
					   SteeringOutput const& steering)
{
	if(steering.isKinematic)
	{
		TransformableLocation::Integrate(time, steering.linear, steering.angular);
	}
	else
	{
		Update(time);

		m_velocity += steering.linear * time;
		m_rotation += steering.angular * time;
	}
}

void Kinematic::GetNewOrientation(Vec2 const& velocity)
{
	if(m_velocity.SquareLength() > 0)
	{
		float angle_radiant = atan2(TransformableLocation::GetPosition().x,
									TransformableLocation::GetPosition().y);

		TransformableLocation::SetOrientation(angle_radiant);
	}
}