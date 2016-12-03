#pragma once
#include <SFML/Graphics.hpp>
#include "Physic/Vec2.hpp"
#include "Physic/Location/Location.hpp"

#define PI 3.14159265
#define M_2PI 6.28318530717958647692

class TransformableLocation : public Location
{
public:
	TransformableLocation(sf::Transformable * transformable);

	void Integrate(float time, Vec2 const& velocity, float rotation);

	void SetPosition(Vec2 const& position);
	void SetPosition(float x, float y);
	void Move(Vec2 const& offset);
	void Move(float offset_x, float offset_y);
	void SetOrientation(float angleInRadiant);
	void Rotate(float angleInRadiant);

	Vec2 GetPosition() const override;
	float GetOrientation() const override;

private:
	sf::Transformable * m_transformable;
};
