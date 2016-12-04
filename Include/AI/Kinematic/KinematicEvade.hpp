#pragma once
#include "AI/Kinematic/KinematicBehaviors.hpp"
#include "Physic/Location/StationaryLocation.hpp"

/**
* \class KinematicEvade
* \brief Kinematic behavior which try to go out (evade)
*		  a target with the shortest path, calculating
*		  by predicated the target deplacement
*/
class KinematicEvade : public KinematicFlee
{
public:

	/**
	* \brief	Construct the KinematicEvade
	* \param	maxSpeed : The maximum speed of the object
	* \param	target : The target to flee
	* \param	maxPredictionTime : The maximum time to predicate
	*			the target deplacement
	*/
	KinematicEvade(float maxSpeed,
				   const Kinematic* target,
				   float maxPredictionTime);

	/**
	* \brief	Set the value of the Steering output to represent the behavior.
	* \param	output : the output to set
	* \param	character : the character which earn the behavior
	*/
	virtual void GiveSteering(SteeringOutput* output,
							  Kinematic* character);

	/**
	* \brief	Set the Target to evade
	* \param	target : the target to evade (we need a Kinematic because we need
	*			to access to the velocity of the target)
	*/
	void SetEvadeTarget(const Kinematic* target);

	/**
	* \brief	Set the maximum time to predicate
	* \param	maxPredictionTime : the maximum duration to predicate
	*/
	void SetMaxPredictionTime(float maxPredictionTime);

private:
	const Kinematic* m_evadeTarget;
	StationaryLocation m_fleeLocation; // used for Flee call
	float m_maxPredictionTime;
};
