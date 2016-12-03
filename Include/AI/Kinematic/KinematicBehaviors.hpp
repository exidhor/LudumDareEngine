#pragma once
#include "AI/Kinematic/TargetedKinematicMovement.hpp"
#include "AI/MathHelper.hpp"
#include "Physic/Vec2.hpp"

namespace KinematicHelper
{
	void ClipToMax_CheckZero(Vec2 * linear, float maxSpeed);

	void ClipToMax_CheckMax(Vec2 * linear, float maxSpeed);
}


/**
* Kinematic seek moves at full speed towards its target at each
* frame.
*/
class KinematicSeek : public TargetedKinematicMovement
{
public :
	/**
	* Works out the desired steering and writes it into the given
	* steering output structure.
	*/
	KinematicSeek(float maxSpeed,
				  const Location* target);

	virtual void GiveSteering(SteeringOutput* output,
							  TransformableLocation* character) const;
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
							  TransformableLocation* character) const;
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
					float radius);

	/**
	* Works out the desired steering and writes it into the given
	* steering output structure.
	*/
	virtual void GiveSteering(SteeringOutput* output,
							  TransformableLocation* character) const;

	void SetTimeToTarget(float timeToTarget);
	void SetRadius(float radius);

	float GetTimeToTarget() const;
	float GetRadius() const;

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
	float m_radius;
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
							  TransformableLocation* character) const;

	void SetMaxRotation(float maxRotation);
	float GetMaxRotation() const;

private:
	/**
	* The maximum rate at which the character can turn.
	*/
	float m_maxRotation;

	float m_maxOffsetChange;
};