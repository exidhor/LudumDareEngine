#pragma once
#include "Physic/Vec2.hpp"

class SteeringOutput
{
public :
	Vec2 linear;
	float angular;
	bool isKinematic;

	SteeringOutput();

	SteeringOutput(Vec2 const& linear, float angular, bool isKinematic = false);
};

