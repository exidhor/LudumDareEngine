#include "AI/Kinematic/KinematicMovement.hpp"

KinematicMovement::KinematicMovement(Location* character, float maxSpeed)
	: m_character(character),
	m_maxSpeed(maxSpeed)
{
	// nothing
}

void KinematicMovement::SetLocationCharacter(Location* character)
{
	m_character = character;
}

void KinematicMovement::SetMaxSpeed(float maxSpeed)
{
	m_maxSpeed = maxSpeed;
}

Location* KinematicMovement::GetCharacterLocation()
{
	return m_character;
}

const Location* KinematicMovement::GetCharacterLocation() const
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