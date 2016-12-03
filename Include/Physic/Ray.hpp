#pragma once
#include "Physic/Vec2.hpp"

class Ray
{
public:
	Vec2 start;
	Vec2 end;

	Ray();

	Ray(Vec2 const& start, Vec2 const& end);

	// todo : add other usefull functions like length ...
};

#include "Physic/Ray.inl"