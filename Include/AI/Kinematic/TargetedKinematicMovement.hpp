#pragma once
#include "AI/Kinematic/KinematicSteering.hpp"
#include "Physic/Location/Location.hpp"
#include "Physic/Vec2.hpp"

class TargetedKinematicMovement : public KinematicSteering
{
public :
	TargetedKinematicMovement(float maxSpeed,
							  const Location* target);

	Vec2 getTargetPosition() const;

private:
	const Location* m_target;
};
