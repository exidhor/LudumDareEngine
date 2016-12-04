#include "AI/Kinematic/KinematicEvade.hpp"


KinematicEvade::KinematicEvade(float maxSpeed,
								 const Kinematic* target,
								 float maxPredictionTime)
	: KinematicFlee(maxSpeed, nullptr),
	m_evadeTarget(target),
	m_maxPredictionTime(maxPredictionTime)
{
	//TargetedKinematicMovement::SetTargetPosition(&m_fleeLocation);
}

void KinematicEvade::GiveSteering(SteeringOutput* output,
								   Kinematic* character)
{
	// do nothing if no target
	if (!m_evadeTarget)
		return;

	// Calculate the target to delegate to flee

	// Work out the distance to target
	Vec2 direction = m_evadeTarget->GetPosition() - character->GetPosition();
	float distance = direction.Length();

	// Work out our current speed
	float speed = character->GetVelocity().Length();

	float prediction = m_maxPredictionTime;
	// Check if speed is too small to give a reasonable prediction time
	// Otherwise calculate the prediction time
	if (speed > distance / m_maxPredictionTime)
	{
		prediction = distance / speed;
	}

	// Put the target together
	Vec2 seekPosition = m_evadeTarget->GetPosition();
	seekPosition += m_evadeTarget->GetVelocity() * prediction;
	m_fleeLocation.SetPosition(seekPosition);

	TargetedKinematicSteering::SetTargetLocation(&m_fleeLocation);
	KinematicFlee::GiveSteering(output, character);
}

void KinematicEvade::SetEvadeTarget(const Kinematic* target)
{
	m_evadeTarget = target;
}

void KinematicEvade::SetMaxPredictionTime(float maxPredictionTime)
{
	m_maxPredictionTime = maxPredictionTime;
}