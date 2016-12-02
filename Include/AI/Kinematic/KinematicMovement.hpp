#pragma
#include "AI/SteeringOutput.hpp"
#include "AI/Kinematic/Kinematic.hpp"


class KinematicMovement
{
public :
	KinematicMovement(Location* character, float maxSpeed);

	virtual void GiveSteering(SteeringOutput* output) const = 0;

	void SetLocationCharacter(Location* character);
	void SetMaxSpeed(float maxSpeed);

	Location* GetCharacterLocation();
	const Location* GetCharacterLocation() const;

	Vec2 GetCharacterPosition() const;

	float GetMaxSpeed() const;


private :
	Location* m_character;
	float m_maxSpeed;
};
