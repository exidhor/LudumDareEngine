#include "Component/AIComponent.hpp"
#include "Component/GameObject.hpp"

AIComponent::AIComponent(sf::Transformable* transformable)
	: m_kinematic(transformable),
	m_steering(nullptr),
	m_parent(nullptr)
{
	// nothing
}

void AIComponent::Init(GameObject* parent)
{
	m_parent = parent;

	m_kinematic.Init(m_parent->GetTransformable());

	m_steering = nullptr;
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

const Location* AIComponent::GetLocation() const
{
	return &m_kinematic;
}

const Kinematic* AIComponent::GetKinematic() const
{
	return &m_kinematic;
}