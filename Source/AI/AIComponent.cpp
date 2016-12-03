#include "AI/AIComponent.hpp"

AIComponent::AIComponent(sf::Transformable* transformable)
	: m_kinematic(transformable),
	m_steering(nullptr)
{
	// nothing
}

void AIComponent::SetKinematicSteering(KinematicSteering* steering)
{
	m_steering = steering;
}

void AIComponent::Update(float time)
{
	SteeringOutput output;

	if(m_steering)
	{
		m_steering->GiveSteering(&output, &m_kinematic);
	}

	m_kinematic.Update(time, output);
}

Location* AIComponent::GetLocation()
{
	return &m_kinematic;
}