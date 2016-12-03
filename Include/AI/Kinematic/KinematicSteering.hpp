#pragma once
#include "AI/SteeringOutput.hpp"
#include "AI/Kinematic/Kinematic.hpp"
#include "Physic/Vec2.hpp"

class KinematicSteering
{
public :

	KinematicSteering(float maxSpeed);

	virtual void GiveSteering(SteeringOutput* output,
	                          Kinematic* character) = 0;

	void SetMaxSpeed(float maxSpeed);
	float GetMaxSpeed() const;

private :
	float m_maxSpeed;
};
