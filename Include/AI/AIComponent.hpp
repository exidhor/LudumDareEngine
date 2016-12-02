#pragma once
#include "AI/Kinematic/Kinematic.hpp"
#include "Kinematic/KinematicSteering.hpp"

class AIComponent
{
public :
	AIComponent(sf::Transformable* transformable);

	void Update(float time);

	void SetKinematicSteering(KinematicMovement* steering);

	Location* GetLocation();

private :
	Kinematic m_kinematic;
	KinematicMovement * m_steering;
	SteeringOutput m_cache;
};
