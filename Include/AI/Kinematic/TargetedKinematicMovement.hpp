#pragma once
#include "AI/Kinematic/KinematicMovement.hpp"

class TargetedKinematicMovement : public KinematicMovement
{
public :
	TargetedKinematicMovement(Location* character, 
							  float maxSpeed,
							  const Location* target);

	Vec2 getTargetPosition() const;

private:
	const Location* m_target;
};
