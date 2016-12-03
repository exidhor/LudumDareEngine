#pragma once
#include "AI/Kinematic/TargetedKinematicSteering.hpp"
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
* \class KinematicSeek
* \brief Kinematic seek moves at full speed towards its target at each
*		 frame.
*/
class KinematicSeek : public TargetedKinematicSteering
{
public :
	/**
	* \brief	Construct the behavior Seek
	* \param	maxSpeed : the maximum speed to go toward the seek target
	* \param	target : The position of the target (it's a Location because
	*			the target can move)
	*/
	KinematicSeek(float maxSpeed,
				  const Location* target);

	/**
	 * \brief	Set the value of the Steering output to represent the behavior.
	 * \param	output : the output to set 
	 * \param	character : the character which earn the behavior
	 */
	virtual void GiveSteering(SteeringOutput* output,
	                          Kinematic* character);
};


/**
* \class Flee
* \brief Flee seeks to maximise the distance from the target.
*/
class KinematicFlee : public KinematicSeek
{
public:

	/**
	* \brief	Construct the behavior Flee
	* \param	maxSpeed : the maximum speed to go to the opposite side of the target
	* \param	target : The position of the target (it's a Location because
	*			the target can move)
	*/
	KinematicFlee(float maxSpeed,
				  const Location* target);

	/**
	* \brief	Set the value of the Steering output to represent the behavior.
	* \param	output : the output to set
	* \param	character : the character which earn the behavior
	*/
	virtual void GiveSteering(SteeringOutput* output,
	                          Kinematic* character);
};


/**
* \class KinematicArrive
* \brief Kinematic arrive behaves just like seek unless it is close to
*		 the target, in which case it moves slower and eventually stops.
*/
class KinematicArrive : public TargetedKinematicSteering
{
public:

	/**
	* \brief	Construct the behavior KinematicArrive
	* \param	maxSpeed : the maximum speed to go to the target when possible
	* \param	target : The position of the target (it's a Location because
	*			the target can move)
	* \param	timeToTarget : The minimum time the object have to rejoin the target
	* \param	targetRadius : The radius in which the object consider it arrive
	* \param	slowRadius : The radius from which the object start to slow down to arrive
	*/
	KinematicArrive(float maxSpeed,
					const Location* target,
					float timeToTarget,
					float targetRadius,
					float slowRadius);

	/**
	* \brief	Set the value of the Steering output to represent the behavior.
	* \param	output : the output to set
	* \param	character : the character which earn the behavior
	*/
	virtual void GiveSteering(SteeringOutput* output,
	                          Kinematic* character);

	/**
	 * \brief Set the minimum time the object have to rejoin the target.
	 * \param timeToTarget : the minimum time the object have to rejoin the target.
	 */
	void SetTimeToTarget(float timeToTarget);
	/**
	 * \brief Set the radius in which the object consider it arrive
	 * \param targetRadius : The radius in which the object consider it arrive
	 */
	void SetTargetRadius(float targetRadius);

	/**
	 * \brief Set the radius from which the object start to slow down to arrive
	 * \param slowRadius : The radius from which the object start to slow down to arrive
	 */
	void SetSlowRadius(float slowRadius);

	/**
	 * \brief Return the minimum time the object have to rejoin the target.
	 * \return the minimum time the object have to rejoin the target.
	 */
	float GetTimeToTarget() const;
	
	/**
	* \brief Return the radius in which the object consider it arrive
	* \return The radius in which the object consider it arrive
	*/
	float GetTargetRadius() const;
	
	/**
	* \brief Return the radius from which the object start to slow down to arrive
	* \return The radius from which the object start to slow down to arrive
	*/
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
* \class KinematicWander
* \brief Wander changes the orientation by a random amount then moves
*		 the character forwards.
*/
class KinematicWander : public KinematicSteering
{
public:

	/**
	 * \brief Construct the behavior KinematicWander
	 * \param maxSpeed : The maximum speed to use when wandering
	 * \param maxRotation : The maximum rotation to move
	 * \param maxOffsetChange : The maximum offset during orientation changement
	 */
	KinematicWander(float maxSpeed,
					float maxRotation,
					float maxOffsetChange = 0.2f);

	/**
	* \brief	Set the value of the Steering output to represent the behavior.
	* \param	output : the output to set
	* \param	character : the character which earn the behavior
	*/
	virtual void GiveSteering(SteeringOutput* output,
	                          Kinematic* character);


	/**
	 * \brief Set the maximum rotation to move
	 * \param maxRotation : The maximum rotation to move
	 */
	void SetMaxRotation(float maxRotation);

	/**
	* \brief Return the maximum rotation to move
	* \return The maximum rotation to move
	*/
	float GetMaxRotation() const;

private:
	/**
	* The maximum rate at which the character can turn.
	*/
	float m_maxRotation;

	float m_maxOffsetChange;
};