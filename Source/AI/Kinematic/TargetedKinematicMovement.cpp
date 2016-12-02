#include "AI/Kinematic/TargetedKinematicMovement.hpp"

TargetedKinematicMovement::TargetedKinematicMovement(Location* character,
													 float maxSpeed,
													 const Location* target)
	: KinematicMovement(character, maxSpeed), 
	m_target(target)
{
	// nothing
}

Vec2 TargetedKinematicMovement::getTargetPosition() const
{
	return m_target->GetPosition();
}