#include "Physic/Location.hpp"

Location::Location(sf::Transformable * transformable)
	: m_transformable(transformable)
{
	// nothing
}

void Location::Integrate(float time, Vec2 const& velocity, float rotation)
{
	SetPosition(velocity * time);
	
	float orientation = rotation * time;
	orientation = fmodf(orientation, M_2PI);

	SetOrientation(orientation);
}

void Location::SetPosition(Vec2 const& position)
{
	m_transformable->setPosition(position);
}

void Location::SetPosition(float x, float y)
{
	SetPosition(Vec2(x, y));
}

void Location::Move(Vec2 const& offset)
{
	m_transformable->move(offset);
}

void Location::Move(float offset_x, float offset_y)
{
	Move(Vec2(offset_x, offset_y));
}

void Location::SetOrientation(float angleInRadiant)
{
	m_transformable->setRotation(angleInRadiant * 180 / PI);
}

void Location::Rotate(float angleInRadiant)
{
	m_transformable->rotate(angleInRadiant * 180 / PI);
}

Vec2 Location::GetPosition() const
{
	return m_transformable->getPosition();
}

float Location::GetOrientation() const
{
	return m_transformable->getRotation() * PI / 180;
}

Vec2 Location::GetOrientationAsVector() const
{
	return Vec2(sin(GetOrientation()),
				cos(GetOrientation()));
}
