#include "Physic/Location/TransformableLocation.hpp"

TransformableLocation::TransformableLocation(sf::Transformable * transformable)
	: m_transformable(transformable)
{
	// nothing
}

void TransformableLocation::Integrate(float time, Vec2 const& velocity, float rotation)
{
	SetPosition(velocity * time);

	float orientation = rotation * time;
	orientation = fmodf(orientation, M_2PI);

	SetOrientation(orientation);
}

void TransformableLocation::SetPosition(Vec2 const& position)
{
	m_transformable->setPosition(position);
}

void TransformableLocation::SetPosition(float x, float y)
{
	SetPosition(Vec2(x, y));
}

void TransformableLocation::Move(Vec2 const& offset)
{
	m_transformable->move(offset);
}

void TransformableLocation::Move(float offset_x, float offset_y)
{
	Move(Vec2(offset_x, offset_y));
}

void TransformableLocation::SetOrientation(float angleInRadiant)
{
	m_transformable->setRotation(angleInRadiant * 180 / PI);
}

void TransformableLocation::Rotate(float angleInRadiant)
{
	m_transformable->rotate(angleInRadiant * 180 / PI);
}

Vec2 TransformableLocation::GetPosition() const
{
	return m_transformable->getPosition();
}

float TransformableLocation::GetOrientation() const
{
	return m_transformable->getRotation() * PI / 180;
}