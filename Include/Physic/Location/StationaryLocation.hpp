#pragma once
#include "Location.hpp"

class StationaryLocation : public Location
{
public :
	StationaryLocation();

	StationaryLocation(Vec2 const& position, float orientation = 0.0f);

	void SetPosition(Vec2 const& newPosition);
	void SetOrientation(float newOrientation);

	Vec2 GetPosition() const override;
	float GetOrientation() const override;

private :
	Vec2 m_position;
	float m_orientation;
};
