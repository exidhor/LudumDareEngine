#include "AI/Kinematic/TargetedKinematicMovement.hpp"

TargetedKinematicMovement::TargetedKinematicMovement(float maxSpeed,
													 const Location* target)
	: KinematicSteering(maxSpeed), 
	m_target(target)
{
	// nothing
}

Vec2 TargetedKinematicMovement::getTargetPosition() const
{
	return m_target->GetPosition();
}