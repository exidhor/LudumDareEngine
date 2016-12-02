#pragma once
#include "Location.hpp"

class StationaryLocation : public Location
{
public :
	StationaryLocation();

	StationaryLocation(Vec2 const& position, float orientation = 0.0f);

	virtual Vec2 GetPosition() const;
	virtual float GetOrientation() const;

private :
	Vec2 m_position;
	float m_orientation;
};
