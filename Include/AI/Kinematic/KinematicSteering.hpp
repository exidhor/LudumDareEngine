#pragma once
#include "AI/SteeringOutput.hpp"
#include "AI/Kinematic/Kinematic.hpp"
#include "Physic/Vec2.hpp"

class KinematicMovement
{
public :
	KinematicMovement(TransformableLocation* character, float maxSpeed);

	virtual void GiveSteering(SteeringOutput* output) const = 0;

	void SetLocationCharacter(TransformableLocation* character);
	void SetMaxSpeed(float maxSpeed);

	TransformableLocation* GetCharacterLocation();
	const TransformableLocation* GetCharacterLocation() const;

	Vec2 GetCharacterPosition() const;

	float GetMaxSpeed() const;


private :
	TransformableLocation* m_character;
	float m_maxSpeed;
};
