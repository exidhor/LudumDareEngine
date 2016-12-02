#pragma once
#include "AI/Kinematic/KinematicSteering.hpp"
#include "Physic/Location/Location.hpp"
#include "Physic/Vec2.hpp"

class TargetedKinematicMovement : public KinematicMovement
{
public :
	TargetedKinematicMovement(TransformableLocation* character,
							  float maxSpeed,
							  const Location* target);

	Vec2 getTargetPosition() const;

private:
	const Location* m_target;
};
