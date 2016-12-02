#pragma once
#include <SFML/Graphics.hpp>
#include "Physic/Vec2.hpp"

#define PI 3.14159265
#define M_2PI 6.28318530717958647692

class Location
{
public :
	virtual Vec2 GetPosition() const = 0;
	virtual float GetOrientation() const = 0;

	Vec2 GetOrientationAsVector() const
	{
		return Vec2(sin(GetOrientation()),
					cos(GetOrientation()));
	}
};
