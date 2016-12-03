#pragma once
#include "AI/SteeringOutput.hpp"
#include "AI/Kinematic/Kinematic.hpp"
#include "Physic/Vec2.hpp"

/**
 * \class KinematicSteering
 * \brief It means that he almost always uses the max speed
 *		   to move, and dont care about the physic laws
 */
class KinematicSteering
{
public :

	/**
	 * \brief  Construct the Steering and set the maximum speed
	 * \param maxSpeed : the maximum speed of the object
	 */
	KinematicSteering(float maxSpeed);

	/**
	* \brief	Set the value of the Steering output to represent the behavior.
	* \param	output : the output to set
	* \param	character : the character which earn the behavior
	*/
	virtual void GiveSteering(SteeringOutput* output,
	                          Kinematic* character) = 0;

	/**
	 * \brief	Set the maximum speed
	 * \param	maxSpeed : the maximum speed 
	 */
	void SetMaxSpeed(float maxSpeed);
	
	/**
	 * \brief	Return the maximum speed
	 * \return	The maximum speed
	 */
	float GetMaxSpeed() const;

private :
	float m_maxSpeed;
};
