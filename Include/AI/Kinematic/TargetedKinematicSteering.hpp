#pragma once
#include "AI/Kinematic/KinematicSteering.hpp"
#include "Physic/Location/Location.hpp"
#include "Physic/Vec2.hpp"

class TargetedKinematicSteering : public KinematicSteering
{
public :
	TargetedKinematicSteering(float maxSpeed,
							  const Location* target);

	Vec2 GetTargetPosition() const;

	void SetTargetPosition(const Location * target);

private:
	const Location* m_target;
};
