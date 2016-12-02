#pragma once
#include "Physic/Vec2.hpp"

class SteeringOutput
{
public :
	Vec2 linear;
	float angular;

	SteeringOutput();

	SteeringOutput(Vec2 const& linear, float angular);

private :
};

