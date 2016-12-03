#pragma once
#include "AI/Kinematic/Kinematic.hpp"
#include "Kinematic/KinematicSteering.hpp"

class AIComponent
{
public :
	AIComponent(sf::Transformable* transformable);

	void SetKinematicSteering(KinematicSteering* steering);

	void Update(float time);

	Location* GetLocation();

private :
	Kinematic m_kinematic;
	KinematicSteering* m_steering;
};
