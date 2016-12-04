#pragma once
#include "AI/Kinematic/Kinematic.hpp"
#include "AI/Kinematic/KinematicSteering.hpp"

class GameObject; // todo doc

class AIComponent
{
public :
	AIComponent(sf::Transformable* transformable = nullptr);

	void Init(GameObject* parent);

	void SetKinematicSteering(KinematicSteering* steering);

	void Update(float time);

	const Location* GetLocation() const;
	const Kinematic* GetKinematic() const;

private :
	Kinematic m_kinematic;
	KinematicSteering* m_steering;

	GameObject* m_parent;
};
