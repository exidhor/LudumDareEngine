#include "AI/Kinematic/KinematicBehaviors.hpp"

void KinematicHelper::ClipToMax_CheckZero(Vec2 * linear, float maxSpeed)
{
	// If there is no direction, do nothing
	if (linear->SquareLength() > 0)
	{
		linear->Normalise();
		(*linear) *= maxSpeed;
	}
}

void KinematicHelper::ClipToMax_CheckMax(Vec2 * linear, float maxSpeed)
{
	// If that is too fast, then clip the speed
	if (linear->SquareLength() > maxSpeed * maxSpeed)
	{
		linear->Normalise();
		(*linear) *= maxSpeed;
	}
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||				KINEMATIC SEEK                   |||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||

KinematicSeek::KinematicSeek(float maxSpeed,
							 const Location* target)
	: TargetedKinematicMovement(maxSpeed, target)
{ }

void KinematicSeek::GiveSteering(SteeringOutput* output,
								 TransformableLocation* character) const
{
	output->isKinematic = true;

	// First work out the direction
	output->linear = TargetedKinematicMovement::getTargetPosition();
	output->linear -= character->GetPosition();

	// If there is no direction, do nothing
	KinematicHelper::ClipToMax_CheckZero(&output->linear,
										 KinematicSteering::GetMaxSpeed());
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||				KINEMATIC FLEE                   |||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||

KinematicFlee::KinematicFlee(float maxSpeed,
							 const Location* target)
	: KinematicSeek(maxSpeed, target)
{ }

void KinematicFlee::GiveSteering(SteeringOutput* output,
								 TransformableLocation* character) const
{
	output->isKinematic = true;

	// First work out the direction
	output->linear = character->GetPosition();
	output->linear -= TargetedKinematicMovement::getTargetPosition();

	// If there is no direction, do nothing
	KinematicHelper::ClipToMax_CheckZero(&output->linear,
										 KinematicSteering::GetMaxSpeed());
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||				KINEMATIC ARRIVE                 |||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||

KinematicArrive::KinematicArrive(float maxSpeed,
								 const Location* target,
								 float timeToTarget,
								 float radius)
	: TargetedKinematicMovement(maxSpeed,
								target),
	m_timeToTarget(timeToTarget),
	m_radius(radius)
{ }

void KinematicArrive::GiveSteering(SteeringOutput* output,
								   TransformableLocation* character) const
{
	output->isKinematic = true;

	// First work out the direction
	output->linear = TargetedKinematicMovement::getTargetPosition();
	output->linear -= character->GetPosition();

	// If there is no direction, do nothing
	if (output->linear.SquareLength() < m_radius * m_radius)
	{
		output->linear.Clear();
	}
	else
	{
		// We'd like to arrive in timeToTarget seconds
		output->linear *= (1.0f / m_timeToTarget);

		// If that is too fast, then clip the speed
		KinematicHelper::ClipToMax_CheckMax(&output->linear,
											KinematicSteering::GetMaxSpeed());
	}
}

void KinematicArrive::SetTimeToTarget(float timeToTarget)
{
	m_timeToTarget = timeToTarget;
}

void KinematicArrive::SetRadius(float radius)
{
	m_radius = radius;
}

float KinematicArrive::GetTimeToTarget() const
{
	return m_timeToTarget;
}

float KinematicArrive::GetRadius() const
{
	return m_radius;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||				KINEMATIC WANDER                 |||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||

KinematicWander::KinematicWander(float maxSpeed,
								 float maxRotation,
								 float maxOffsetChange)
	: KinematicSteering(maxSpeed),
	m_maxRotation(maxRotation),
	m_maxOffsetChange(maxOffsetChange)
{ }

void KinematicWander::GiveSteering(SteeringOutput* output,
								   TransformableLocation* character) const
{
	output->isKinematic = true;

	// Move forward in the current direction
	output->linear = character->GetOrientationAsVector();
	output->linear *= KinematicSteering::GetMaxSpeed();

	// Turn a little
	float change = MathHelper::RandomBinomial(m_maxOffsetChange);
	output->angular = change * m_maxRotation;
}

void KinematicWander::SetMaxRotation(float maxRotation)
{
	m_maxRotation = maxRotation;
}

float KinematicWander::GetMaxRotation() const
{
	return m_maxRotation;
}