#include "AI/Kinematic/Kinematic.hpp"

Kinematic::Kinematic(sf::Transformable* transformable)
	: Kinematic(transformable, Vec2(), 0)
{
	// nothing
}

Kinematic::Kinematic(sf::Transformable* transformable,
					 Vec2 const& velocity,
					 float rotation)
	: Location(transformable),
	m_velocity(velocity),
	m_rotation(rotation)
{
	// nothing
}

void Kinematic::Update(float time)
{
	Location::Integrate(time, m_velocity, m_rotation);
}

void Kinematic::Update(float time,
					   SteeringOutput const& steering)
{
	Update(time);

	m_velocity += steering.linear * time;
	m_rotation += steering.angular * time;
}

void Kinematic::GetNewOrientation(Vec2 const& velocity)
{
	if(m_velocity.SquareLength() > 0)
	{
		float angle_radiant = atan2(Location::GetPosition().x,
									Location::GetPosition().y);

		Location::SetOrientation(angle_radiant);
	}
}