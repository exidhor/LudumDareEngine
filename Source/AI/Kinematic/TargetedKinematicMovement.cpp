#include "AI/Kinematic/TargetedKinematicMovement.hpp"

TargetedKinematicMovement::TargetedKinematicMovement(float maxSpeed,
													 const Location* target)
	: KinematicSteering(maxSpeed), 
	m_target(target)
{
	// nothing
}

Vec2 TargetedKinematicMovement::GetTargetPosition() const
{
	return m_target->GetPosition();
}

void TargetedKinematicMovement::SetTargetPosition(const Location * target)
{
	m_target = target;
}