#pragma once
#include "AI/Kinematic/KinematicBehaviors.hpp"
#include "Physic/Location/StationaryLocation.hpp"

/**
 * \class KinematicPursue
 * \brief Kinematic behavior which try to rejoin
 *		  a target with the shortest path, calculating
 *		  by predicated the target deplacement
 */
class KinematicPursue : public KinematicSeek
{
public :

	/**
	 * \brief	Construct the KinematicPursue
	 * \param	maxSpeed : The maximum speed of the object
	 * \param	target : The target to rejoin
	 * \param	maxPredictionTime : The maximum time to predicate
	 *			the target deplacement
	 */
	KinematicPursue(float maxSpeed,
					const Kinematic* target,
					float maxPredictionTime);

	/**
	* \brief	Set the value of the Steering output to represent the behavior.
	* \param	output : the output to set
	* \param	character : the character which earn the behavior
	*/
	virtual void GiveSteering(SteeringOutput* output,
							  Kinematic* character);

	
	void SetPursueTarget(const Kinematic* target);
	
	
	void SetMaxPredictionTime(float maxPredictionTime);

private :
	const Kinematic* m_pursueTarget;
	StationaryLocation m_seekLocation; // used for Seek call
	float m_maxPredictionTime;
};
