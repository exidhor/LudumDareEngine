
#include "AI/Kinematic/KinematicPursue.hpp"


KinematicPursue::KinematicPursue(float maxSpeed,
								 const Kinematic* target,
								 float maxPredictionTime)
	: KinematicSeek(maxSpeed, nullptr),
	m_pursueTarget(target),
	m_maxPredictionTime(maxPredictionTime)
{
	//TargetedKinematicMovement::SetTargetPosition(&m_seekLocation);
}

void KinematicPursue::GiveSteering(SteeringOutput* output,
								   Kinematic* character)
{
	// do nothing if no target
	if (!m_pursueTarget)
		return;

	// Calculate the target to delegate to seek

	// Work out the distance to target
	Vec2 direction = m_pursueTarget->GetPosition() - character->GetPosition();
	float distance = direction.Length();

	// Work out our current speed
	float speed = character->GetVelocity().Length();

	float prediction = m_maxPredictionTime;
	// Check if speed is too small to give a reasonable prediction time
	// Otherwise calculate the prediction time
	if(speed > distance / m_maxPredictionTime)
	{
		prediction = distance / speed;
	}

	// Put the target together
	Vec2 seekPosition = m_pursueTarget->GetPosition();
	seekPosition += m_pursueTarget->GetVelocity() * prediction;
	m_seekLocation.SetPosition(seekPosition);

	TargetedKinematicMovement::SetTargetPosition(&m_seekLocation);
	KinematicSeek::GiveSteering(output, character);
}

void KinematicPursue::SetPursueTarget(const Kinematic* target)
{
	m_pursueTarget = target;
}

void KinematicPursue::SetMaxPredictionTime(float maxPredictionTime)
{
	m_maxPredictionTime = maxPredictionTime;
}