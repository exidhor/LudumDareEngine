#pragma once
#include "Physic/Vec2.hpp"

/*
 * \class SteeringOutput
 * \brief The output use to set a Kinematic.
 *		  It can be Kinematic or not.
 *		  If it's Kinematic, it means that the linear is the velocity
 *		  and the angular is the rotation
 */
class SteeringOutput
{
public :
	Vec2 linear;
	float angular;
	bool isKinematic;

	/**
	 * \brief	Construct a void SteeringOutput with default value (everything a zero)
	 *			By default, a steering output is not kinematic
	 */
	SteeringOutput();

	/**
	 * \brief   Construct a SteeringOutput
	 * \param	linear : The linear value for the integration for the position
	 * \param	angular : the angular value for the integration for the orientation 
	 * \param	isKinematic : If the output is design for kinematic or not
	 */
	SteeringOutput(Vec2 const& linear, float angular, bool isKinematic = false);
};

