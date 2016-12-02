#include "AI/AIComponent.hpp"

AIComponent::AIComponent(sf::Transformable* transformable)
	: m_kinematic(transformable),
	m_steering(nullptr)
{
	// nothing
}

void AIComponent::Update(float time)
{
	if(m_steering != nullptr)
	{
		m_steering->GiveSteering(&m_cache);

		m_kinematic.Update(time, m_cache);
	}
	else
	{
		m_kinematic.Update(time);
	}
}

void AIComponent::SetKinematicSteering(KinematicMovement* steering)
{
	m_steering = steering;
}

Location* AIComponent::GetLocation()
{
	return &m_kinematic;
}