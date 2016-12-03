#pragma once
#include "AI/Kinematic/KinematicBehaviors.hpp"
#include "Physic/Location/StationaryLocation.hpp"

class KinematicPursue : public KinematicSeek
{
public :
	KinematicPursue(float maxSpeed,
					const Kinematic* target,
					float maxPredictionTime);

	virtual void GiveSteering(SteeringOutput* output,
							  Kinematic* character);

	void SetPursueTarget(const Kinematic* target);
	void SetMaxPredictionTime(float maxPredictionTime);

private :
	const Kinematic* m_pursueTarget;
	StationaryLocation m_seekLocation; // used for Seek call
	float m_maxPredictionTime;
};
