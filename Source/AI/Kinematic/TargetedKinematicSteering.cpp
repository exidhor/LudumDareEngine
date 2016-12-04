#include "AI/Kinematic/TargetedKinematicSteering.hpp"

TargetedKinematicSteering::TargetedKinematicSteering(float maxSpeed,
													 const Location* target)
	: KinematicSteering(maxSpeed), 
	m_target(target)
{
	// nothing
}

Vec2 TargetedKinematicSteering::GetTargetPosition() const
{
	return m_target->GetPosition();
}

void TargetedKinematicSteering::SetTargetLocation(const Location * target)
{
	m_target = target;
}

float TargetedKinematicSteering::GetTargetOrientation() const
{
	return m_target->GetOrientation();
}