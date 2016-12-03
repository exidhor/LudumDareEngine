#pragma once
#include "AI/Kinematic/KinematicSteering.hpp"
#include "Physic/Location/Location.hpp"
#include "Physic/Vec2.hpp"

/**
 * \class TargetedKinematicSteering
 * \brief A Steering which have a target 
 */
class TargetedKinematicSteering : public KinematicSteering
{
public :

	/**
	 * \brief Construct a Targeted Steering
	 * \param maxSpeed : the maximum speed of the object
	 * \param target : The target
	 */
	TargetedKinematicSteering(float maxSpeed,
							  const Location* target);

	/**
	 * \brief Return the target
	 * \return the target position
	 */
	Vec2 GetTargetPosition() const;

	/**
	 * \brief Set the Target location
	 * \param target : the target location
	 */
	void SetTargetLocation(const Location * target);

private:
	const Location* m_target;
};
