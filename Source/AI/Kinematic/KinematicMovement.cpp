#include "AI/Kinematic/KinematicSteering.hpp"

KinematicMovement::KinematicMovement(TransformableLocation* character, float maxSpeed)
	: m_character(character),
	m_maxSpeed(maxSpeed)
{
	// nothing
}

void KinematicMovement::SetLocationCharacter(TransformableLocation* character)
{
	m_character = character;
}

void KinematicMovement::SetMaxSpeed(float maxSpeed)
{
	m_maxSpeed = maxSpeed;
}

TransformableLocation* KinematicMovement::GetCharacterLocation()
{
	return m_character;
}

const TransformableLocation* KinematicMovement::GetCharacterLocation() const
{
	return m_character;
}

Vec2 KinematicMovement::GetCharacterPosition() const
{
	return m_character->GetPosition();
}

float KinematicMovement::GetMaxSpeed() const
{
	return m_maxSpeed;
}