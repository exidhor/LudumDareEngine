#pragma once
#include <SFML/Graphics.hpp>
#include "AI/SteeringOutput.hpp" 
#include "Physic/Vec2.hpp"
#include "Physic/Location/TransformableLocation.hpp"

/**
 * \class Kinematic
 * \brief Handle an Object in time, with his
 *		  Location, orientation, velocity and rotation	
 */
class Kinematic : public TransformableLocation
{
public :
	
	/**
	* \brief 	Construct a void Kinematic
	* \param	transformable : used to create
	*			the location of the Kinematic
	* \warning	The Transformable can be NULL
	*/
	Kinematic(sf::Transformable* transformable = nullptr);
	
	/**
	* \brief 	Init the Kinematic with the Transformable
	* \param	transformable : used to create
	*			the location of the Kinematic
	*/
	void Init(sf::Transformable* transformable);

	/**
	 * \brief	Update the Kinematic by integrating the
	 *			velocity and the rotation into the Location
	 * \param	time : The time elapsed in seconds
	 */
	void Update(float time);

	/**
	 * \brief	Update the Kinematic with the steering
	 * \param	time : The time elapsed in seconds
	 * \param	steering : the steering to use
	 */
	void Update(float time,
				SteeringOutput const& steering);

	/**
	 * \brief	Set the orientation from the velocity.
	 *			It forces the object to face the direction.
	 * \param	velocity : The velocity to use 
	 */
	void GetNewOrientation(Vec2 const& velocity);

	/**
	 * \brief	Return the velocity
	 * \return	The velocity
	 */
	Vec2 const& GetVelocity() const;

private :
	Vec2 m_velocity;
	float m_rotation;
};
