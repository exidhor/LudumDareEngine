#pragma once
#include "AI/Kinematic/TargetedKinematicSteering.hpp"

class Align : public TargetedKinematicSteering
{
public :
	Align(float maxSpeed,
		  const Location* target,
		  float maxAngularAcceleration,
		  float maxRotation,
		  float targetRadius,
		  float slowRadius,
		  float timeToTarget);

	/**
	* \brief	Set the value of the Steering output to represent the behavior.
	* \param	output : the output to set
	* \param	character : the character which earn the behavior
	*/
	virtual void GiveSteering(SteeringOutput* output,
							  Kinematic* character);

	void SetMaxAngularAcceleration(float maxAngularAcceleration);

	void SetMaxRotation(float maxRotation);

	void SetTargetRadius(float targetRadius);

	void SetSlowRadius(float slowRadius);

	void SetTimeToTarget(float timeToTarget);

	float GetMaxAngularAcceleration() const;

	float GetMaxRotation() const;

	float GetTargetRadius() const;

	float GetSlowRadius() const;

	float GetTimeToTarget() const;

private :
	float m_maxAngularAcceleration;
	float m_maxRotation;
	float m_targetRadius;
	float m_slowRadius;
	float m_timeToTarget;
};

class Face
{
	
};