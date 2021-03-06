#include "AI/Kinematic/KinematicBehaviors.hpp"

void KinematicHelper::ClipToMax_CheckZero(Vec2 * direction, float maxSpeed)
{
	// If there is no direction, do nothing
	if (direction->SquareLength() > 0)
	{
		direction->Normalise();
		(*direction) *= maxSpeed;
	}
}

void KinematicHelper::ClipToMax_CheckMax(Vec2 * direction, float maxSpeed)
{
	// If that is too fast, then clip the speed
	if (direction->SquareLength() > maxSpeed * maxSpeed)
	{
		direction->Normalise();
		(*direction) *= maxSpeed;
	}
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||				KINEMATIC SEEK                   |||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||

KinematicSeek::KinematicSeek(float maxSpeed,
							 const Location* target)
	: TargetedKinematicSteering(maxSpeed, target)
{ }

void KinematicSeek::GiveSteering(SteeringOutput* output,
                                 Kinematic* character)
{
	output->isKinematic = true;

	// First work out the direction
	output->linear = TargetedKinematicSteering::GetTargetPosition();
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
                                 Kinematic* character)
{
	output->isKinematic = true;

	// First work out the direction
	output->linear = character->GetPosition();
	output->linear -= TargetedKinematicSteering::GetTargetPosition();

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
								 float targetRadius,
								 float slowRadius)
	: TargetedKinematicSteering(maxSpeed,
								target),
	m_timeToTarget(timeToTarget),
	m_targetRadius(targetRadius),
	m_slowRadius(slowRadius)

{ }

void KinematicArrive::GiveSteering(SteeringOutput* output,
                                   Kinematic* character)
{
	output->isKinematic = true;

	// First work out the direction
	output->linear = TargetedKinematicSteering::GetTargetPosition();
	output->linear -= character->GetPosition();

	float squareDistance = output->linear.SquareLength();

	// If there is no direction, do nothing
	if (squareDistance < m_targetRadius * m_targetRadius)
	{
		output->linear.Clear();
	}
	else
	{
		output->linear.Normalise();
		output->linear *= KinematicSteering::GetMaxSpeed();

		// if we are outside the slowRadius, then go maxSpeed (and no changement)
		// Otherwise calculate a scaled speed
		if(squareDistance < m_slowRadius * m_slowRadius)
		{
			output->linear *= sqrt(squareDistance) / m_slowRadius;
		}

		// Acceleration tries to get to the target velocity
		output->linear -= character->GetVelocity();
		output->linear /= m_timeToTarget;

		// If that is too fast, then clip the speed
		KinematicHelper::ClipToMax_CheckMax(&output->linear,
											KinematicSteering::GetMaxSpeed());
	}
}

void KinematicArrive::SetTimeToTarget(float timeToTarget)
{
	m_timeToTarget = timeToTarget;
}

void KinematicArrive::SetTargetRadius(float targetRadius)
{
	m_targetRadius = targetRadius;
}

void KinematicArrive::SetSlowRadius(float slowRadius)
{
	m_slowRadius = slowRadius;
}

float KinematicArrive::GetTimeToTarget() const
{
	return m_timeToTarget;
}

float KinematicArrive::GetTargetRadius() const
{
	return m_targetRadius;
}

float KinematicArrive::GetSlowRadius() const
{
	return m_slowRadius;
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
                                   Kinematic* character)
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