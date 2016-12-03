#include "AI/Kinematic/KinematicSteering.hpp"

KinematicSteering::KinematicSteering(float maxSpeed)
	: m_maxSpeed(maxSpeed)
{
	// nothing
}

void KinematicSteering::SetMaxSpeed(float maxSpeed)
{
	m_maxSpeed = maxSpeed;
}

float KinematicSteering::GetMaxSpeed() const
{
	return m_maxSpeed;
}