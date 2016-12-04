#include "AI/Kinematic/KinematicAlign.hpp"

Align::Align(float maxSpeed,
			 const Location* target,
			 float maxAngularAcceleration,
			 float maxRotation,
			 float targetRadius,
			 float slowRadius,
			 float timeToTarget)
	: TargetedKinematicSteering(maxSpeed, target),
	m_maxAngularAcceleration(maxAngularAcceleration),
	m_maxRotation(maxRotation),
	m_targetRadius(targetRadius),
	m_slowRadius(slowRadius),
	m_timeToTarget(timeToTarget)
{
	// nothing
}

void Align::GiveSteering(SteeringOutput* output,
						  Kinematic* character)
{
	float rotation = TargetedKinematicSteering::GetTargetOrientation();
	rotation -= character->GetOrientation();

	// todo
}

void Align::SetMaxAngularAcceleration(float maxAngularAcceleration)
{
	m_maxAngularAcceleration = maxAngularAcceleration;
}

void Align::SetMaxRotation(float maxRotation)
{
	m_maxRotation = maxRotation;
}

void Align::SetTargetRadius(float targetRadius)
{
	m_targetRadius = targetRadius;
}

void Align::SetSlowRadius(float slowRadius)
{
	m_slowRadius = slowRadius;
}

void Align::SetTimeToTarget(float timeToTarget)
{
	m_timeToTarget = timeToTarget;
}

float Align::GetMaxAngularAcceleration() const
{
	return m_maxAngularAcceleration;
}

float Align::GetMaxRotation() const
{
	return m_maxRotation;
}

float Align::GetTargetRadius() const
{
	return m_targetRadius;
}

float Align::GetSlowRadius() const
{
	return m_slowRadius;
}

float Align::GetTimeToTarget() const
{
	return m_timeToTarget;
}