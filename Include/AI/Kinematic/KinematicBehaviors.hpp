#pragma once
#include "AI/Kinematic/TargetedKinematicMovement.hpp"
#include "AI/MathHelper.hpp"
#include "Physic/Vec2.hpp"


namespace KinematicHelper
{
	/**
	 * \brief	Clip the linear vector to the maxSpeed direction
	 *			It only checks if the linear length is zero
	 * \param	direction : the linear to clip 
	 * \param	maxSpeed : the maxSpeed of the object
	 */
	void ClipToMax_CheckZero(Vec2 * direction, float maxSpeed);

	/**
	* \brief	Clip the linear vector to the maxSpeed direction
	*			It only checks if the linear is upper than the max
	* \param	direction : the linear to clip
	* \param	maxSpeed : the maxSpeed of the object
	*/
	void ClipToMax_CheckMax(Vec2 * direction, float maxSpeed);
}


/**
* Kinematic seek moves at full speed towards its target at each
* frame.
*/
class KinematicSeek : public TargetedKinematicMovement
{
public :
	/**
	* \brief	Works out the desired steering and writes it into the given
	*			steering output structure.
	* \param	maxSpeed : the maximum speed to go toward the seek target
	* \param	target : The position of the target (it's a Location because
	*			the target can move)
	*/
	KinematicSeek(float maxSpeed,
				  const Location* target);

	/**
	 * \brief	// todo 
	 * \param output : 
	 * \param character : 
	 */
	virtual void GiveSteering(SteeringOutput* output,
	                          Kinematic* character);
};


/**
* Flee seeks to maximise the distance from the target.
*/
class KinematicFlee : public KinematicSeek
{
public:
	/**
	* Works out the desired steering and writes it into the given
	* steering output structure.
	*/
	KinematicFlee(float maxSpeed,
				  const Location* target);

	/**
	* Works out the desired steering and writes it into the given
	* steering output structure.
	*/
	virtual void GiveSteering(SteeringOutput* output,
	                          Kinematic* character);
};


/**
* Kinematic arrive behaves just like seek unless it is close to
* the target, in which case it moves slower and eventually stops.
*/
class KinematicArrive : public TargetedKinematicMovement
{
public:
	KinematicArrive(float maxSpeed,
					const Location* target,
					float timeToTarget,
					float targetRadius,
					float slowRadius);

	/**
	* Works out the desired steering and writes it into the given
	* steering output structure.
	*/
	virtual void GiveSteering(SteeringOutput* output,
	                          Kinematic* character);

	void SetTimeToTarget(float timeToTarget);
	void SetTargetRadius(float targetRadius);
	void SetSlowRadius(float slowRadius);

	float GetTimeToTarget() const;
	float GetTargetRadius() const;
	float GetSlowRadius() const;

private:
	/**
	* At each step the character tries to reach its target in
	* this duration. This means it moves more slowly when nearby.
	*/
	float m_timeToTarget;

	/**
	* If the character is closer than this to the target, it will
	* not attempt to move.
	*/
	float m_targetRadius;

	float m_slowRadius;
};

/**
* Wander changes the orientation by a random amount then moves
* the character forwards.
*/
class KinematicWander : public KinematicSteering
{
public:
	KinematicWander(float maxSpeed,
					float maxRotation,
					float maxOffsetChange = 0.2f);

	/**
	* Works out the desired steering and writes it into the given
	* steering output structure.
	*/
	virtual void GiveSteering(SteeringOutput* output,
	                          Kinematic* character);

	void SetMaxRotation(float maxRotation);
	float GetMaxRotation() const;

private:
	/**
	* The maximum rate at which the character can turn.
	*/
	float m_maxRotation;

	float m_maxOffsetChange;
};