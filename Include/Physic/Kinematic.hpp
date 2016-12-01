#pragma once
#include <SFML/Graphics.hpp>
#include "Physic/KinematicSteeringOutput.hpp"

#define PI 3.14159265

class Kinematic
{
public :
	Kinematic(sf::Transformable* transformable);

	void Update(KinematicSteeringOutput const& steering, 
				float time);

	void GetNewOrientation();

private :

	float getOrientationInRadiant() const;
	void setOrientation(float angleInRadiant);
	void rotate(float angleInRadiant);

	KinematicSteeringOutput m_steering;
	sf::Transformable* m_transformable;
};
