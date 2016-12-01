#pragma once
#include "Physic/Vec2.hpp"

class KinematicSteeringOutput
{
public :
	KinematicSteeringOutput()
		: rotation(0)
	{
		// nothing
	}

	KinematicSteeringOutput(Vec2 const& velocity,
							float rotation)
		: velocity(velocity),
		rotation(rotation)
	{
		// nothing
	}

	Vec2 velocity;
	float rotation;
};

