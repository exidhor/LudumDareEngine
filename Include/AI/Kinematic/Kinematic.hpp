#pragma once
#include <SFML/Graphics.hpp>
#include "AI/SteeringOutput.hpp" 
#include "Physic/Vec2.hpp"
#include "Physic/Location/TransformableLocation.hpp"

/// \class	Kinematic
/// \brief	Handle an Object in time, with his
///			Location, orientation, velocity and rotation
class Kinematic : public TransformableLocation
{
public :
	
	/// \brief	Construct a void Kinematic
	/// \param	transformable : used to create
	///			the location of the Kinematic
	/// \warning The Transformable can be NULL
	Kinematic(sf::Transformable* transformable = nullptr);
	
	/// \brief 
	/// \param transformable 
	void Init(sf::Transformable* transformable);

	void Update(float time);

	void Update(float time,
				SteeringOutput const& steering);

	void GetNewOrientation(Vec2 const& velocity);

	Vec2 const& GetVelocity() const;

private :
	Vec2 m_velocity;
	float m_rotation;
};
